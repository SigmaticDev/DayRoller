#include "jsonserializer.h"

#include <QFile>
#include <QJsonDocument>

JsonSerializer::JsonSerializer() {}

void JsonSerializer::save(const Serializable& s,
                          const QString& filepath,
                          const QString& rootName)
{
    QJsonDocument doc = QJsonDocument::fromVariant(s.toVariant());
    QFile file(filepath);
    file.open(QFile::WriteOnly);
    file.write(doc.toJson());
    file.close();
}

void JsonSerializer::load(Serializable& s,
                          const QString& filepath)
{
    QFile file(filepath);
    file.open(QFile::ReadOnly);
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();
    s.fromVariant(doc.toVariant());
}
