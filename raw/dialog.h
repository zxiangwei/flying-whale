#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <ctime>

namespace Ui
{
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(clock_t t,QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
