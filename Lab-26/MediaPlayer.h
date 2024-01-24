#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QWidget>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QFileDialog>
#include <QMenuBar>
#include <QPainter>
#include <QLabel>
#include <QMediaPlayer>

class MediaPlayer : public QMainWindow {
    Q_OBJECT
    QMediaPlayer* media_player;
    QString filename;
    QLineEdit* line_filename;
    QPushButton* button_play;
    bool is_playing;

private slots:
    void manipulateFile();
    void openFile();

public:
    MediaPlayer(QWidget *parent = nullptr);
    ~MediaPlayer();
};
#endif // MEDIAPLAYER_H
