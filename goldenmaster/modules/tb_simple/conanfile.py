from conans import ConanFile, CMake, tools
from pathlib import os

class tb_simpleConan(ConanFile):
    name = "tb_simple"
    version = "1.0"
    license = "GPL v3"
    author = "ApiGear UG"
    #url = "<Package recipe repository url here, for issues about the package>"
    settings = "os", "compiler", "build_type", "arch"
    requires = "catch2/2.13.7", "nlohmann_json/3.9.1", "apigear/0.1.0"
    generators = "cmake_find_package"
    exports_sources = "*"

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder=".")
        cmake.build()

    def package(self):
        packages = ["api", "core", "monitor", "olink"]
        self.copy("**/*.h", dst="include/generated", src="generated")
        self.copy("*.h", dst="include", src="implementation")
        self.copy("*.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.dylib*", dst="lib", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.env_info.path.append(os.path.join(self.package_folder, "bin"))
        self.cpp_info.components["tb_simple-api"].libs = ["tb_simple-api"]
        self.cpp_info.components["tb_simple-core"].libs = ["tb_simple-core"]
        self.cpp_info.components["tb_simple-core"].requires = ["tb_simple-api", "catch2::catch2", "nlohmann_json::nlohmann_json"]
        self.cpp_info.components["tb_simple-implementation"].libs = ["tb_simple-implementation"]
        self.cpp_info.components["tb_simple-implementation"].requires = ["tb_simple-core", "catch2::catch2", "nlohmann_json::nlohmann_json"]
        self.cpp_info.components["tb_simple-monitor"].libs = ["tb_simple-monitor"]
        self.cpp_info.components["tb_simple-monitor"].requires = ["tb_simple-core", "nlohmann_json::nlohmann_json", "apigear::poco-tracer"]
        self.cpp_info.components["tb_simple-olink"].libs = ["tb_simple-olink"]
        self.cpp_info.components["tb_simple-olink"].requires = ["tb_simple-core", "nlohmann_json::nlohmann_json", "apigear::poco-olink"]