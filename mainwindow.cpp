#include "mainwindow.h"
#include "questwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    loadAboutWindowAction = new QAction(tr("&About"), this);
    questButton = new QPushButton(tr("Edit Quests"));
    titleLabel = new QLabel(this);

    titleLabel->setText("This program is used to generate database code to import into a Mangos database.");

    connect(questButton, SIGNAL(clicked()), this,SLOT(loadQuestWindow()));
    connect(loadAboutWindowAction, SIGNAL(triggered()), this, SLOT(loadAboutWindow()));

    //Menu
    menu = menuBar()->addMenu(tr("&Help"));
    menu->addAction(loadAboutWindowAction);

    QWidget *buttonWidget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(titleLabel);
    layout->addWidget(questButton);

    buttonWidget->setLayout(layout);
    setCentralWidget(buttonWidget);
    setWindowTitle("Mangos Database Editor - Main Window");
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::loadQuestWindow(){
    QuestWindow *q = new QuestWindow();

    q->show();
}

void MainWindow::loadAboutWindow(){
    QMessageBox aboutBox;

    aboutBox.setText(tr("Version: 1.0a\n\nThis program is designed to speed up the creation of Quests, Mobs and Items.\n\nCreated By: bels"));
    aboutBox.setStandardButtons(QMessageBox::Cancel);
    aboutBox.exec();

}
