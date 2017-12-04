#include "bus.h"

string Bus::getName() const
{
    return name;
}

void Bus::setName(const string &value)
{
    name = value;
}

int Bus::getNb_ports() const
{
    return nb_ports;
}

void Bus::setNb_ports(int value)
{
    nb_ports = value;
}

int Bus::getBandwith() const
{
    return bandwith;
}

void Bus::setBandwith(int value)
{
    bandwith = value;
}

string Bus::getType() const
{
    return type;
}

void Bus::setType(const string &value)
{
    type = value;
}

Bus::Bus()
{

}

Bus::Bus(string name, int nb_ports, int bandwith, string type)
    : name(name)
    , nb_ports(nb_ports)
    , bandwith(bandwith)
    , type(type)
{

}
