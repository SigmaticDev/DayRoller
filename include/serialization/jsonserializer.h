#ifndef JSONSERIALIZER_H
#define JSONSERIALIZER_H

#include "serializer.h"

class JsonSerializer : public Serializer
{
public:
    JsonSerializer();

    void save(const Serializable& s,
              const QString& filepath,
              const QString& rootName) override;
    void load(Serializable& s,
              const QString& filepath) override;
};

#endif // JSONSERIALIZER_H
