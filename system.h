#ifndef SYSTEM_H
#define SYSTEM_H

#include <QVector>
#include "tier.h"

class System
{
private:
    Bus bus;
    QVector<Tier> tiers;
public:
    System();

    /** Accesseurs et mutateurs **/

    Bus getBus() const;
    void setBus(const Bus &value);

    QVector<Tier> getTiers() const;
    void setTiers(const QVector<Tier> &value);
};

#endif // SYSTEM_H
