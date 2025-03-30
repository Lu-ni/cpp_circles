#include <cctype>
#include <iostream>
#include <ostream>
#include <string>

using std::cout;

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos)
        return "";  // all spaces

    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; ++i) {
        std::string text = argv[i];
        for (std::string::size_type ii = 0; ii < text.length(); ii++) {
            text[ii] = std::toupper(static_cast<unsigned char>(text[ii]));
        }
        cout << trim(text);
        if (i == argc - 1) {
            cout << std::endl;
        } else {
            cout << " ";
        }
    }

    return 0;
}
