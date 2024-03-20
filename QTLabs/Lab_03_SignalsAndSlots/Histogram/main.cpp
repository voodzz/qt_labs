#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QHorizontalBarSeries>
#include <QVector>
#include <QRandomGenerator>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QVector<int> data(QRandomGenerator::global()->bounded(5, 20));
    for (int i = 0; i < data.size(); ++i) {
        data[i] = QRandomGenerator::global()->bounded(0, 100);
    }

    QVector<QBarSet*> barSets(data.size());
    for (int i = 0; i != barSets.size(); ++i) {
        QString number = "#";
        number += QString::fromStdString(std::to_string(i));
        barSets[i] = new QBarSet(number);
    }

    for (auto& set : barSets) {
        // set->setColor(QColor(QRandomGenerator::global()->bounded(0, 255), QRandomGenerator::global()->bounded(0, 255), QRandomGenerator::global()->bounded(0, 255)));
        set->setBrush(QBrush(QColor(QRandomGenerator::global()->bounded(0, 255),
                                                  QRandomGenerator::global()->bounded(0, 255),
                                                  QRandomGenerator::global()->bounded(0, 255)), Qt::BrushStyle(QRandomGenerator::global()->bounded(1,14))));
        set->setBorderColor(QColor(5, 5, 5));
    }

    int i = 0;
    for (auto& set : barSets) {
        (*set) << data[i];
        ++i;
    }

    QHorizontalBarSeries *series = new QHorizontalBarSeries();
    for (auto& set : barSets) {
        series->append(set);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Simple horizontal histogram");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "array";
    QBarCategoryAxis *axisY = new QBarCategoryAxis();
    axisY->append(categories);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    QValueAxis *axisX = new QValueAxis();
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    axisX->applyNiceNumbers();

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(1280, 720);
    window.show();

    return a.exec();
}
