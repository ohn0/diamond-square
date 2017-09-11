#include "RNG.h"

RNG::RNG()
{
    rng.seed(std::chrono::system_clock::now().time_since_epoch().count());
}

RNG::~RNG()
{
}

RNG::genInt(int n){
    std::uniform_int_distribution<int> gen(0, n);
    return gen(rng);

}
