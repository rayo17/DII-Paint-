#ifndef SCREEN_H
#define SCREEN_H

#include <QMainWindow>
#include<QPen>

class QMouseEvent;
class QPainter;
class QImage;
class QPen;
namespace Ui {
class Screen;

}

class Screen : public QMainWindow
{
    Q_OBJECT

public:
    explicit Screen(QWidget *parent = nullptr);
    ~Screen();
    int **getMatrix();
    void createScreen(int,int);
  protected:
  void mousePressEvent(QMouseEvent *event)override;
  void mouseMoveEvent(QMouseEvent *event)override;
  void paintEvent(QPaintEvent *event)override;
  void mouseReleaseEvent(QMouseEvent *event)override;


private slots:
  void on_actionSize_triggered();

  void on_actionColor_triggered();

  void on_actionRectangle_triggered();

  void on_actionTringle_triggered();

  void on_actionSquare_triggered();

  void on_actionEraser_triggered();

private:
    Ui::Screen *ui;
    QPainter *painter;
    QImage *img;
    int **matrix;
    QPoint begin;
    QPoint end;
    bool enable;
    int size;
    QColor color;
    QPen pencil;
    QPen eraser;


};

#endif // SCREEN_H
