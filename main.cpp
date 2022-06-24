#include <iostream>
#include <filesystem>
#include <vector>
#include <memory>


namespace fs = std::filesystem;

int main() {

    std::vector<std::string> nameFiles;

    auto outNameFiles = [&](fs::path path, const std::string& extension) {

        for (auto &it: fs::recursive_directory_iterator(path)) {

            if (!it.path().extension().compare(extension)) {

                nameFiles.emplace_back(it.path().string());
            }
        }

        return std::make_unique<std::vector<std::string>>(nameFiles);
    };

    const std::string extension = ".txt";
    auto OutNames = outNameFiles("C:\\NewFolder", extension);

    for (auto i : *OutNames)
    {
        std::cout << i << std::endl;
    }
}
