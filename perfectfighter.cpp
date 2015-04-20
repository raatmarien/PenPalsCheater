#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

bool isMax(int min, int max, int randint);
bool isPerfect(int randint);

int main () {
    int seed;
    for (seed = 0; !isPerfect(seed); seed++);
    cout << seed << endl;
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
