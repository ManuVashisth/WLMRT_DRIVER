#include <boost/filesystem.hpp>
#include <iostream>

namespace fs = boost::filesystem;

int main() {
    try {
        // Define the directory and file names
        fs::path dirName("/home/manu/Downloads");
        fs::path fileName = dirName / "example.txt";  // Combine directory and file name

        // Check if the directory exists, and create it if it doesn't
        if (!fs::exists(dirName)) {
            fs::create_directory(dirName);
            std::cout << "Directory created: " << dirName << std::endl;
        } else {
            std::cout << "Directory already exists: " << dirName << std::endl;
        }

        // Check if the file exists
        if (fs::exists(fileName)) {
            std::cout << "File size: " << fs::file_size(fileName) << " bytes" << std::endl;
            std::cout << "File path: " << fileName << std::endl;
            std::cout << "File is " << (fs::is_regular_file(fileName) ? "a file" : "not a file") << std::endl;
            std::cout << "File is " << (fs::is_directory(fileName) ? "a directory" : "not a directory") << std::endl;
        } else {
            std::cout << "File does not exist: " << fileName << std::endl;
        }

    } catch (const fs::filesystem_error& ex) {
        std::cerr << "An error occurred: " << ex.what() << std::endl;
    }

    return 0;
}
