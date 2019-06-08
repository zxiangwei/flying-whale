#ifndef DIALOG_H
#define DIALOG_H
#include <ctime>
#include <string>
#include <QDialog>
#include <QString>
#include <QKeyEvent>
using std::to_string;
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
private:
    Ui::Dialog *ui;
    virtual void keyPressEvent(QKeyEvent*);
};
#endif // DIALOG_H
