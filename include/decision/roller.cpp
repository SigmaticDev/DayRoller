#include "roller.h"

Roller::Roller()
    : m_distribution(0.0, 1.0)
    , m_prng(std::random_device{}()) {}

bool Roller::operator()(double threshold)
{
    return m_distribution(m_prng) > threshold;
}
