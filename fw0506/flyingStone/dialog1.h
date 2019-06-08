#ifndef DIALOG1_H
#define DIALOG1_H
#include <string>
#include <ctime>
#include <QString>
#include <QDialog>
#include <QKeyEvent>
using std::to_string;
namespace Ui
{
    class Dialog1;
}
class Dialog1 : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog1(clock_t t,QWidget *parent = 0);
    ~Dialog1();
private:
    Ui::Dialog1 *ui;
    virtual void keyPressEvent(QKeyEvent*);
};
#endif // DIALOG1_H
