#include <fstream>
#include <iostream>
#include <string>

long long solve(std::ifstream &in) {
    std::string line;
    // We need to first identify the index of the largest
    // digit.
    int N = 0;
    int outputJoltage = 0;
    while (std::getline(in, line)) {
        if (!N) {
            N = line.length();
        }
        // Find the largest joltage first
        int firstDigit = 0;
        int firstIndex = 0;
        for (int i = 0; i < N; i++) {
            if (line[i] - '0' > firstDigit) {
                firstDigit = line[i] - '0';
                firstIndex = i;
            }
        }
        int secondDigit = 0;
        int secondIndex = 0;
        for (int i = 0; i < N; i++) {
            if (line[i] - '0' > secondDigit && i != firstIndex) {
                // If there are still digits in front of the first index,
                // this digit cannot make the max possible number.
                if (i < firstIndex && firstIndex < N - 1) {
                    continue;
                }
                secondDigit = line[i] - '0';
                secondIndex = i;
            }
        }
        if (firstIndex < secondIndex) {
           outputJoltage += firstDigit * 10 + secondDigit;
        } else {
            outputJoltage += secondDigit * 10 + firstDigit;
        }
    }
    return outputJoltage;
}

int main() {
    std::ifstream in("day-03/input.txt");
    long long totalJoltage = solve(in);
    std::cout << "total joltage: " << totalJoltage << std::endl;
}
