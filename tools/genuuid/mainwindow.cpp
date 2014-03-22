#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QUuid>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect button signal to appropriate slot
    connect(ui->pushButton, SIGNAL(released()), this, SLOT(OnGenUuid()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::OnGenUuid()
{
    ui->lineEdit->setText(QUuid::createUuid().toString());
}
