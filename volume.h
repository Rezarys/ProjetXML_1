#ifndef VOLUME_H
#define VOLUME_H

#include <string>
#include <QVector>
#include "bus.h"
#include "device.h"

using namespace std;

class Volume
{
private:
    int nb_devices;
    Bus bus;
    string config_type;
    int config_buffersize;
    QVector<Device> devices;

public:
    Volume();
    Volume(int nb_devices, Bus bus, string config_type, int config_buffersize, Device device);

    /** Accesseurs et mutateurs **/

    int getNb_devices() const;
    void setNb_devices(int value);

    Bus getBus() const;
    void setBus(const Bus &value);

    string getConfig_type() const;
    void setConfig_type(const string &value);

    int getConfig_buffersize() const;
    void setConfig_buffersize(int value);

    QVector<Device> getDevices() const;
    void setDevices(const QVector<Device> &value);
};

#endif // VOLUME_H
