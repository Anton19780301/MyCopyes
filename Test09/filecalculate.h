#ifndef FILECALCULATE_H
#define FILECALCULATE_H

//! класс содержит методы для обработки входящего файла и сбора статистики слов
/*!
@brief класс содержит методы для обработки входящего файла и сбора статистики слов.
       Экземпляр класса всегда создаётся в отдельном потоке, в классе ProgrammActions.
       В классе происходит считывание и анализ содержимого файла, а так же отсылка
       результатов в класс ProgrammActions, для дальнейшей передачи в QML.

    \param[FileCalculate] - конструктор класса, принимет QWaitCondition и мьютекс из класса ProgrammActions
                            для анализа
    \param[raitingRecalculate] - сигнал, передаёт в класс ProgrammActions срез из 15 топовых слов
    \param[maxFileSizeChanged] - сигнал, сообщает в класс ProgrammActions максимальный размер файла
    \param[curentFilePosChanged] - сигнал, сообщает в класс ProgrammActions текущий байт файла
    \param[addFile] - публичный слот, для установки файла по имени
    \param[cancelCalculate] - публичный слот для отмены анализа файла
    \param[pause] - публичный слот, для установки паузы
    \param[startCalculate] - основной метода (реализован как слот). Начинает анализ файла, если таковой выбран.
                             разбивает файл на строки с задрежкой и отправлвет их в метод calculateWords для анализа.
    \param[calculateWords] - один из основных метод - принимает строку, обрабатывает (удаляет нестандартные символы по списку)
                             и разбивает на отдельные слова. Затем вычисляет положение каждого слова в рейтрнге и отсылает срез
                             рейтинга в ProgrammActions для вывода на гистограмму. Так же отправляет в ProgrammActions
                             техническую информацию о файле и процессе анализа.
    \param[removeCharacters] - метод 'удалитель' символов из текста, удаляет по списку remList
    \param[comparatorListWS] - функция компоратор для сортировки списка слов
    \param[predicatListWS] - функция предикат для удаления слов из подсчета
    \param[delList] - список для исключения слов из подсчета. Некторые слова являются таковыми толко технически (пробелы, междометия итд)
    \param[remList] - список для удаления символов в анализируемой строке, эти символы заменяться на пробел и станут разделителем на отдельные слова
    \param[_fileName] - имя выбранного файла, передайтся в экземпляр класса для выбора файла для анализа
    \param[_inputFile] - выбранный файл
    \param[_wc] - QWaitCondition для паузы
    \param[_mx] - мьютекс, для паузы
    \param[_pause] - если истина, то процесс распарсивания файла поставлен на паузу
    \param[_fileSize] - содержит полную длинну файла в байтах, используется для отображения информации в прогресс баре
    \param[_curuentByte] - содержит текущую позицию в файле, используется для отображения информации в прогресс баре
    \param[_wordsData] - содержит абсолютный рейтинг по всем найденным в тексте словам
    \param[_reiting] - содержит срез из первых 15 слов в рейтинге
    \param[RAITING_COUNT] - количество записей в рейтинге, менять не желательно.
*/

#include <QObject>
#include <QFile>

class QTimer;
class QMutex;
class QWaitCondition;
class WordsData;

class FileCalculate : public QObject
{
    Q_OBJECT

public:
    explicit FileCalculate(QWaitCondition *wc, QMutex *mx);

signals:
    void raitingRecalculate(QVector<WordsData*> *reiting);
    void maxFileSizeChanged(int maxsize);
    void curentFilePosChanged(int pos);

public slots:
    void addFile(QString fileName);
    void cancelCalculate();
    void pause(bool pause);
    void startCalculate();

private:
    const int RAITING_COUNT = 15;

    void calculateWords(QString line);
    void removeCharacters(QString &word);
    static bool comparatorListWS(WordsData *a, WordsData *b);
    static bool predicatListWS(const QString &a);
    inline static QStringList delList = {""," ","\n","\t", "\\","и"};
    QStringList remList = {".",",","!",":","-","[","]","(",")"};

    QString _fileName = "";
    QFile _inputFile;
    QWaitCondition *_wc = nullptr;
    QMutex *_mx = nullptr;
    bool _pause = false;
    int _fileSize = 0;
    int _curuentByte = 0;

    QVector<WordsData*> _wordsData = {};
    QVector<WordsData*> *_reiting = new QVector<WordsData*>();
};

#endif // FILECALCULATE_H
