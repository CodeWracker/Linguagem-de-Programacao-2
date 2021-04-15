#ifndef CHANGEALPHA_H
#define CHANGEALPHA_H

#include <QDialog>
#include "data.h"
namespace Ui {
class ChangeAlpha;
}

class ChangeAlpha : public QDialog
{
    Q_OBJECT
public:
    int* pos;
    size_t* newChar;
    bool* cncl;
public:
    explicit ChangeAlpha(QWidget *parent = nullptr);
    ~ChangeAlpha();

private slots:
    void on_textEdit_textChanged();

    void on_spinBox_valueChanged(int arg1);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::ChangeAlpha *ui;
};

#endif // CHANGEALPHA_H
