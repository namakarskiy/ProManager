#include "realtimeplot.h"

RealTimePlot::RealTimePlot()
{
        //counter = 0;
        painter = new QwtPlotDirectPainter(this);
        this->setFixedHeight(100);
        this->setFixedWidth(400);
        this->setAxisScale(QwtPlot::xBottom, 0, 0);
        this->setAxisScale(QwtPlot::yLeft, 0, 1000);
}

void RealTimePlot::getData(int used)
{
   /*  double elapsed = (this -> dclock_elapsed());
     QPoint point(elapsed,used); //формируем точку
     this->appendPoint(point);//добавляем точку к кривой*/
}

void RealTimePlot::appendPoint(QPoint point)
{

}


