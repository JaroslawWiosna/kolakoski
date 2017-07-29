#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

std::vector<std::size_t> kolakoski(std::size_t size) {
    std::vector<std::size_t> vec;
    vec.reserve(size);
    vec.emplace_back(1);
    vec.emplace_back(2);
    vec.emplace_back(2);
    std::vector<std::size_t>::iterator it = vec.begin() + 2;
    while (vec.size() < size) {
        if (*it == 1) {
            if (vec.back() == 1) {
                vec.emplace_back(2);
            } else { //if (vec.back() == 2) {
                vec.emplace_back(1);
            }  
        } else { //if (*it == 2) {
            if (vec.back() == 1) {
                vec.emplace_back(2);
                vec.emplace_back(2);
            } else { //if (vec.back() == 2) {
                vec.emplace_back(1);
                vec.emplace_back(1);
            }       }
        ++it;
    }
    return vec;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Please, set the length of sequence.\nAborting...\n";
        throw;
    }

    std::size_t length;
    std::istringstream ss(argv[1]);
    if (!(ss >> length)) {
        std::cerr << "Invalid number " << argv[1] << '\n';
    }

    auto vec = kolakoski(length);
    for (const auto& i : vec) {
        std::cout << i << ", ";
    }
    std::cout << "\b\b  " << std::endl;

    std::string filename{"../kolakoskiSequences/kolakoski-"};
//    filename += length;
    filename += ss.str();
    filename += ".txt";
    std::ofstream ostrm(filename);
    if (ostrm) {
        for (const auto& i : vec) {
            ostrm << i << ", ";
        }
        ostrm << "\b\b  " << std::endl;
    } else {
        throw;
    }

    return 0;
}
