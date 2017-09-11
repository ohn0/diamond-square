#ifndef RNG_H
#define RNG_H
#include <random>
#include <chrono>

class RNG
{
    public:
        RNG();
        int genInt(int);
        virtual ~RNG();
    private:
        std::default_random_engine rng;

};

#endif // RNG_H
