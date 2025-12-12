#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> read_input(std::ifstream& in) {
    std::vector<std::string> manifold;
    std::string line;
    while (std::getline(in, line)) {
        manifold.push_back(line);
    }
    return manifold;
}

long long solve(std::vector<std::string> input) {
    int m = input.size();
    int n = input[0].length();
    std::vector<long long> columns(n, 1ll);
    for (int row = m - 2; row > 1; row -= 2) {
        for (int col = 0; col < n; col++) {
            if (input[row][col] == '^') {
                columns[col] = columns[col - 1] + columns[col + 1];
            }
        }
    }
    return columns[n / 2];
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::ifstream in("day-07/input.txt");
    std::vector<std::string> input = read_input(in);
    
    std::cout << "timelines: " << solve(input) << std::endl;
}
