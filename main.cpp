#include <QCoreApplication>
#include <QDebug>
#include "xmldomdocument.h"
#include "architecture.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    string value;

    XmlDomDocument* doc = new XmlDomDocument("./XML_files/arch_jbod.xml");
    if (doc) {
        int nb_buses = stoi(doc->getChildAttribute("architecture", 0, "buses", 0, "nbbuses").c_str());
        cout << "Architecture JOBD : " << endl << endl;
        cout << "   Nombre de bus : " << nb_buses << endl;
        for(int i = 0; i < nb_buses; ++i){
            cout << "   Bus " << i+1 << " :" << endl;
            cout << "      Name : " << doc->getChildAttribute("buses", 0, "bus", i, "name").c_str() << endl;
            cout << "      Nombre de ports : " << doc->getChildAttribute("buses", 0, "bus", i, "nbports").c_str() << endl;
            cout << "      Bande passante : " << doc->getChildAttribute("buses", 0, "bus", i, "bandwidth").c_str() << endl;
            cout << "      Type : " << doc->getChildAttribute("buses", 0, "bus", i, "type").c_str() << endl << endl;
        }

        cout << "   Le système est composé de " << doc->getChildAttribute("architecture", 0, "system", 0, "nbtiers").c_str() << " tier(s) "
             << "branché(s) au système à travers le bus " << doc->getChildAttribute("architecture", 0, "system", 0, "bus").c_str()
             << ". Le premier tier comprend " << doc->getChildAttribute("system", 0, "tier", 0, "nbvolumes").c_str() << " volume(s) "
             << "branché(s) au premier tier à travers le bus " << doc->getChildAttribute("system", 0, "tier", 0, "bus").c_str()
             << ". Le premier volume contient " << doc->getChildAttribute("tier", 0, "volume", 0, "nbdevices").c_str() << " disque(s) "
             << "branché(s) au premier volume à travers le bus " << doc->getChildAttribute("tier", 0, "volume", 0, "bus").c_str()
             << ". Ce volume est de type " << doc->getChildAttribute("volume", 0, "config", 0, "type").c_str() << ". Le fichier de "
             << "configuration des disques se trouve à l'adresse \"" << doc->getChildAttribute("volume", 0, "device", 0, "file").c_str()
             << "\"" << endl;

        delete doc;

        QVector<Bus> buses;
        buses.append(Bus("B0", 17, 640, "SCSI"));
        buses.append(Bus("B1", 17, 640, "SCSI"));
        buses.append(Bus("B2", 17, 640, "SCSI"));

        Architecture A("JBOD", "./XML_files/arch_jbod.xml", buses);
        XmlDomDocument* doc2 = new XmlDomDocument("./XML_files/arch_jbod.xml");
        doc2->outPutXMLFile(A);

        delete doc2;
        exit(0);
    }/*
    Bus B0("B0", 1, 600, "SCSI");
    Device hdd("./XML_files/bookstore.xml");

    Volume v1(1, B0, "JBOD", -1, hdd);

    qDebug() << v1.getBus().getName().c_str();*/


    return a.exec();
}
