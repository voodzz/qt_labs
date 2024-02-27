#include<QtWidgets>

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    QLabel* lbl = new QLabel("Hello World!");
    lbl->show();
    return app.exec();
}
