#ifndef BUS_H
#define BUS_H

#include <string>

using namespace std;

class Bus
{
private:
    string name;
    int nb_ports;
    int bandwith;
    string type;
public:
    Bus();
    Bus(string name, int nb_ports, int bandwith, string type);

    /** Accesseurs et mutateurs **/

    string getName() const;
    void setName(const string &value);

    int getNb_ports() const;
    void setNb_ports(int value);

    int getBandwith() const;
    void setBandwith(int value);

    string getType() const;
    void setType(const string &value);
};

#endif // BUS_H
