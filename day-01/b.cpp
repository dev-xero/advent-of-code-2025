
#include <iostream>
#include <fstream>
#include <string>

using ll = long long;

int main() {
    const int TRACKS = 100;
    ll password = 0;
    ll position = 50;

    std::ifstream file("day-01/input.txt");
    std::string line;

    while (std::getline(file, line)) {
        char direction = line[0] == 'L' ? -1 : 1;
        ll turns = std::stoi(line.substr(1, line.size() - 1));
        ll zeroTurns = 0;
        if (position < 0) {
            zeroTurns = (turns - position) / TRACKS;
        } else {
            zeroTurns = (position + turns) / TRACKS;
        }
        password += zeroTurns;
        position += direction * turns;
        position %= TRACKS;
        if (position == 0)
            password++;
    }

    std::cout << "result: " << password << std::endl;
}
