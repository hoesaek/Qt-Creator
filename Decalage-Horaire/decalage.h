#ifndef DECALAGE_H
#define DECALAGE_H

#include <QWidget>
#include <QString>

namespace Ui {
class decalage;
}

class decalage : public QWidget
{
    Q_OBJECT

public:
    explicit decalage(QWidget *parent = nullptr);
    ~decalage();
    int getDecalage() const { return _hdecal; }; // méthode pour obtenir le décalage
    //void setDecalage(int value) { _hdecal = value; };
private slots:
    void on_comboBox_currentIndexChanged(int index);
    void on_pushButton_clicked();
    int dacalageConvertion(int value);
signals:
    void sigChangeValHeure(QString ville ,int value);

private:
    Ui::decalage *ui;
    const char* villes[25];
    int _hdecal; //heure decaler
    static const int deca = 12;  // Constante pour le décalage
};

#endif // DECALAGE_H
