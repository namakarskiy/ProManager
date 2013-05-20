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

void RealTimePlot::getData(int)
{

}

void RealTimePlot::drawPoint(QPointF point)
{
}


