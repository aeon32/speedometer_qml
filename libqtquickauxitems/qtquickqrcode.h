#ifndef QTQUICKQRCODE_H
#define QTQUICKQRCODE_H

#include <QtQuick/QQuickPaintedItem>
 #include <QColor>
#include <QBrush>
#include <QPen>
#include <QPainter>


class QtQuickQRCode : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString qrString READ qrString WRITE setQRString NOTIFY qrStringChanged)
    Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor NOTIFY backgroundColorChanged)

public:
    explicit QtQuickQRCode (QQuickItem *parent = 0);

    void paint(QPainter *painter) override;

    QString qrString() const;
    QColor backgroundColor() const;

public slots:
    void setQRString(const QString qrString);
    void setBackgroundColor(const QColor backgroundColor);


signals:
    void qrStringChanged(const QString qrString);
    void backgroundColorChanged(const QColor backgroundColor);


private:
    QString     m_qrString;
    QColor m_backgroundColor;

    QPixmap m_qrPixmap;


    void updateQRPixmap();
};


#endif
