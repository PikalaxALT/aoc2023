#include <fstream>
#include <string>
#include <array>
#include <iostream>
#include "AOC2023.h"

class Day1 : public AOC2023::AOC2023Base {
public:
    Day1() : AOC2023::AOC2023Base() {}
    int part1(std::ifstream& strm) final {
        constexpr std::string_view digits {"0123456789"};
        std::string line;
        int result = 0;
        while (std::getline(strm, line)) {
            std::size_t lpos = line.find_first_of(digits);
            std::size_t rpos = line.find_last_of(digits);
            result += 10 * (line[lpos] - '0') + (line[rpos] - '0');
        }
        std::cout << result << "\n";
        return 0;
    }
    int part2(std::ifstream& strm) final {
        int result = 0;
        std::string line;
        std::array<const char*, 20> numbers {
            "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
            "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
        };
        while (std::getline(strm, line)) {
            int tens = -1;
            int ones = -1;
            std::size_t lpos = std::string::npos;
            std::size_t rpos = std::string::npos;
            for (std::size_t i = 0; i < numbers.size(); ++i) {
                const auto& s = numbers[i];
                std::size_t pos;
                if ((pos = line.find(s)) != std::string::npos) {
                    if (pos < lpos) {
                        lpos = pos;
                        tens = i % 10;
                    }

                    // Because find returned != npos, rfind is guaranteed to also return != npos.
                    pos = line.rfind(s);
                    if (rpos == std::string::npos || pos > rpos) {
                        rpos = pos;
                        ones = i % 10;
                    }
                }
            }
            result += 10 * tens + ones;
        }
        std::cout << result << "\n";
        return 0;
    }
};

int main(int argc, char** argv) {
    return AOC2023::main<Day1>(argc, argv);
}
