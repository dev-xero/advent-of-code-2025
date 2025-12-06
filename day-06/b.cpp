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
    // The nature of the problem is different this time.
    // We read numbers top-down, right-to-left, column to column.
    // Each 'cell' is separated by a column of whitespace.
    std::string& ops = input.back();
    ops.erase(std::remove(ops.begin(), ops.end(), ' '), ops.end());

    int k = ops.size();
    std::vector<long long> res(k);

    // Identity elements.
    for (int i = 0; i < k; ++i) {
        res[i] = (ops[i] == '*') ? 1 : 0;
    }

    // Determine overall number of rows and columns.
    // Had issues with my editor trimming whitespaces here.
    int m = input.size() - 1;
    int n = input[0].size();
    
    int bin = k - 1;
    for (int col = n - 1; col > -1; col--) {
        std::string num;
        for (int row = 0; row < m; row++) {
            if (input[row][col] == ' ') {
               continue;
            } else {
                num += input[row][col];
            }
        }
        // If num is empty, then its time for another bin.
        if (num.find_first_not_of(' ') == num.npos) {
            bin--;
        } else {
            long long val = std::stoll(num);
            ops[bin] == '*'
                ? res[bin] *= val
                : res[bin] += val;
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
