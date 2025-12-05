#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

struct PuzzleInput {
    std::vector<std::pair<long long, long long>> ranges;
};

PuzzleInput read_input(std::ifstream& in) {
    PuzzleInput input;
    std::string line;
    while (std::getline(in, line)) {
        if (line.find_first_not_of(' ') == line.npos) {
            break;
        }
        const auto delim = line.find("-");
        const auto first = line.substr(0, delim);
        const auto second = line.substr(delim + 1, line.npos);
        input.ranges.push_back(std::make_pair(
            std::stoll(first),
            std::stoll(second)
        ));
    }
    return input;
}

long long solve(PuzzleInput& input) {
    std::vector<std::pair<long long, long long>>& ranges = input.ranges;
    std::sort(ranges.begin(), ranges.end());

    long long fresh = 0;
    long long maxEnd = ranges[0].second;
    fresh += ranges[0].second - ranges[0].first + 1;

    for (int curr = 1; curr < ranges.size(); curr++) {
        if (maxEnd >= ranges[curr].first) {
            if (ranges[curr].second > maxEnd) {
                fresh += ranges[curr].second - maxEnd;
                maxEnd = ranges[curr].second;
            }
        } else {
            fresh += ranges[curr].second - ranges[curr].first + 1;
            maxEnd = ranges[curr].second;
        }
    }

    return fresh;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ifstream in("day-05/input.txt");
    PuzzleInput input = read_input(in);

    std::cout << "fresh: " << solve(input) << std::endl;
}
