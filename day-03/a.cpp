#include <fstream>
#include <iostream>
#include <string>

std::vector<std::string> read_input(std::ifstream& in) {
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(in, line)) {
        lines.push_back(line);
    }
    return lines;
}

long long solve(std::vector<std::string> lines) {
    int N = lines[0].length();
    int output_joltage = 0;

    for (const auto& line : lines) {
        int first_digit = 0;
        int first_index = 0;
        for (int i = 0; i < N; i++) {
            if (line[i] - '0' > first_digit) {
                first_digit = line[i] - '0';
                first_index = i;
            }
        }

        int second_digit = 0;
        int second_index = 0;
        for (int i = 0; i < N; i++) {
            if (line[i] - '0' > second_digit && i != first_index) {
                // If there are still digits in front of the first index,
                // this digit cannot make the max possible number.
                if (i < first_index && first_index < N - 1) {
                    continue;
                }
                second_digit = line[i] - '0';
                second_index = i;
            }
        }

        if (first_index < second_index) {
            output_joltage += first_digit * 10 + second_digit;
        } else {
            output_joltage += second_digit * 10 + first_digit;
        }
    }

    return output_joltage;
}

int main() {
    std::ifstream in("day-03/test.txt");
    long long total_joltage = solve(read_input(in));
    std::cout << "total joltage: " << total_joltage << std::endl;
}
