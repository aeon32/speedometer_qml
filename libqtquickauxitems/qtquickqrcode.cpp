#include "qtquickqrcode.h"


#include <libqrencode/qrencode.h>

#include <iostream>

const int QR_BLOCK_SIZE = 10;

QtQuickQRCode::QtQuickQRCode(QQuickItem *parent) :
    QQuickPaintedItem(parent),
    m_backgroundColor(Qt::white)

{


    updateQRPixmap();
    update();


}

void QtQuickQRCode::paint(QPainter *painter)
{
    // Отрисовка объекта

    QBrush  brush(m_backgroundColor);               // выбираем цвет фона, ...
    painter->setBrush(brush);

    painter->fillRect(boundingRect(), brush);
    painter->drawPixmap(20, 20, m_qrPixmap);


};


QString QtQuickQRCode::qrString() const
{
    return  m_qrString;
}

QColor QtQuickQRCode::backgroundColor() const
{
    return m_backgroundColor;
}


void QtQuickQRCode::setQRString(const QString qrString)
{
    if (this->m_qrString == qrString)
        return;


    this->m_qrString = qrString;


    updateQRPixmap();
    update();
    emit qrStringChanged(qrString);
}

void QtQuickQRCode::setBackgroundColor(const QColor backgroundColor)
{
    if (m_backgroundColor == backgroundColor)
        return;

    m_backgroundColor = backgroundColor;
    updateQRPixmap();
    update();
    emit backgroundColorChanged(backgroundColor);

}


void QtQuickQRCode::updateQRPixmap()
{
      QRcode * qrCode = NULL;

      char * sourceString = strdup(m_qrString.toUtf8().data());


     if (qrCode = QRcode_encodeString(sourceString, 0, QR_ECLEVEL_H, QR_MODE_8, 1))
	 {
	    QPixmap newQRPixmap;
	    unsigned char * qrData = qrCode->data;



	    newQRPixmap = QPixmap(qrCode->width * QR_BLOCK_SIZE, qrCode->width * QR_BLOCK_SIZE);
	    newQRPixmap.fill(m_backgroundColor);

	    QPainter qrPixmapPainter (&newQRPixmap);
	    qrPixmapPainter.setBrush(QBrush(Qt::black));
	    qrPixmapPainter.setPen(QPen(Qt::black));

		for(int y = 0; y < qrCode->width; y++)
		{
			for(int x = 0; x < qrCode->width; x++)
			{
				if (*qrData & 1)
				{
				   qrPixmapPainter.drawRect(x*QR_BLOCK_SIZE, y*QR_BLOCK_SIZE, QR_BLOCK_SIZE, QR_BLOCK_SIZE);
				}


                qrData++;
			}

		}

		m_qrPixmap = newQRPixmap;
		QRcode_free(qrCode);
	} else {
	   //TODO : print error
	   std::cout<<"error 1"<<std::endl;
	};

	free(sourceString);





};
