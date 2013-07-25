#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QMessageBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void loadQuestWindow();
    void loadAboutWindow();

private:
    QPushButton *questButton;
    QLabel *titleLabel;
    QMenu *menu;
    QAction *loadAboutWindowAction;

};

#endif // MAINWINDOW_H
