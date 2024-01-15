#ifndef ROLLER_H
#define ROLLER_H

#include <random>

class Roller
{
public:
    Roller();

    bool operator()(double threshold);

private:
    std::uniform_real_distribution<> m_distribution;
    std::mt19937 m_prng;
};

#endif // ROLLER_H
