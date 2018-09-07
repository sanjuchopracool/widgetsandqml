#include <QQuickView>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    connect(ui->pushButton, SIGNAL(clicked()), qApp, SLOT(quit()));

    QQuickView *view = new QQuickView();
    QWidget *container = QWidget::createWindowContainer(view, this);
    container->setFocusPolicy(Qt::TabFocus);
    view->setSource(QUrl("qrc:/main.qml"));
    ui->horizontalLayout->insertWidget(0, container);
    mitem = view->rootObject();
    container->setMinimumWidth(mitem->implicitWidth());
    ui->horizontalLayout->setMargin(0);
    ui->horizontalLayout->setSpacing(0);

    mWidget = container;

//    QTimer* timer = new QTimer(this);
//    timer->setInterval(2000);
//    connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));
//    timer->start();

    connect(mitem, SIGNAL(widthChanged(int)), this, SLOT(changeWidth(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeWidth(int inWidth)
{
    mWidget->setFixedWidth(inWidth);
}
