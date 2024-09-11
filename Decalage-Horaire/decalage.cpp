#include "decalage.h"
#include "ui_decalage.h"

#include "heuredecale.h"

decalage::decalage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::decalage)
    , _hdecal(12)
{
    ui->setupUi(this);
    villes[0] = "Baker Island (non habitée)"; // UTC-12
    villes[1] = "Pago Pago (Samoa Américaines)"; // UTC-11
    villes[2] = "Honolulu (Hawaï, États-Unis)"; // UTC-10
    villes[3] = "Anchorage (Alaska, États-Unis)"; // UTC-9
    villes[4] = "Los Angeles (Californie, États-Unis)"; // UTC-8
    villes[5] = "Denver (Colorado, États-Unis)"; // UTC-7
    villes[6] = "Mexico City (Mexique)"; // UTC-6
    villes[7] = "New York (États-Unis), Toronto (Canada)"; // UTC-5
    villes[8] = "Caracas (Venezuela), La Paz (Bolivie)"; // UTC-4
    villes[9] = "Buenos Aires (Argentine), São Paulo (Brésil)"; // UTC-3
    villes[10] = "Îles Géorgie du Sud (territoire britannique)"; // UTC-2
    villes[11] = "Açores (Portugal)"; // UTC-1
    villes[12] = "Londres (Royaume-Uni), Reykjavik (Islande)"; // UTC±0
    villes[13] = "Paris (France), Berlin (Allemagne)";  // UTC+1
    villes[14] = "Le Caire (Égypte), Athènes (Grèce)"; // UTC+2
    villes[15] = "Moscou (Russie), Riyad (Arabie Saoudite)"; // UTC+3
    villes[16] = "Dubaï (Émirats Arabes Unis), Bakou (Azerbaïdjan)"; // UTC+4
    villes[17] = "Islamabad (Pakistan), Tachkent (Ouzbékistan)"; // UTC+5
    villes[18] = "Almaty (Kazakhstan), Dhaka (Bangladesh)"; // UTC+6
    villes[19] = "Bangkok (Thaïlande), Hô Chi Minh Ville (Vietnam)"; // UTC+7
    villes[20] = "Pékin (Chine), Singapour (Singapour)"; // UTC+8
    villes[21] = "Tokyo (Japon), Séoul (Corée du Sud)";  // UTC+9
    villes[22] = "Sydney (Australie), Vladivostok (Russie)"; // UTC+10
    villes[23] = "Nouméa (Nouvelle-Calédonie), Honiara (Îles Salomon)"; // UTC+11
    villes[24] = "Suva (Fidji), Tarawa (Kiribati)";     // UTC+12
    ui->lblVille->setText(villes[0]);
}

decalage::~decalage()
{
    delete ui;
}

void decalage::on_comboBox_currentIndexChanged(int index)
{
    ui->lblVille->setText(villes[index]);
    _hdecal = dacalageConvertion(index);
}

int decalage::dacalageConvertion(int value)
{
    if (value < 0 || value > 24) return -999;
    return  value - deca;
}

void decalage::on_pushButton_clicked()
{
    Heuredecale *fen = new Heuredecale;
    connect(this, &decalage::sigChangeValHeure, fen, &Heuredecale::onChangeValHeure);
    emit sigChangeValHeure(ui->lblVille->text(), this->getDecalage());
    fen->show();
    this->close();
}

