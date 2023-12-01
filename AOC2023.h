#ifndef GUARD_AOC2023_H
#define GUARD_AOC2023_H

static_assert(__cplusplus >= 202100L);

#include <string>
#include <fstream>
#include <iostream>

namespace AOC2023 {
class AOC2023Base {
public:
    AOC2023Base() = default;
    virtual int part1(std::ifstream& strm) {
        std::cerr << "not implemented\n";
        return 1;
    }
    virtual int part2(std::ifstream& strm) {
        std::cerr << "not implemented\n";
        return 1;
    }
};

template<typename T>
int main(int argc, char** argv) {
    using namespace std::literals;
    std::string usage = "usage: "s + argv[0] + " FILENAME PART";
    if (argc < 3) {
        std::cerr << "error: insufficient arguments\n\n" << usage << "\n";
        return 1;
    }
    int part = std::stoi(argv[2]);
    if (part != 1 && part != 2) {
        std::cerr << "error: PART must be 1 or 2, got " << part << "\n\n" << usage << "\n";
        return 1;
    }
    std::ifstream infile {argv[1]};
    if (!infile) {
        std::cerr << "error: unable to open " << argv[1] << " for reading\n\n" << usage << "\n";
        return 1;
    }
    T t {};
    return part == 1 ? t.part1(infile) : t.part2(infile);
}
}

#endif //GUARD_AOC2023_H
