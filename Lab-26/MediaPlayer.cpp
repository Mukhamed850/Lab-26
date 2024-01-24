#include "MediaPlayer.h"
#include <QGridLayout>
#include <QDebug>
#include <QString>
#include <QLabel>

// Конструктор класса MediaPlayer
MediaPlayer::MediaPlayer(QWidget *parent) : QMainWindow(parent) {
    // Создание главного виджета
    QWidget *mainWidget = new QWidget;
    setCentralWidget(mainWidget);
    // Инициализация переменных
    filename = "";
    this->is_playing = false;
    // Создание и настройка основного макета сетки
    QGridLayout *mainLayout = new QGridLayout;
    line_filename = new QLineEdit;
    QPushButton* button_browse = new QPushButton("Выбрать...");
    button_play = new QPushButton("Воспроизвести");
    media_player = new QMediaPlayer(this);
    line_filename->setEnabled(false);

    // Добавление виджетов на основной макет
    mainLayout->addWidget(line_filename);
    mainLayout->addWidget(button_browse, 0, 1);
    mainLayout->addWidget(button_play, 1, 0, 1, 2);

    // Подключение сигналов к слотам
    connect(button_play, SIGNAL(clicked()), this, SLOT(manipulateFile()));
    connect(button_browse, SIGNAL(clicked()), this, SLOT(openFile()));

    // Установка макета для главного виджета
    mainWidget->setLayout(mainLayout);

    // Установка минимального размера окна
    setMinimumSize(500,100);
}
// Слот для обработки нажатия кнопки "Воспроизвести/Остановить"
void MediaPlayer::manipulateFile() {
    // Проверка, был ли выбран аудиофайл
    if(filename.isEmpty()) {
        line_filename->setText("Выбрать аудиофайл");
        return;
    }

    // Проверка состояния воспроизведения
    if(is_playing) {
        // Если воспроизведение активно, останавливаем и выводим сообщение в консоль
        qDebug() << "Остановка аудиофайла...";
        button_play->setText("Воспроизвести");
        media_player->pause();
    } else {
        // Если воспроизведение неактивно, начинаем воспроизведение и выводим сообщение в консоль
        qDebug() << "Воспроизведение аудиофайла...";
        button_play->setText("Остановить");
        media_player->play();
    }

    // Инвертирование флага состояния воспроизведения
    this->is_playing = !(this->is_playing);
    update();
}
// Слот для обработки нажатия кнопки "Выбрать..."
void MediaPlayer::openFile() {
    // Открытие диалогового окна для выбора аудиофайла
    filename = QFileDialog::getOpenFileName(this, tr("Открыть файл"), "./", tr("Аудиофайлы (*.mp3)"));

    // Отображение выбранного пути в текстовом поле
    line_filename->setText(filename);

    // Преобразование пути файла в URL и установка его в QMediaPlayer
    QUrl file = QUrl::fromLocalFile(filename);
    media_player->setMedia(file);

    // Установка громкости воспроизведения
    media_player->setVolume(80);
}

// Деструктор класса MediaPlayer
MediaPlayer::~MediaPlayer() {}
