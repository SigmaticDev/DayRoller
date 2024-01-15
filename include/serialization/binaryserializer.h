#ifndef BINARYSERIALIZER_H
#define BINARYSERIALIZER_H

#include "serializer.h"

class BinarySerializer : public Serializer
{
public:
    BinarySerializer();

    void save(const Serializable& s,
              const QString& filepath,
              const QString& rootName) override;
    void load(Serializable& s,
              const QString& filepath) override;
};

#endif // BINARYSERIALIZER_H
