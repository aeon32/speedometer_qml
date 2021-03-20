/***************************************************************************
**                                                                        **
**  QCodesysNV, a QT C++ library for communication                        **
**  with CODESYS network variable UDP protocol.                           **
**                                                                        **
**  Copyright (C) 2015-2016 Jani Komppula                                 **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
**                                                                        **
****************************************************************************
**           Author: Jani Komppula                                        **
**                   jani.komppula@gmail.com                              **
**             Date: 11.02.2016                                           **
**          Version: 0.6                                                  **
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

#include <libqrencode/qrencode.h>
#include <QPixmap>
#include <QPainter>

using namespace std;

namespace qrcodetest {




	MainWindow::MainWindow(QWidget *parent) :
		QMainWindow(parent),
		ui(new Ui::MainWindow)
	{
		ui->setupUi(this);

		//makes pointers to NULL
		//remember this!

	}

	MainWindow::~MainWindow()
	{

		delete ui;
	}

	//writes data to logfile if file is open and check box is checked
	//function call in MainWindow::dataAvailable()
	//see connection in MainWindow::MainWindow
	void MainWindow::on_showQR_clicked()
    {

     QRcode * qrCode = NULL;
     char * sourceString = "Вася";
     QPixmap qrPixmap;

     const int QR_BLOCK_SIZE = 10;


     if (qrCode = QRcode_encodeString(sourceString, 0, QR_ECLEVEL_H, QR_MODE_8, 1))
	 {
	    unsigned char * qrData = qrCode->data;

	    qrPixmap = QPixmap(qrCode->width * QR_BLOCK_SIZE, qrCode->width * QR_BLOCK_SIZE);
	    qrPixmap.fill(Qt::white);

	    QPainter qrPixmapPainter (&qrPixmap);
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
		ui->qrLabel->setPixmap(qrPixmap);

		QRcode_free(qrCode);
	};


   }; //MainWindow::on_showQR_clicked()





};
