#include "dialogwithbutton.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QApplication>

DialogWithButton::DialogWithButton(QWidget* parent)
    : QDialog(parent)
    , createFileButton(nullptr)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    createFileButton = new QPushButton("Create file", this);
    layout->addWidget(createFileButton, 0, Qt::AlignCenter);

    connect(createFileButton, &QPushButton::clicked, this, &DialogWithButton::ButtonClicked);
}

void DialogWithButton::ButtonClicked()
{
    QFile file("output.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << "Миру мир!";
        file.close();
    }
    else
    {
        QMessageBox::warning(this, "Error", "Failed to create file.");
    }

    close();

    QApplication::quit();
}
