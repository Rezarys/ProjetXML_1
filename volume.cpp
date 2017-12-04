#include "volume.h"

int Volume::getNb_devices() const
{
    return nb_devices;
}

void Volume::setNb_devices(int value)
{
    nb_devices = value;
}

Bus Volume::getBus() const
{
    return bus;
}

void Volume::setBus(const Bus &value)
{
    bus = value;
}

string Volume::getConfig_type() const
{
    return config_type;
}

void Volume::setConfig_type(const string &value)
{
    config_type = value;
}

int Volume::getConfig_buffersize() const
{
    return config_buffersize;
}

void Volume::setConfig_buffersize(int value)
{
    config_buffersize = value;
}

QVector<Device> Volume::getDevices() const
{
    return devices;
}

void Volume::setDevices(const QVector<Device> &value)
{
    devices = value;
}

Volume::Volume()
{
    this->nb_devices = 1;

}

Volume::Volume(int nb_devices, Bus bus, string config_type, int config_buffersize, Device device)
    : nb_devices(nb_devices)
    , bus(bus)
    , config_type(config_type)
    , config_buffersize(config_buffersize)

{
    this->devices.append(device);
}
