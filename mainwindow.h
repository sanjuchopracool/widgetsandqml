#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QQuickItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void changeWidth(int inWidth);

private:
    Ui::MainWindow *ui;
    QWidget*    mWidget = nullptr;
    QQuickItem* mitem = nullptr;
};

#endif // MAINWINDOW_H
