#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <QString>

#include "serializable.h"

class Serializer
{
public:
    virtual ~Serializer() {}

    virtual void save(const Serializable& s,
                      const QString& filepath,
                      const QString& rootName = "") = 0;
    virtual void load(Serializable& s,
                      const QString& filepath) = 0;
};

#endif // SERIALIZER_H
