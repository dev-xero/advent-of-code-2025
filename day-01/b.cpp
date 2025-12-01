
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

    // * There are cases where zero occurs a few times during rotations.
    //
    // * We need to know the number of times we pass 0 given t turns, this is just t/100.
    // * If t < 100, then no loop happens.
    //
    // * Note: position should be considered, for instance:
    // *    - if pos = 90, and we have t = 20, 20/100 ~ 0.
    // *    - we've looped in this case.
    //
    // * If applying turns remains in bounds (0 - 99) we don’t care.
    while (std::getline(file, line)) {
        char direction = line[0] == 'L' ? -1 : 1;
        ll turns = std::stoi(line.substr(1, line.size() - 1));

        password += turns / TRACKS;

        ll prevPos = position;
        ll remainder = turns % TRACKS;

        position += direction * turns;
        position %= TRACKS;
        if (position < 0)
            position += TRACKS;

        // TIL, C++ % is not mathematical modulo, I've wasted so much time
        // bashing my head against a wall.
        if (direction == 1) {
            if (prevPos + remainder >= TRACKS)
                password++;
        } else {
            if (prevPos > 0 && prevPos - remainder <= 0)
                password++;
        }
    }

    std::cout << "Result: " << password << std::endl;
}
