#ifndef BAC_H
#define BAC_H

#include <QMainWindow>
#include "dialog.h"
#include "myvalidator.h"

namespace Ui { // define class bCalcu within Ui namespace
class bCalcu;
}

class bCalcu : public QMainWindow
{
    Q_OBJECT

public:
    explicit bCalcu(QWidget *parent = nullptr);
    ~bCalcu();
    void setValidateList();
    void calculateAction();
    void clearAll();

private slots:
    void on_pushButton_clicked();
    void on_clearAll_clicked();


    void on_helpWindow_clicked();

private:
    Ui::bCalcu *ui;
    dialog *helpWindow = new dialog;
    MyIntValidator *validator= new MyIntValidator(0, 100 ,this);
};


#endif // BAC_H
