#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

std::vector<std::string> read_input(std::ifstream& in) {
    std::vector<std::string> input;
    std::string line;
    while (std::getline(in, line)) {
       input.push_back(line);
    }
    return input;
}

long long solve(std::vector<std::string>& input) {
    // To know how many cols we have, strip the last row (operators) and find its length.
    // Then we can have 'bins' where each computation is stored.
    std::string& ops = input.back();
    ops.erase(std::remove(ops.begin(), ops.end(), ' '), ops.end());

    int k = ops.size();
    std::vector<long long> res(k);

    // Identity elements for + and *.
    for (int i = 0; i < k; ++i) {
        res[i] = (ops[i] == '+') ? 0 : 1;
    }

    // Up onto the last row (which are just operators).
    for (int row = 0; row < input.size() - 1; row++) {
        const std::string& line = input[row];
        int ch_idx = 0;
        int bin = 0;

        while (ch_idx < line.length() && bin < k) {
            // skip spaces
            while (ch_idx < line.length() && line[ch_idx] == ' ')
                ch_idx++;

            if (ch_idx >= line.length()) break;

            std::string num;
            while (ch_idx < line.length() && line[ch_idx] != ' ') {
                num += line[ch_idx++];
            }

            long long val = std::stoll(num);
            ops[bin] == '+'
                ? res[bin++] += val
                : res[bin++] *= val;
        }
    }

    return std::accumulate(res.begin(), res.end(), 0ll);
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ifstream in("day-06/input.txt");
    std::vector<std::string> input = read_input(in);

    std::cout << "ans: " << solve(input) << std::endl;
}
