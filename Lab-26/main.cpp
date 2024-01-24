#include "MediaPlayer.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MediaPlayer player;
    player.show();
    return a.exec();
}
