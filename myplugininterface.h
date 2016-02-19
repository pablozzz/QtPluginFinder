#ifndef MYPLUGININTERFACE_H
#define MYPLUGININTERFACE_H
#include <QString>

class MyPluginInterface
{
public:
    virtual ~MyPluginInterface() {}
    virtual bool start_plugin() = 0;
};

#define MyPluginInterface_iid "MyPluginInterface"

Q_DECLARE_INTERFACE(MyPluginInterface, MyPluginInterface_iid)

#endif // MYPLUGININTERFACE_H
