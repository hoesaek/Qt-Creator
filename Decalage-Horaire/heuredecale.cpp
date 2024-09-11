#include "heuredecale.h"
#include "ui_heuredecale.h"

Heuredecale::Heuredecale(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Heuredecale)
    , _ville("Narnia")
{
    ui->setupUi(this);
    ui->teVilleOffset->setText(getVille()); //valeur par defaut
    timer = new QTimer(this);
    // Connecter le QTimer pour appeler updateTime() toutes les secondes
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    // Démarrer le timer (1 seconde = 1000 ms)
    timer->start(1000);

    // Afficher l'heure immédiatement au démarrage
    updateTime();
}

Heuredecale::~Heuredecale()
{
    delete ui;
}



void Heuredecale::onChangeValHeure(QString city, int offset){
    this->setOffset(offset);
    this->setVille(city);

    ui->teVilleOffset->setText(getVille()); //màj avec info recu du signal
    ui->teOffset->setText("UTC" + QString::number(getOffset()));
}



void Heuredecale::updateTime() {
    // Obtention de l'heure actuelle
    QTime currentTime = QTime::currentTime();

    // Calcul du décalage total en heures et minutes
    int offsetHours = getOffset(); // Décalage en heures

    // Ajustement de l'heure actuelle en fonction du décalage
    QTime adjustedTime = currentTime.addSecs(offsetHours * 3600);

    // Extraction des heures, minutes et secondes ajustées
    int hours = adjustedTime.hour();
    int minutes = adjustedTime.minute();
    int secondes = adjustedTime.second();

    // Affichage des heures, minutes et secondes sur les QLCDNumber
    ui->lcdheures->display(hours);
    ui->lcdminutes->display(minutes);
    ui->lcdsecondes->display(secondes);
}
