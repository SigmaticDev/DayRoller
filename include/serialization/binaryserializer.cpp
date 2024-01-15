#include "binaryserializer.h"

#include <QDataStream>
#include <QFile>

BinarySerializer::BinarySerializer() {}

void BinarySerializer::save(const Serializable& s,
                            const QString& filepath,
                            const QString& /*rootName*/)
{
    QFile file(filepath);
    file.open(QFile::WriteOnly);
    QDataStream dataStream(&file);
    dataStream << s.toVariant();
    file.close();
}

void BinarySerializer::load(Serializable& s,
                            const QString& filepath)
{
    QFile file(filepath);
    file.open(QFile::ReadOnly);
    QDataStream dataStream(&file);
    QVariant variant;
    dataStream >> variant;
    s.fromVariant(variant);
    file.close();
}
