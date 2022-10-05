from conans import ConanFile, CMake, tools
from pathlib import os
from conan.tools.files import load, copy

class apigearConan(ConanFile):
    name = "apigear"
    version = "0.1.0"
    license = "Apache-2.0"
    author = "ApiGear UG"
    #url = "<Package recipe repository url here, for issues about the package>"
    settings = "os", "compiler", "build_type", "arch"
    requires = "catch2/2.13.7", "poco/1.11.3@#2f5e663a2d744e2d86962bfff2b2345e", "nlohmann_json/3.9.1"
    generators = "cmake_find_package", "virtualenv"
    default_options = {"poco:shared": False,
                       "poco:enable_data_mysql": False,
                       "openssl:shared": False,
                       "poco:enable_activerecord": False,
                       "poco:enable_apacheconnector": False,
                       "poco:enable_cppparser": False,
                       "poco:enable_crypto": True,
                       "poco:enable_data": False,
                       "poco:enable_data_odbc": False,
                       "poco:enable_data_postgresql": False,
                       "poco:enable_data_sqlite": False,
                       "poco:enable_encodings": False,
                       "poco:enable_json": False,
                       "poco:enable_jwt": False,
                       "poco:enable_mongodb": False,
                       "poco:enable_net": True,
                       "poco:enable_netssl": True,
                       "poco:enable_pagecompiler": False,
                       "poco:enable_pagecompiler_file2page": False,
                       "poco:enable_pdf": False,
                       "poco:enable_pocodoc": False,
                       "poco:enable_redis": False,
                       "poco:enable_sevenzip": False,
                       "poco:enable_util": True,
                       "poco:enable_xml": True,
                       "poco:enable_zip": False
                       }

    
    def layout(self):
        # Set root of the project to one level above, to keep proper folder structure
        self.folders.root = ".."
        # The source of the project is root/apigear (the folder that .py is)
        self.folders.source = "apigear"
        self.folders.build = "build/apigear"

    def export_sources(self):
        # The sources should be copied with apigear folder, so starting one level above
        folder = os.path.join(self.recipe_folder, "..")
        copy(self, "apigear/*", folder, self.export_sources_folder)

    def build(self):
        cmake = CMake(self)
        path = os.path.join(self.source_folder, "apigear")
        cmake.configure(source_folder=".")
        cmake.build()

    def configure(self):
        if self.settings.os == "Windows":
            self.options["openssl"].shared = True
            self.options["poco"].shared = False

    def package(self):
        packages = ["tracer", "olink"]
        self.copy("**/*.h", dst="include/apigear", src=".")
        self.copy("*.lib", dst="lib", src=".", keep_path=False)
        self.copy("*.dll", dst="bin", src=".", keep_path=False)
        self.copy("*.dylib*", dst="lib", src=".", keep_path=False)
        self.copy("*.so*", dst="lib", src=".", keep_path=False, symlinks=True)
        self.copy("*.a", dst="lib", src=".", keep_path=False)
        # manually copy objectlink-core-cpp include files, to have headers for module/generated/olink instead of linking whole library
        #self.copy(pattern="*.h", dst="include/olink", src="apigear/_deps/olink-core-src/src", keep_path=True)

    def package_info(self):
        self.env_info.path.append(os.path.join(self.package_folder, "bin"))
        self.cpp_info.components["poco-tracer"].libs = ["poco-tracer"]
        self.cpp_info.components["poco-tracer"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["poco-tracer"].requires = ["catch2::catch2", "poco::poco", "nlohmann_json::nlohmann_json"]
        self.cpp_info.components["poco-olink"].libs = ["poco-olink"]
        self.cpp_info.components["poco-olink"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["poco-olink"].requires = ["poco::poco", "nlohmann_json::nlohmann_json"]
