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
    painter->drawPixmap(0, 0, m_qrPixmap);


};


QString QtQuickQRCode::qrString() const
{
    return  m_qrString;
}

QColor QtQuickQRCode::backgroundColor() const
{
    return m_backgroundColor;
}

QColor QtQuickQRCode::pixelColor() const
{
    return m_pixelColor;
};

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

void QtQuickQRCode::setPixelColor(const QColor pixelColor)
{
    if (m_pixelColor == pixelColor)
        return;

    m_pixelColor = pixelColor;
    updateQRPixmap();
    update();
    emit pixelColorChanged(pixelColor);

}


void QtQuickQRCode::updateQRPixmap()
{
      QRcode * qrCode = NULL;

     char * sourceString = strdup(m_qrString.toUtf8().data());
     QPixmap newQRPixmap;

     if (qrCode = QRcode_encodeString(sourceString, 0, QR_ECLEVEL_H, QR_MODE_8, 1))
	 {

	    unsigned char * qrData = qrCode->data;
	    QRectF itemRect = this->boundingRect();

	    qreal width = itemRect.width();
	    qreal height = itemRect.height();
	    qreal widthBlockSize;
	    qreal heightBlockSize;
	    if (qrCode->width > 0)
        {
           widthBlockSize = width/qrCode->width;
           heightBlockSize = height/qrCode->width;
	    }




	    std::cout<<"width "<<width<<" height "<<height<<std::endl;

	    newQRPixmap = QPixmap( ((int) width) + 1, ((int)height) + 1 );
	    newQRPixmap.fill(m_backgroundColor);

	    QPainter qrPixmapPainter (&newQRPixmap);
	    qrPixmapPainter.setBrush(QBrush(m_pixelColor));
	    qrPixmapPainter.setPen(QPen(m_pixelColor));

		for(int y = 0; y < qrCode->width; y++)
		{
			for(int x = 0; x < qrCode->width; x++)
			{
				if (*qrData & 1)
				{
				   qrPixmapPainter.drawRect(QRectF(x*widthBlockSize, y*heightBlockSize, widthBlockSize, heightBlockSize));
				}


                qrData++;
			}

		}

		QRcode_free(qrCode);
	} else {
	   //TODO : print error
	   qWarning()<<"QRcode_encodeString result is null";

	};
	m_qrPixmap = newQRPixmap;
    qDebug() << m_qrPixmap.width();

	free(sourceString);



};

void QtQuickQRCode::geometryChanged(const QRectF &newGeometry, const QRectF &oldGeometry)
{
    if (newGeometry.size() != oldGeometry.size())
    {
       updateQRPixmap();
    };

};
