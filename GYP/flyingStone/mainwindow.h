#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_actionhelp_triggered();

    void on_actionthe_story_of_whale_triggered();

private:
    Ui::MainWindow *ui;
//protected:
    //virtual void keyPressEvent(QKeyEvent*);
};

#endif // MAINWINDOW_H
