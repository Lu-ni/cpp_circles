#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Wrong usage (args number): " << argv[0] << " <filename> <string1> <string2>" << '\n';
        return 1;
    }

    std::string filename = argv[1];
    std::string str1 = argv[2];
    std::string str2 = argv[3];

    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open input file " << filename << '\n';
        return 1;
    }

    if (str1.empty()) {
        std::cerr << "Error: str1 can't be empty\n";
        return 1;
    }

    std::ofstream outputFile(filename + ".replace");
    if (!outputFile.is_open()) {
        std::cerr << "Error: could not open output file " << filename + ".replace" << '\n';
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::string::size_type pos = 0;
        while ((pos = line.find(str1, pos)) != std::string::npos) {
            line.replace(pos, str1.length(), str2);
            pos += str2.length();
        }
        outputFile << line << '\n';
    }

    return 0;
}
