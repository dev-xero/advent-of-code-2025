#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

std::vector<std::string> read_input(std::ifstream& in) {
    std::vector<std::string> manifold;
    std::string line;
    while (std::getline(in, line)) {
        manifold.push_back(line);
    }
    return manifold;
}

// For each row, we maintain a set of active beam positions.
// If a column contains a splitter '^', then we add the left
// and right cols from this splitter.
// Otherwise, this beam moves straight through, we add it to the next set.
long long solve(std::vector<std::string> input) {
    int m = input.size();
    int n = input[0].length();
    
    std::unordered_set<int> beams;
    for (int col = 0; col < n; col++) {
        if (input[0][col] == 'S') {
            beams.insert(col);
            break;
        }
    }
    
    long long splits = 0ll;
    for (std::size_t row = 0; row < m; row++) {
        if (beams.empty()) {
            break;
        }
        std::unordered_set<int> next_beams;
        for (const int col : beams) {
            if (input[row][col] == '^') {
                splits++;
                if (col > 0)
                    next_beams.insert(col - 1);
                if (col < n - 1)
                    next_beams.insert(col + 1);
            } else {
                next_beams.insert(col);
            }
        }
        beams = next_beams;
    }
    
    return splits; 
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::ifstream in("day-07/input.txt");
    std::vector<std::string> input = read_input(in);
    
    std::cout << "splits: " << solve(input) << std::endl;
}
