#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;

bool isMax(int min, int max, int randint);
bool isPerfect(int randint);
string genName(int seed);
string toString(int num);

int main () {
    int seed;
    for (seed = 0; !isPerfect(seed); seed++);
    cout << genName(seed) << endl;
}

bool isMax(int min, int max, int randint) {
    int val = randint % (max + 1 - min) + min;
    return val == max;
}

bool isPerfect(int seed) {
    srand(seed);
    int randint = rand();
    return isMax(75, 125, randint) // health
        // weight hoeft niet?
        // && isMax(48,400,randint)
        && isMax(5, 20, randint) // strength
        && isMax(12, 28, randint) // jump
        && isMax(75, 120, randint);
}

string genName(int seed) {
    int rest = -1;
    string name = "a";
    bool done = false;
    for (int i = 32; i < 127 && !done; i++) {
        for (int j = 32; j < 127; j++) {
            int left = seed - ((i * 4) * j);
            if (left > 0 && left < 126 * 4) {
                rest = left;
                for (int x = 0; x < 4; x++) {
                    name += (char) i;
                }
                name += (char) j;
                done = true;
                break;
            }
        }
    }
    if (rest != -1) {
        for (int i = 0; i < 4; i++) {
            int charNum = rest / (4 - i);
            name += (char) charNum;
            rest -= rest / (4 - i);
        }
        name += (char) rest;
        string msg = "The seed is ";
        msg.append(toString(seed));
        msg.append(". The name found is ");
        msg.append(name);
        return msg;
    } else {
        name = "No name could be found, the seed is ";
        name.append(toString(seed));
    }
    return name;
}


string toString(int num) {
    string numString;
    while(num > 0) {
        numString = ((char) ((num % 10)
                      + 48))
            + numString;
        num /= 10;
    }
    return numString;
}
