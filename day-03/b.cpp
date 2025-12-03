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
    long long output_joltage = 0;

    for (const auto& line : lines) {
        // Max skippable window = R - N + 1
        // where:
        // - R is the digits remaining
        // - N is the digits still needed
        std::string joltage;
        int idx = 0;

        while (joltage.length() != 12) {
            int N = 12 - joltage.length();
            int R = line.length() - idx;
            int window = R - N + 1;

            char best = '0';
            int best_idx = idx;

            for (int i = idx; i < idx + window; i++) {
                if (line[i] > best) {
                    best = line[i];
                    best_idx = i;
                }
            }

            joltage += best;
            idx = best_idx + 1;
        }

        output_joltage += std::stoll(joltage);
    }

    return output_joltage;
}

int main() {
    std::ifstream in("day-03/input.txt");
    long long total_joltage = solve(read_input(in));
    std::cout << "total joltage: " << total_joltage << std::endl;
}
