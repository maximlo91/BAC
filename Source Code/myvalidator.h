#ifndef MYVALIDATOR_H
#define MYVALIDATOR_H
#include "ui_bac.h"

class MyIntValidator : public QIntValidator // special made derived class from QIntValidator
{
    public:
    MyIntValidator(int bottom, int top, QObject * parent);
    QValidator::State validater(QString &s) const; // validate for string input
  
};




#endif // MYVALIDATOR_H
