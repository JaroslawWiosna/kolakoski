#include <iostream>
#include <vector>

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

int main() {
    auto vec = kolakoski(100);
    for (const auto& i : vec) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
    return 0;
}