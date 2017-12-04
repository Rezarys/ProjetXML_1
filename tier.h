#ifndef TIER_H
#define TIER_H

#include <QVector>
#include "volume.h"

class Tier
{
private:
    Bus bus;
    QVector<Volume> volumes;
public:
    Tier();

    /** Accesseurs et mutateurs **/

    Bus getBus() const;
    void setBus(const Bus &value);

    QVector<Volume> getVolumes() const;
    void setVolumes(const QVector<Volume> &value);
};

#endif // TIER_H
