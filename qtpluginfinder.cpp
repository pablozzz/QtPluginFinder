#include "qtpluginfinder.h"

QtPluginFinder::QtPluginFinder()
{
    createGUI();
    setLayout(vlayout);
    setWindowTitle("Simple Plugin Example");

}

void QtPluginFinder::start_plugin()
{
    if (!loadPlugin()) {
        QMessageBox::information(this, "Error", "Could not load the plugin");
    }
    else {
        bool plugin_started = myPluginInterface->start_plugin();
    }

}

void QtPluginFinder::createGUI()
{
    label = new QLabel("Press button to choose plugins directory:");
    DirPath= new QLineEdit;
    choose_dir = new QPushButton("Choose Dir");
    connect (choose_dir,SIGNAL(clicked(bool)),this,SLOT(plugin_dir()));

    hlayout1 = new QHBoxLayout;
    hlayout1->addWidget(DirPath);
    hlayout1->addWidget(choose_dir);

    plugin_start_button = new QPushButton("Start Plugin");
    plugin_start_button->setHidden(true);
    connect(plugin_start_button, SIGNAL(clicked()),
            this, SLOT(start_plugin()));

    exit_button = new QPushButton("Exit");
    connect(exit_button,SIGNAL(clicked(bool)),this,SLOT(close()));

    hlayout2 = new QHBoxLayout;
    hlayout2->addWidget(plugin_start_button);
    hlayout2->addWidget(exit_button);

    //Prepeare list for plugins
    plugins_list = new QListWidget;
    plugins_list->setHidden(true);
    item = new QListWidgetItem;
    item = 0;

    vlayout = new QVBoxLayout;
    vlayout->addLayout(hlayout1);
    vlayout->addWidget(plugins_list);
    vlayout->addLayout(hlayout2);
}

void QtPluginFinder::plugin_dir()
{
    QString dir_path = QFileDialog::getExistingDirectory(0,"Select Plugin Directory","");
    DirPath->setText(dir_path);
    QDir plugins_Dir = dir_path;
    foreach (QString fileName,plugins_Dir.entryList(QDir::Files)) {
        if (fileName.contains("dll")) item = new QListWidgetItem(fileName, plugins_list);
    }
    plugins_list->show();
    plugin_start_button->show();
}

bool QtPluginFinder::loadPlugin()
{
    QDir plugins_Dir = DirPath->text();
    QString filename = plugins_list->currentItem()->text();
    QPluginLoader pluginLoader(plugins_Dir.absoluteFilePath(filename));
    QObject *plugin = pluginLoader.instance();
        if (plugin) {
            myPluginInterface = qobject_cast<MyPluginInterface *>(plugin);
            if (myPluginInterface)
                return true;
        }
    return false;
}
