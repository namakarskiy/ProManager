#ifndef REALTIMEPLOT_H
#define REALTIMEPLOT_H

#include <QWidget>
#include <QWidget>
#include <QtGui>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>
#include <qwt_plot_directpainter.h>
#include <qwt_series_data.h>
#include <QPointF>

class RealTimePlot : public QwtPlot
{

    Q_OBJECT
private:
        QwtPlotCurve *curve;
        QwtPlotDirectPainter *painter;


public:        
        void drawPoint(QPointF point);
        RealTimePlot();
signals:
    
public slots:
        void getData(int);

    
};

#endif // REALTIMEPLOT_H
