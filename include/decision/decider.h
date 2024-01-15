#ifndef DECIDER_H
#define DECIDER_H

#include <QObject>

#include "roller.h"

class Directive;

class Decider : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double bias READ bias WRITE setBias NOTIFY biasChanged FINAL)
public:
    explicit Decider(QObject *parent = nullptr);

    double bias() const {return m_bias;}

    void setBias(const double& bias);

    bool decideFor(Directive* directive);

signals:
    void biasChanged(const double& newBias);

private:
    double m_bias;
    Roller m_roller;
};

#endif // DECIDER_H
