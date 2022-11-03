/* Copyright 2011 Stanislaw Adaszewski. All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are
permitted provided that the following conditions are met:

   1. Redistributions of source code must retain the above copyright notice, this list of
      conditions and the following disclaimer.

   2. Redistributions in binary form must reproduce the above copyright notice, this list
      of conditions and the following disclaimer in the documentation and/or other materials
      provided with the distribution.

THIS SOFTWARE IS PROVIDED BY STANISLAW ADASZEWSKI ``AS IS'' AND ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL STANISLAW ADASZEWSKI OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those of the
authors and should not be interpreted as representing official policies, either expressed
or implied, of Stanislaw Adaszewski. */

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

//
// MainWindow
//

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QInputEventRecorder::nameAllWidgets(ui->widget_3);
    m_Recorder.setObj(ui->widget_3);

    QObject::connect(ui->recordButton, SIGNAL(clicked()), this, SLOT(record()));
    QObject::connect(ui->replayButton, SIGNAL(clicked()), this, SLOT(replay()));
    QObject::connect(ui->stopButton, SIGNAL(clicked()), this, SLOT(stop()));
    QObject::connect(&m_Recorder, SIGNAL(replayDone()), this, SLOT(stop()));

    ui->widget_4->setScene(new QGraphicsScene(ui->widget_4));
    ui->widget_4->setSceneRect(0, 0, ui->widget_4->width(), ui->widget_4->height());
    QObject::connect(ui->clearButton, SIGNAL(clicked()), ui->widget_4->scene(), SLOT(clear()));

    QObject::connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(save()));
    QObject::connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(load()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::record()
{
	m_Recorder.record();
	ui->recordButton->setEnabled(false);
	ui->stopButton->setEnabled(true);
	ui->replayButton->setEnabled(false);
}

void MainWindow::stop()
{
	m_Recorder.stop();
	ui->stopButton->setEnabled(false);
	ui->recordButton->setEnabled(true);
	ui->replayButton->setEnabled(true);
}

void MainWindow::replay()
{
	m_Recorder.replay(10.0f / ui->speedSlider->value());
	ui->replayButton->setEnabled(false);
	ui->stopButton->setEnabled(true);
	ui->recordButton->setEnabled(false);
}

void MainWindow::save()
{
	QString fileName = QFileDialog::getSaveFileName(this);
	if (!fileName.isEmpty())
		m_Recorder.save(fileName);
}

void MainWindow::load()
{
	stop();

	QString fileName = QFileDialog::getOpenFileName(this);
	if (!fileName.isEmpty())
		m_Recorder.load(fileName);
}
