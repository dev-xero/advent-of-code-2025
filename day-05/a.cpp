#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

struct PuzzleInput {
    std::vector<std::pair<long long, long long>> ranges;
    std::vector<long long> ids;
};

PuzzleInput read_input(std::ifstream& in) {
    PuzzleInput input;
    std::string line;
    bool reading_ids = false;
    while (std::getline(in, line)) {
        if (line.find_first_not_of(' ') == line.npos) {
            reading_ids = true;
            continue;
        }
        if (reading_ids) {
            input.ids.push_back(std::stoll(line));
        } else {
            const auto delim = line.find("-");
            const auto first = line.substr(0, delim);
            const auto second = line.substr(delim + 1, line.npos);
            input.ranges.push_back(std::make_pair(
                std::stoll(first),
                std::stoll(second)
            ));
        }
    }
    return input;
}

long long solve(PuzzleInput& input) {
    long long fresh = 0;
    for (const long long id : input.ids) {
        for (const auto& range : input.ranges) {
            if (id >= range.first && id <= range.second) {
                fresh++;
                break;
            }
        }
    }
    return fresh;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ifstream in("day-05/input.txt");
    PuzzleInput input = read_input(in);

    std::sort(input.ranges.begin(), input.ranges.end());

    std::cout << "fresh: " << solve(input) << std::endl;
}
