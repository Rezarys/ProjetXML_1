#ifndef ARCHITECTURE_H
#define ARCHITECTURE_H

#include <string>
#include <QVector>
#include "bus.h"
#include "system.h"

class Architecture
{
private:
    string type;
    string path;
    QVector<Bus> buses;
    QVector<System> system;

public:
    /** Constructeurs **/

    Architecture();
    Architecture(string type, string path, QVector<Bus> buses);

    /** Accesseurs et mutateurs **/

    string getType() const;
    void setType(const string &value);

    string getPath() const;
    void setPath(const string &value);

    QVector<Bus> getBuses() const;
    void setBuses(const QVector<Bus> &value);

    QVector<System> getSystem() const;
    void setSystem(const QVector<System> &value);
};

#endif // ARCHITECTURE_H
