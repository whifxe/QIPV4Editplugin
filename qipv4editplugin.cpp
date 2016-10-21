#include "qipv4edit.h"
#include "qipv4editplugin.h"

#include <QtPlugin>

QIPV4EditPlugin::QIPV4EditPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void QIPV4EditPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool QIPV4EditPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *QIPV4EditPlugin::createWidget(QWidget *parent)
{
    return new QIPV4Edit(parent);
}

QString QIPV4EditPlugin::name() const
{
    return QLatin1String("QIPV4Edit");
}

QString QIPV4EditPlugin::group() const
{
    return QLatin1String("Input Widgets");
}

QIcon QIPV4EditPlugin::icon() const
{
    return QIcon(QLatin1String(":/32IP.png"));
}

QString QIPV4EditPlugin::toolTip() const
{
    return QLatin1String("");
}

QString QIPV4EditPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool QIPV4EditPlugin::isContainer() const
{
    return false;
}

QString QIPV4EditPlugin::domXml() const
{
    return QLatin1String("<widget class=\"QIPV4Edit\" name=\"qIPV4Edit\">\n</widget>\n");
}

QString QIPV4EditPlugin::includeFile() const
{
    return QLatin1String("qipv4edit.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(qipv4editplugin, QIPV4EditPlugin)
#endif // QT_VERSION < 0x050000
