#include "myvalidator.h"
#include "ui_bac.h"
#include "bac.h"

MyIntValidator::MyIntValidator (int bottom, int top, QObject * parent) :  // constructor
QIntValidator(bottom, top, parent){}


MyIntValidator::QValidator::State validater(QString &s) const // validate input by user
    {
        if (s.isEmpty()) // if the string in lineedit is empty allow typing (intermediate)
        {
            return QValidator::Intermediate;
        }

        QLocale locale;
        if ( (locale.toInt(s)) >= bottom() && (locale.toInt(s)) <= top()) // compare ranges
        {
            return QValidator::Acceptable;
        }
        else
        {
            return QValidator::Invalid;
        }
    }