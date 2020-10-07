#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-200,-150,400,300);
    scene->setBackgroundBrush(Qt::black);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    for (int k = 0; k < 4; k++)
    {
        aliens[k] = new Alien;
        aliens[k]->setPos(-190 + k * 125, -150);
        scene->addItem(aliens[k]);
    }

    QTimer* timer = new QTimer;
    connect(timer,SIGNAL(timeout()), scene, SLOT(advance()));
    timer->setInterval(1000/33);
    timer->start();
}

Dialog::~Dialog()
{
    delete ui;
}
