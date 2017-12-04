#include "system.h"

Bus System::getBus() const
{
    return bus;
}

void System::setBus(const Bus &value)
{
    bus = value;
}

QVector<Tier> System::getTiers() const
{
    return tiers;
}

void System::setTiers(const QVector<Tier> &value)
{
    tiers = value;
}

System::System()
{

}
