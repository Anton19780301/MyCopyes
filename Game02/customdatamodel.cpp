#include "customdatamodel.h"

CustomDataModel::CustomDataModel()
{

}

CustomDataModel::CustomDataModel(bool visible, QString name, int xID, int yID, bool fm) :
    m_visible(visible),
    m_name(name),
    m_xID(xID),
    m_yID(yID),
    m_flagMarker(fm)
{

}

int CustomDataModel::xID() const
{
    return m_xID;
}

void CustomDataModel::setXID(int newXID)
{
    if (m_xID == newXID)
        return;
    m_xID = newXID;
    emit xIDChanged();
}

int CustomDataModel::yID() const
{
    return m_yID;
}

void CustomDataModel::setYID(int newYID)
{
    if (m_yID == newYID)
        return;
    m_yID = newYID;
    emit yIDChanged();
}

QString CustomDataModel::name() const
{
    return m_name;
}

void CustomDataModel::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

bool CustomDataModel::visible() const
{
    return m_visible;
}

void CustomDataModel::setVisible(bool newVisible)
{
    if (m_visible == newVisible)
        return;
    m_visible = newVisible;
    emit visibleChanged();
}

bool CustomDataModel::flagMarker() const
{
    return m_flagMarker;
}

void CustomDataModel::setFlagMarker(bool newFlagMarker)
{
    if (m_flagMarker == newFlagMarker)
        return;
    m_flagMarker = newFlagMarker;
    emit flagMarkerChanged();
}
