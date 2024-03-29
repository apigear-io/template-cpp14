#pragma once
#pragma warning (disable: 4251) 
#pragma warning (disable: 4099) 


#include "Poco/Net/ServerSocket.h"
#include "Poco/Net/HTTPServer.h"
#include <iostream>
#include <memory>
#include <vector>
#include <mutex>
#include <functional>
#include <chrono>

#include "tests/private/frame.hpp"
#include "tests/private/test_server/iframestorage.hpp"
#include "tests/private/test_server/test_server_request_factory.hpp"

namespace tests
{
// Test server
// Allows to inspect all the received frames from a client getReceivedFrames.
// Sends a frame to a client on demand with a sendFrame function.
// To keep server simple it is written for one client.
class TestServer : public IFrameStorage
{
public:
	// The POCO server takes ownership of request handler factory.
	TestServer(int port)
		: server(new TestServerRequestHandlerFactory(*this), port)
	{}

	void start()
	{
		server.start();
		Poco::Thread::sleep(100);
	}
	void stop()
	{
		Poco::Thread::sleep(100);
		server.stop();
	}

	virtual~TestServer()
	{
		stop();
	}

	// Use this function to send a message form a server to your client.
	void sendFrame(const std::string& payload, int flags = Poco::Net::WebSocket::FRAME_TEXT)
	{
		if (m_requestSend)
		{
			m_requestSend({ payload, flags });
		}
		else
		{
			std::cout << "Test Server cannot send frame. Socket owner(RequestHandler) didn't provide the send Frame function, check if the connection was established." << std::endl;
		}
	}

	// Get all the frames received by server since last call of this function.
	// The frames are cleared from server storage with this call, the only copy is on user side.
	std::vector<Frame> getReceivedFrames()
	{
		// Client send frames with some delay, here delay is long enough to make sure all messages are delivered
		// also due to working in threads.
		Poco::Thread::sleep(50);
		std::vector<Frame> frames;
		std::unique_lock<std::timed_mutex> lock(receivedFramesMutex, std::defer_lock);
		if (lock.try_lock_for(std::chrono::milliseconds(100)))
		{
			std::swap(frames, receivedFrames);
			lock.unlock();
		}
		return frames;
	}

	// Implementation of IFrameStorage::storeFrame, 
	// used by socket owner.
	void storeFrame(const Frame& frame) override
	{
		std::unique_lock<std::timed_mutex> lock(receivedFramesMutex, std::defer_lock);
		if (lock.try_lock_for(std::chrono::milliseconds(100)))
		{
			receivedFrames.push_back(frame);
			lock.unlock();
		}
	}
	// Implementation of IFrameStorage::setRequestSendFunction, 
	// used by socket owner.
	void setRequestSendFunction(std::function<void(Frame)> requestSend) override
	{
		m_requestSend = requestSend;
	}

	// Function to send a frame from server. Provided by socket owner. 
	std::function <void(Frame)> m_requestSend;
	// Mutex for managing receivedFrames.
	std::timed_mutex receivedFramesMutex;
	// Storage for received frames.
	std::vector<Frame> receivedFrames;
	Poco::Net::HTTPServer server;
};

} //namespace tests
