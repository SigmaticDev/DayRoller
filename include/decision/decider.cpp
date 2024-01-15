#include "decider.h"

#include <iostream>

#include "directive.h"

Decider::Decider(QObject *parent)
    : QObject{parent}
    , m_bias(0.0)
    , m_roller()
{}

void Decider::setBias(const double &bias)
{
    if (bias >= -0.50 && bias <= 0.50) {
        m_bias = bias;
        emit biasChanged(m_bias);
    } else {
        std::cout << "[Decider::setBias]" << std::endl;
        std::cout << "ERROR! Failed to set. Value out of range." << std::endl;
    }
}

bool Decider::decideFor(Directive *directive)
{
    return m_roller(directive->threshold() + m_bias);
}
