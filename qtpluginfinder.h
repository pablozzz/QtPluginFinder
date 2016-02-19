#ifndef QTPLUGINFINDER_H
#define QTPLUGINFINDER_H

#include <QWidget>
#include <QtWidgets>
#include <myplugininterface.h>

class QString;
class QLineEdit;
class QLabel;
class QPushButton;
class QGridLayout;

class QtPluginFinder : public QWidget
{
    Q_OBJECT

public:
    QtPluginFinder();

private slots:
    void start_plugin();
    void plugin_dir();

private:
    void createGUI();
    bool loadPlugin();

    MyPluginInterface *myPluginInterface;
    QLabel *label;
    QLineEdit *DirPath;
    QPushButton *plugin_start_button;
    QPushButton *exit_button;
    QPushButton *choose_dir;
    QVBoxLayout *vlayout;
    QHBoxLayout *hlayout1;
    QHBoxLayout *hlayout2;
    QListWidget *plugins_list;
    QListWidgetItem *item;
};

#endif // QTPLUGINFINDER_H
