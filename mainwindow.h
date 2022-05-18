#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMouseEvent>
#include<canvas.h>
#include"screen.h"
//class QImage;
//class QPainter;
class Screen;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:

private slots:
    void on_create_clicked();

    void on_actionsize_triggered();

    void on_actioncolor_triggered();

private:
    Ui::MainWindow *ui;
   // QPainter *painter;
    //QImage *imag;
    Screen *canvas;
};
#endif // MAINWINDOW_H
