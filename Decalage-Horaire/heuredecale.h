#ifndef HEUREDECALE_H
#define HEUREDECALE_H

#include <QWidget>
#include <QTime>
#include <QTimer>

namespace Ui {
class Heuredecale;
}

class Heuredecale : public QWidget
{
    Q_OBJECT

public:
    explicit Heuredecale(QWidget *parent = nullptr);

    int getOffset() const {return _decalage;}
    void setOffset(int value){ _decalage = value ;};

    QString getVille() const { return _ville; };
    void setVille(QString city){ _ville = city ;};

    ~Heuredecale();

public slots:
    void onChangeValHeure(const QString city, int offset); // Slot pour recevoir le signal sigChangeValHeure
    void updateTime();



private:
    Ui::Heuredecale *ui;
    QTimer *timer;
    int _decalage;
    QString _ville;
};

#endif // HEUREDECALE_H
