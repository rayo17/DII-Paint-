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
   color=QColor(Qt::black);
   size=5;

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


//eventos de la pantalla para dibujar
void Screen::paintEvent(QPaintEvent *event){

    enable=true;
    QPainter painter2(this);


    painter2.drawImage(0,0,*img);
    event->accept();
}
void Screen::mousePressEvent(QMouseEvent *event){
    qDebug()<<event->pos();
    int x=event->pos().x();
   int y=event->pos().y();
    matrix[x][y]=qGray(img->pixel(x,y));

   qDebug()<<"("<<x<<","<<y<<")"<<"color"<<matrix[x][y];
    enable=true;
    begin=event->pos();
    event->accept();

}
void Screen::mouseMoveEvent(QMouseEvent *event){

    qDebug()<<event->pos();


    if(!enable){

        event->accept();
        return;
    }
    else{
        pencil.setColor(color);
        pencil.setCapStyle(Qt::RoundCap);
        pencil.setWidth(size);
        end=event->pos();
        int x=event->pos().x();
       int y=event->pos().y();
        matrix[x][y]=qGray(img->pixel(x,y));

       qDebug()<<"("<<x<<","<<y<<")"<<"color"<<matrix[x][y];

        painter->setPen(pencil);

        painter->drawLine(begin,end);
        begin=end;
        update();
        event->accept();
    }
}
void Screen::mouseReleaseEvent(QMouseEvent *event){
    enable=false;

    event->accept();
}
int **Screen::getMatrix(){
    matrix = new int *[img->width()];
      for(int i=0;i<img->width();++i){
        matrix[i] = new int [img->height()];
      }

     for(int i=0;i<img->width();++i){
         for(int j=0;j<img->height();++j){
             matrix[i][j]=qGray(img->pixel(i,j));
          //   qDebug()<<"("<<i<<","<<j<<")"<<"color"<<**matrix;
             //Less than 127 = 1.


                   }
            }
      return matrix;
}

