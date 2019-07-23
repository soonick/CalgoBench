from conans import ConanFile, CMake, tools


class CalgoBenchConan(ConanFile):
    name = "CalgoBench"
    version = "0.2"
    generators = "cmake"
    license = "The Unlicense"
    author = "Adrian Ancona Novelo <soonick5@yahoo.com.mx>"
    url = "https://github.com/soonick/CalgoBench"
    description = "I created this library, so I could benchmark different solutions while solving algorithm and data structure questions"
    topics = ("benchmark")
    settings = "os", "compiler", "build_type", "arch"
    exports_sources = "src/*"

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder="src")
        cmake.build()

    def package(self):
        self.copy("*.h", dst="include", src="src")
        self.copy("*.tpp", dst="include", src="src")
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["CalgoBench"]
