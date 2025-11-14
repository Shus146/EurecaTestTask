#ifndef DIALOGWITHBUTTON_H
#define DIALOGWITHBUTTON_H

#include <QDialog>

class QPushButton;

class DialogWithButton : public QDialog
{
    Q_OBJECT

public:
    DialogWithButton(QWidget* parent = nullptr);
    ~DialogWithButton() override {}
private slots:
    void ButtonClicked();
private:
    QPushButton* createFileButton;
};

#endif // DIALOGWITHBUTTON_H
