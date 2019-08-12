#include <QApplication>
#include <QDebug>
#include <iostream>
#include "viewer.h"

int main(int argc, char* argv[]) {
  if ((argc != 2)&&(argc != 4)) {
    qDebug() << "usage: viewer <port number> <resolutionx> <resolutiony>";
    return 1;
  }
  QApplication a(argc, argv);
  unsigned short clientPort = (unsigned short)atoi(argv[1]);
  Viewer viewer(clientPort);
  if (argc>3)
  {
  	viewer.resize((unsigned short)atoi(argv[2]), (unsigned short)atoi(argv[3]));
  }else
  {
  	viewer.resize(512, 512);
  }
  viewer.create();
  viewer.show();

  return a.exec();
}
