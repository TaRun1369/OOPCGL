#include "Assignment_No_6.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include<iostream>
#include<QTimer>
#include<QTime>

using namespace std;
static QImage img(500,500,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ver=0;
    start=true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(start)
    {
        int p=ev->pos().x();
        int q=ev->pos().y();
        a[ver]=p;
        b[ver]=q;

        if(ev->button()==Qt::RightButton)
        {
            dda(a[0],b[0],a[ver-1],b[ver-1]);
            start=false;
        }
        else
        {
            if(ver>0)
            {
                dda(a[ver],b[ver],a[ver-1],b[ver-1]);
            }
        }
        ver++;
    }
}

void MainWindow::dda(int x1, int y1, int x2, int y2)
{
       double dx,dy,x,y,len,xinc,yinc;
       dx=x2-x1;
       dy=y2-y1;
       if(abs(dx)>=abs(dy))
           len=abs(dx);
       else
           len=abs(dy);
       xinc=dx/len;
       yinc=dy/len;
       x=x1;
       y=y1;
       int i=0;
       while(i<len)
       {
           img.setPixel(int(x),int(y),qRgb(255,255,0));
           x=x+xinc;
           y=y+yinc;
           i++;
       }
       ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_clicked()
{
    a[ver]=a[0];
    b[ver]=b[0];
    for(i=0;i<ver;i++)
    {
        dy=b[i+1]-b[i];
        dx=a[i+1]-a[i];
        if(dy==0.0f) slope[i]=1.0;
        if(dx==0.0f) slope[i]=0.0;
        if((dy!=0.0f)&&(dx!=0.0f))
        {
            slope[i]=dx/dy;

        }
    }
    for (int y=0;y<500;y++)
    {
        k=0;
        for(i=0;i<ver;i++)
        {
            if(((b[i]<=y)&&(b[i+1]>y))||((b[i]>y)&&(b[i+1]<=y)))
            {
                xi[k]=int(a[i]+(slope[i]*(y-b[i])));
                k++;
            }
        }
        for (j=0;j<k-1;j++)
            for(i=0;i<k-j-1;i++)
            {
                if(xi[i]>xi[i+1])
                {
                  int temp=xi[i];
                    xi[i]=xi[i+1];
                    xi[i+1]=temp;
                }
            }
        for(i=0;i<k;i+=2)
        {
//            delay(40);
            dda(xi[i],y,xi[i+1]+1,y);
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{

}
