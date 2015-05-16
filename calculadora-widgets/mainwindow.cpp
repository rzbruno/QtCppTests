#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnDivisao_clicked()
{
    ui->lblResultado->setText(QString::number(ui->spn1->value() / ui->spn2->value()));
}

void MainWindow::on_btnMultiplicacao_clicked()
{
    ui->lblResultado->setText(QString::number(ui->spn1->value() * ui->spn2->value()));
}

void MainWindow::on_btnSubtracao_clicked()
{
    ui->lblResultado->setText(QString::number(ui->spn1->value() - ui->spn2->value()));
}

void MainWindow::on_btnSoma_clicked()
{
    ui->lblResultado->setText(QString::number(ui->spn1->value() + ui->spn2->value()));
}
