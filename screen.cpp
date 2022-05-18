#include "screen.h"
#include "ui_screen.h"
#include<QDebug>
#include<QMouseEvent>
#include<QPainter>
#include<QImage>
#include<QPen>
#include<QDesktopServices>
#include<QColorDialog>
#include<QInputDialog>

Screen::Screen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Screen)
{
   ui->setupUi(this);
   enable=false;
   //color=QColor(Qt::black);
  // size=5;
  //Create matrix where each element will be a pixel value.
 //qDebug()<<"matrix"<<**matrix;
}

Screen::~Screen()
{
    delete ui;
    delete painter;
    delete img;


}

void Screen::createScreen(int x, int y){
    img=new QImage(x,y,QImage::Format_ARGB32_Premultiplied);
    painter=new QPainter(img);
    painter->fillRect(img->rect(),Qt::white);
}
