#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>

class StartWindow : public QWidget
{
    Q_OBJECT
public:
    explicit StartWindow(QWidget *parent = nullptr);

signals:
    void startGame(QString name, QString surname, int age, QString gender);

private:
    QLineEdit *nameEdit;
    QLineEdit *surnameEdit;
    QLineEdit *ageEdit;
    QComboBox *genderBox;
    QPushButton *startBtn;
};

#endif // STARTWINDOW_H
