#ifndef CUSTOMDATAMODEL_H
#define CUSTOMDATAMODEL_H

#include <QObject>
#include <QQmlEngine>

class CustomDataModel : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(bool visible READ visible WRITE setVisible NOTIFY visibleChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int xID READ xID WRITE setXID NOTIFY xIDChanged)
    Q_PROPERTY(int yID READ yID WRITE setYID NOTIFY yIDChanged)
    Q_PROPERTY(bool flagMarker READ flagMarker WRITE setFlagMarker NOTIFY flagMarkerChanged)

public:
    explicit CustomDataModel();
    explicit CustomDataModel(bool visible, QString name, int xID, int yID, bool fm);

    int xID() const;
    void setXID(int newXID);

    int yID() const;
    void setYID(int newYID);

    QString name() const;
    void setName(const QString &newName);

    bool visible() const;
    void setVisible(bool newVisible);

    bool flagMarker() const;
    void setFlagMarker(bool newFlagMarker);

signals:
    void xIDChanged();
    void yIDChanged();
    void nameChanged();
    void visibleChanged();

    void flagMarkerChanged();

private:
    bool m_visible = true;
    int m_xID = 0;
    int m_yID = 0;
    QString m_name = "";
    bool m_flagMarker = false;
};

Q_DECLARE_METATYPE(CustomDataModel)

#endif // CUSTOMDATAMODEL_H
