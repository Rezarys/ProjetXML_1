#include "tier.h"

Bus Tier::getBus() const
{
    return bus;
}

void Tier::setBus(const Bus &value)
{
    bus = value;
}

QVector<Volume> Tier::getVolumes() const
{
    return volumes;
}

void Tier::setVolumes(const QVector<Volume> &value)
{
    volumes = value;
}

Tier::Tier()
{

}
