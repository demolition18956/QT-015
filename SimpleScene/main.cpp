#include <QtGui>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsTextItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsView>

int main(int argc, char* argv[])
{
	QApplication myApp(argc, argv);
	
	QGraphicsScene myScene(QRect(-100, -100, 400, 300));
	myScene.setBackgroundBrush(QBrush(Qt::lightGray, Qt::SolidPattern));
	
	QGraphicsSimpleTextItem simpletext("Help Me!");
	simpletext.setPen(QPen(Qt::red));
	simpletext.setPos(0,0);
	
	QGraphicsTextItem text("I'm making a scene!");
	text.setDefaultTextColor(Qt::black);
	text.setPos(100,100);
	
	QGraphicsEllipseItem circle(QRect(-50,-50,100,100));
	circle.setPen(QPen(Qt::blue));
	
	myScene.addItem(&simpletext);
	myScene.addItem(&text);
	myScene.addItem(&circle);
	
	QGraphicsView myView;
	myView.setScene(&myScene);
	myView.show();
	
	return myApp.exec();
}
