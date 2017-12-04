#include "architecture.h"

string Architecture::getType() const
{
    return type;
}

void Architecture::setType(const string &value)
{
    type = value;
}

string Architecture::getPath() const
{
    return path;
}

void Architecture::setPath(const string &value)
{
    path = value;
}

QVector<Bus> Architecture::getBuses() const
{
    return buses;
}

void Architecture::setBuses(const QVector<Bus> &value)
{
    buses = value;
}

QVector<System> Architecture::getSystem() const
{
    return system;
}

void Architecture::setSystem(const QVector<System> &value)
{
    system = value;
}

Architecture::Architecture()
{

}

Architecture::Architecture(string type, string path, QVector<Bus> buses)
    : type(type)
    , path(path)
    , buses(buses)
{

}
