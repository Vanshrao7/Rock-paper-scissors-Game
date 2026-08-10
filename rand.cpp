#include "rand.h"
#include <random>
using namespace std;
random_device seed;
mt19937 engine{seed()};
int Rand()
{

    uniform_int_distribution get{0, 2};
    return get(engine);
}