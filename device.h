#ifndef DEVICE_H
#define DEVICE_H

#include <string>

using namespace std;

class Device
{
private:
    string path;
public:
    Device();
    Device(string path);

    /** Accesseurs et mutateurs **/

    string getPath() const;
    void setPath(const string &value);
};

#endif // DEVICE_H
