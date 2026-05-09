#include "startwindow.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QIntValidator>

StartWindow::StartWindow(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *nameLabel = new QLabel("Անուն", this);
    nameEdit = new QLineEdit(this);
    layout->addWidget(nameLabel);
    layout->addWidget(nameEdit);

    QLabel *surnameLabel = new QLabel("Ազգանուն", this);
    surnameEdit = new QLineEdit(this);
    layout->addWidget(surnameLabel);
    layout->addWidget(surnameEdit);

    QLabel *ageLabel = new QLabel("Տարիք", this);
    ageEdit = new QLineEdit(this);
    ageEdit->setValidator(new QIntValidator(1, 120, this));
    layout->addWidget(ageLabel);
    layout->addWidget(ageEdit);

    QLabel *genderLabel = new QLabel("Սեռ", this);
    genderBox = new QComboBox(this);
    genderBox->addItem("Տղա");
    genderBox->addItem("Աղջիկ");
    layout->addWidget(genderLabel);
    layout->addWidget(genderBox);

    startBtn = new QPushButton("Սկսել խաղը", this);
    layout->addWidget(startBtn);

    connect(startBtn, &QPushButton::clicked, this, [this](){
        QString name = nameEdit->text();
        QString surname = surnameEdit->text();
        int age = ageEdit->text().toInt();
        QString gender = genderBox->currentText();
        emit startGame(name,surname,age,gender);
    });
}
