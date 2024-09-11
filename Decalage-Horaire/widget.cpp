#include "widget.h"
#include "./ui_widget.h"

#include "decalage.h"

#include <QTime>


Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    //ui->lbVille->setVisible(false);
    //ui->lbDecalage->setVisible(false);
    //ui->label->setVisible(false);
    //ui->label_2->setVisible(false);
    // Connecter le QTimer pour appeler updateTime() toutes les secondes
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    // Démarrer le timer (1 seconde = 1000 ms)
    timer->start(1000);
    // Afficher l'heure immédiatement au démarrage
    updateTime();
}

Widget::~Widget()
{
    delete ui;
    delete timer;
}

void Widget::updateTime(){
    // Obtenir l'heure actuelle du système
    QTime currentTime = QTime::currentTime();

    // Mettre à jour les QSpinBox avec l'heure actuelle
    ui->sBheure->setValue(currentTime.hour()); //Configure la valeur de QSpinBox sBheure
    ui->sBminutes->setValue(currentTime.minute()); //Configure la valeur de QSpinBox sBminutes
    ui->sBsecondes->setValue(currentTime.second()); //Configure la valeur de QSpinBox sBsecondes
}

void Widget::on_pBsethours_clicked()
{
    decalage *fen1 = new decalage;
    fen1->show();
}


void Widget::on_pushButton_clicked()
{

}

