#ifndef DIALOG1_H
#define DIALOG1_H
#include <QKeyEvent>
#include <QDialog>

namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = 0);
    ~Dialog1();

private:
    Ui::Dialog1 *ui;
protected:
    virtual void keyPressEvent(QKeyEvent*);
};

#endif // DIALOG1_H
