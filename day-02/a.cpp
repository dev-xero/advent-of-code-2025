#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

std::vector<std::pair<long long, long long>> getRanges(std::ifstream& in) {
    std::vector<std::pair<long long, long long>> ranges;
    std::string first;
    std::string last;

    char ch;
    bool inSecondPart = false;

    // Since we're reading a single long line, this should suffice.
    while (in.get(ch)) {
        if (ch == ',') {
            ranges.push_back(std::make_pair(std::stoll(first), std::stoll(last)));
            inSecondPart = false;
            first = "";
            last = "";
        } else if (ch == '-') {
            inSecondPart = true;
        } else {
            if (inSecondPart) last += ch;
            else first += ch;
        }
    }

    ranges.push_back(std::make_pair(std::stoll(first), std::stoll(last)));

    return ranges;
}

bool isRepeating(const std::string& id) {
    if (id.size() % 2 != 0)
        return false;

    int halfLen = id.length() / 2;
    std::string firstHalf = id.substr(0, halfLen);
    std::string secondHalf = id.substr(halfLen, halfLen);

    return firstHalf == secondHalf;
}

int main() {
    std::ifstream in("day-02/input.txt");
    std::vector<std::pair<long long, long long>> ranges = getRanges(in);

    // :skull_emoji
    long long invalidIds = 0;
    for (const auto &[first, last] : ranges) {
        for (auto id = first; id <= last; id++) {
            // We only consider even-length ids
            std::string idStr = std::to_string(id);
            if (isRepeating(idStr)) {
                invalidIds += id;
            }
        }
    }

    std::cout << "invalid ids: " << invalidIds << std::endl;
}
