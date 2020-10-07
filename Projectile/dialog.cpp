#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);     // turning off indexing to speed up animation
    scene->setSceneRect(-200,-150,400,300);
    scene->setBackgroundBrush(Qt::blue);

    // Config graphics view object
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    // Add projectile to scene
    p1 = new Projectile;
    p1->setPos(-200,-150);
    scene->addItem(p1);

    // Create and configure timer Object
    QTimer* timer = new QTimer;
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->setInterval(1000/33);
    timer->start();
}

Dialog::~Dialog()
{
    delete ui;
}
