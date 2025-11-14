#include "mainwindow.h"
#include "dialogwithbutton.h"

#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , firstFormButton(nullptr)
{
    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);

    firstFormButton = new QPushButton("Open dialog", this);
    layout->addWidget(firstFormButton, 0, Qt::AlignCenter);

    invokableDilaog = new DialogWithButton(this);

    connect(firstFormButton, &QPushButton::clicked, invokableDilaog, &QDialog::show);

    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow() {}
