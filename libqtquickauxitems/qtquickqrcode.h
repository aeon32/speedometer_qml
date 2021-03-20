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

public:
    explicit ClockCircle(QQuickItem *parent = 0);

    void paint(QPainter *painter) override; // Переопределяем метод, в котором будет отрисовываться наш объект

    QString qrString() const;

public slots:
    void setQRString(const QString name);
    void setBackgroundColor(const QColor backgroundColor);
    void setBorderActiveColor(const QColor borderActiveColor);
    void setBorderNonActiveColor(const QColor borderNonActiveColor);
    void setAngle(const qreal angle);
    void setCircleTime(const QTime circleTime);

signals:
    void cleared();

    void nameChanged(const QString name);
    void backgroundColorChanged(const QColor backgroundColor);
    void borderActiveColorChanged(const QColor borderActiveColor);
    void borderNonActiveColorChanged(const QColor borderNonActiveColor);
    void angleChanged(const qreal angle);
    void circleTimeChanged(const QTime circleTime);

private:
    QString     m_name;                 // Название объекта, по большей части до кучи добавлено
    QColor      m_backgroundColor;      // Основной цвет фона
    QColor      m_borderActiveColor;    // Цвет ободка, заполняющий при прогрессе ободок таймера
    QColor      m_borderNonActiveColor; // Цвет ободка фоновый
    qreal       m_angle;                // Угол поворота графика типа пирог, будет формировать прогресс на ободке
    QTime       m_circleTime;           // Текущее время таймера

    QTimer      *internalTimer;         // Таймер, по которому будет изменяться время
};
