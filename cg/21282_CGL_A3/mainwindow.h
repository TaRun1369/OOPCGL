#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *event);
    void DDA1(int x1,int y1,int x2,int y2,int color);
    void DDA(int x1,int y1,int x2,int y2,int color);
    void cohen_sutherland_clip(int x1, int y1 , int x2, int y2 );
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    int a[10],b[10],ver,j,temp,k,i,xi[20];
    float slope[10],dx,dy;
    bool start;
};
#endif // MAINWINDOW_H
