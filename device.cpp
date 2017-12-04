#include "device.h"

string Device::getPath() const
{
    return path;
}

void Device::setPath(const string &value)
{
    path = value;
}

Device::Device()
{

}

Device::Device(string path)
    : path(path)
{

}
