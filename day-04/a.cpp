#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Look up adjacent 8 cells from (i, j). Returns if there are fewer
// than 4 cells with rolls '@'.
bool adj_fewer_than_four(std::vector<std::vector<char>>& grid, int i, int j) {
    int N = grid.size();
    int M = grid[0].size();

    int rolls = 0;

    if (i != 0) {
        // Top-left
        if (j != 0) rolls += grid[i - 1][j - 1] == '@';
        // Top-right
        if (j != M - 1) rolls += grid[i - 1][j + 1] == '@';
        // Top
        rolls += grid[i - 1][j] == '@';
    }

    if (i != N - 1) {
        // Bottom-left
        if (j != 0) rolls += grid[i + 1][j - 1] == '@';
        // Bottom-right
        if (j != M - 1) rolls += grid[i + 1][j + 1] == '@';
        // Bottom
        rolls += grid[i + 1][j] == '@';
    }

    // Left
    if (j != 0) rolls += grid[i][j - 1] == '@';

    // Right
    if (j != M - 1) rolls += grid[i][j + 1] == '@';

    return rolls < 4;
}

long long solve(std::vector<std::vector<char>>& grid) {
    int N = grid.size();
    int M = grid[0].size();
    long long can_access = 0;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            char cell = grid[row][col];
            if (cell == '@' && adj_fewer_than_four(grid, row, col)) {
                can_access++;
            }
        }
    }
    return can_access;
}

std::vector<std::vector<char>> read_input(std::ifstream& in) {
    std::vector<std::vector<char>> grid;
    std::string line;
    while (std::getline(in, line)) {
        std::vector<char> row;
        for (const auto& ch : line) {
            row.push_back(ch);
        }
        grid.push_back(row);
    }
    return grid;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ifstream in("day-04/input.txt");
    std::vector<std::vector<char>> grid = read_input(in);

    std::cout << "can access: " << solve(grid) << std::endl;
}
