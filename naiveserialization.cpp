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

//
// Save
//

/* quint32 evSize;
quint32 evCls;

if (dynamic_cast<QContextMenuEvent*>(ev)) {
	evSize = sizeof(QContextMenuEvent);
	evCls = 1;
} else if (dynamic_cast<QKeyEvent*>(ev)) {
	evSize = sizeof(QKeyEvent);
	evCls = 2;
} else if (dynamic_cast<QMouseEvent*>(ev)) {
	evSize = sizeof(QMouseEvent);
	evCls = 3;
} else if (dynamic_cast<QTabletEvent*>(ev)) {
	evSize = sizeof(QTabletEvent);
	evCls = 4;
} else if (dynamic_cast<QTouchEvent*>(ev)) {
	evSize = sizeof(QTouchEvent);
	evCls = 5;
} else if (dynamic_cast<QWheelEvent*>(ev)) {
	evSize = sizeof(QWheelEvent);
	evCls = 6;
}

ds << evSize;
ds << evCls;
ds.writeBytes((char*) ev, evSize); */

//
// Load
//

/* quint32 evSize, evCls;

ds >> evSize >> evCls;
char *tmp;
ds.readBytes(tmp, evSize);
QEvent *ev;
switch (evCls)
{
case 1: ev = new QContextMenuEvent(*((QContextMenuEvent*) tmp)); break;
case 2: ev = new QKeyEvent(*((QKeyEvent*) tmp)); break;
case 3: ev = new QMouseEvent(*((QMouseEvent*) tmp)); break;
case 4: ev = new QTabletEvent(*((QTabletEvent*) tmp)); break;
case 5: ev = new QTouchEvent(*((QTouchEvent*) tmp)); break;
case 6: ev = new QWheelEvent(*((QWheelEvent*) tmp)); break;
}
delete [] tmp; */
