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

#include "canvaswidget.h"

#include <QMouseEvent>
#include <QGraphicsItem>

CanvasWidget::CanvasWidget(QWidget *parent):
	QGraphicsView(parent)
{
}

void CanvasWidget::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_Mode = Drawing;
		m_LastPoint = mapToScene(event->pos());
	} else
	if (event->button() == Qt::RightButton)
	{
		m_Mode = Removing;
	}
}

void CanvasWidget::mouseReleaseEvent(QMouseEvent *event)
{
	m_Mode = None;
}

void CanvasWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (scene())
	{
		if (m_Mode == Drawing)
		{
			QPointF pt(mapToScene(event->pos()));
			scene()->addLine(QLineF(m_LastPoint, pt), QPen(Qt::red));
			m_LastPoint = pt;
		} else
		if (m_Mode == Removing)
		{
			QGraphicsItem *item = itemAt(event->pos());
			if (item)
			{
				scene()->removeItem(item);
				delete item;
			}
		}
	}
}