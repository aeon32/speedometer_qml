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
    Q_PROPERTY(QColor pixelColor READ pixelColor WRITE setPixelColor NOTIFY pixelColorChanged)

public:
    explicit QtQuickQRCode (QQuickItem *parent = 0);

    void paint(QPainter *painter) override;

    QString qrString() const;
    QColor backgroundColor() const;
    QColor pixelColor() const;

public slots:
    void setQRString(const QString qrString);
    void setBackgroundColor(const QColor backgroundColor);
    void setPixelColor(const QColor pixelColor);


signals:
    void qrStringChanged(const QString qrString);
    void backgroundColorChanged(const QColor backgroundColor);
    void pixelColorChanged(const QColor pixelColor);


private:
    QString     m_qrString;
    QColor m_backgroundColor;
    QColor m_pixelColor;

    QPixmap m_qrPixmap;


    void updateQRPixmap();

protected:
    virtual void geometryChanged(const QRectF &newGeometry, const QRectF &oldGeometry);
};


#endif
