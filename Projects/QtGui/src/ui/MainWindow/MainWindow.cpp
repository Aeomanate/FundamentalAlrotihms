#include "MainWindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include <FundamentalAlgorithms.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnTest, &QPushButton::clicked, this, &MainWindow::OnClick);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnClick()
{
    QString s = QString::number(FundamentalAlgorithms::Ret1());
    ui->btnTest->setText(s);
}
