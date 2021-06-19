#include "bac.h"
#include "maincalcu.h"

bCalcu::bCalcu(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::bCalcu)
{
    ui->setupUi(this);
    ui->errorlbl->setVisible(false); // make error label invisibel as default
    setValidateList(); // set validator list for all lineEdit in the program
}

void bCalcu::setValidateList() // sets the list for all lineEdit boxes
{
   ui->lineEdit1_0->setValidator(validator);
   ui->lineEdit1_1->setValidator(validator);
   ui->lineEdit1_2->setValidator(validator);
   ui->lineEdit1_3->setValidator(validator);
   ui->lineEdit1_4->setValidator(validator);
   ui->lineEdit1_5->setValidator(validator);
   ui->lineEdit1_6->setValidator(validator);
   ui->lineEdit1_7->setValidator(validator);
   ui->lineEdit1_8->setValidator(validator);
   ui->lineEdit1_9->setValidator(validator);
}


void bCalcu::calculateAction()
{
    mainCalcu *base = new mainCalcu;
    ui->errorlbl->setVisible(false);  // hide input error if its shown

    // insert data into the calculator from the lineEdit's
    if (ui->un1_0->currentIndex() && ui->lineEdit1_0->text().toInt())
    {
        base->insert(PROF_INDEX::e_citizenship, ID_TABLE::e_regular,(ui->un1_0->currentIndex()),(ui->lineEdit1_0->text().toInt()));
    }

    if (ui->un1_1->currentIndex() && ui->lineEdit1_1->text().toInt())
    {
        base->insert(PROF_INDEX::e_english, ID_TABLE::e_englishB,(ui->un1_1->currentIndex()),(ui->lineEdit1_1->text().toInt()));
    }

    if (ui->un1_2->currentIndex() && ui->lineEdit1_2->text().toInt())
    {
        base->insert(PROF_INDEX::e_hebrew, ID_TABLE::e_regular,(ui->un1_2->currentIndex()),(ui->lineEdit1_2->text().toInt()));
    }

    if (ui->un1_3->currentIndex() && ui->lineEdit1_3->text().toInt())
    {
        base->insert(PROF_INDEX::e_history, ID_TABLE::e_special,(ui->un1_3->currentIndex()),(ui->lineEdit1_3->text().toInt()));
    }

    if (ui->un1_4->currentIndex() && ui->lineEdit1_4->text().toInt())
    {
        base->insert(PROF_INDEX::e_math, ID_TABLE::e_mathB,(ui->un1_4->currentIndex()),(ui->lineEdit1_4->text().toInt()));
    }

    if (ui->un1_5->currentIndex() && ui->lineEdit1_5->text().toInt())
    {
        base->insert(PROF_INDEX::e_literature, ID_TABLE::e_special,(ui->un1_5->currentIndex()),(ui->lineEdit1_5->text().toInt()));
    }

    if (ui->un1_6->currentIndex() && ui->lineEdit1_6->text().toInt())
    {
        base->insert(PROF_INDEX::e_bible, ID_TABLE::e_special,(ui->un1_6->currentIndex()),(ui->lineEdit1_6->text().toInt()));
    }

    if (ui->list->currentIndex() && ui->un1_7->currentIndex() > 0 && ui->lineEdit1_7->text().toInt())
    {
        base->insert(PROF_INDEX::e_select1, ui->list->currentIndex(),ui->un1_7->currentIndex(),ui->lineEdit1_7->text().toInt());
    }

    if (ui->list_2->currentIndex() && ui->un1_8->currentIndex() > 0 && ui->lineEdit1_8->text().toInt())
    {
        base->insert(PROF_INDEX::e_select2,ui->list_2->currentIndex(),ui->un1_8->currentIndex(),ui->lineEdit1_8->text().toInt());
    }

    if (ui->list_3->currentIndex() && ui->un1_9->currentIndex() > 0 && ui->lineEdit1_9->text().toInt())
    {
        base->insert(PROF_INDEX::e_select3,ui->list_3->currentIndex(),ui->un1_9->currentIndex(),ui->lineEdit1_9->text().toInt());
    }


if(base->getUnit()) // start display section only if units are entered!
    {
      // display the score+bonus in every profession
     // if statements below displays the score+bonus only in an event of desired input
    if ((ui->lineEdit1_0->text().toInt()) && ui->un1_0->currentIndex())
    {
        ui->lineEdit2_0->setText(QString::number(base->wShow(PROF_INDEX::e_citizenship)));
    }
    else
    {
        ui->lineEdit2_0->clear();
    }
    if ((ui->lineEdit1_1->text().toInt()) && ui->un1_1->currentIndex())
    {
        ui->lineEdit2_1->setText(QString::number(base->wShow(PROF_INDEX::e_english)));
    }
    else
    {
        ui->lineEdit2_1->clear();
    }
    if ((ui->lineEdit1_2->text().toInt()) && ui->un1_2->currentIndex())
    {
        ui->lineEdit2_2->setText(QString::number(base->wShow(PROF_INDEX::e_hebrew)));
    }
    else
    {
        ui->lineEdit2_2->clear();
    }
    if ((ui->lineEdit1_3->text().toInt()) && ui->un1_3->currentIndex())
    {
        ui->lineEdit2_3->setText(QString::number(base->wShow(PROF_INDEX::e_history)));
    }
    else
    {
        ui->lineEdit2_3->clear();
    }
    if ((ui->lineEdit1_4->text().toInt()) && ui->un1_4->currentIndex())
    {
        ui->lineEdit2_4->setText(QString::number(base->wShow(PROF_INDEX::e_math)));
    }
    else
    {
        ui->lineEdit2_4->clear();
    }
    if ((ui->lineEdit1_5->text().toInt()) && ui->un1_5->currentIndex())
    {
        ui->lineEdit2_5->setText(QString::number(base->wShow(PROF_INDEX::e_literature)));
    }
    else
    {
        ui->lineEdit2_5->clear();
    }
    if ((ui->lineEdit1_6->text().toInt()) && ui->un1_6->currentIndex())
    {
        ui->lineEdit2_6->setText( QString::number ( base->wShow(PROF_INDEX::e_bible)));
    }
    else
    {
        ui->lineEdit2_6->clear();
    }
    if ((ui->list->currentIndex()) && (ui->lineEdit1_7->text().toInt()) && ui->un1_7->currentIndex())
    {
        ui->lineEdit2_7->setText( QString::number(base->wShow(PROF_INDEX::e_select1)));
    }
    else
    {
        ui->lineEdit2_7->clear();
    }
    if ((ui->list_2->currentIndex()) && (ui->lineEdit1_8->text().toInt()) && ui->un1_8->currentIndex())
    {
        ui->lineEdit2_8->setText( QString::number(base->wShow(PROF_INDEX::e_select2)));
    }
    else
    {
        ui->lineEdit2_8->clear();
    }

    if ((ui->list_3->currentIndex())&& (ui->lineEdit1_9->text().toInt()) && ui->un1_9->currentIndex())
    {
        ui->lineEdit2_9->setText( QString::number(base->wShow(PROF_INDEX::e_select3)));
    }
    else
    {
        ui->lineEdit2_9->clear();
    }

        ui->wScore->setText(QString::number(base->wCalculate())); // calculate and display weighted score
        ui->rScore->setText(QString::number(base->rCalculate())); // calculate and display real score
}
 else
    {
        ui->errorlbl->setVisible(true);
      // display input error when units are = 0
      // clear all remaining display windows
        ui->lineEdit2_0->clear();
        ui->lineEdit2_1->clear();
        ui->lineEdit2_2->clear();
        ui->lineEdit2_3->clear();
        ui->lineEdit2_4->clear();
        ui->lineEdit2_5->clear();
        ui->lineEdit2_6->clear();
        ui->lineEdit2_7->clear();
        ui->lineEdit2_8->clear();
        ui->lineEdit2_9->clear();
        ui->rScore->clear();
         ui->wScore->clear();

      }
   delete base;
}

void bCalcu::clearAll() // resets all information in the program
{
     ui->errorlbl->setVisible(false);

    ui->un1_0->setCurrentIndex(0);
    ui->un1_1->setCurrentIndex(0);
    ui->un1_2->setCurrentIndex(0);
    ui->un1_3->setCurrentIndex(0);
    ui->un1_4->setCurrentIndex(0);
    ui->un1_5->setCurrentIndex(0);
    ui->un1_6->setCurrentIndex(0);
    ui->un1_7->setCurrentIndex(0);
    ui->un1_8->setCurrentIndex(0);
    ui->un1_9->setCurrentIndex(0);

    ui->lineEdit1_0->clear();
    ui->lineEdit1_1->clear();
    ui->lineEdit1_2->clear();
    ui->lineEdit1_3->clear();
    ui->lineEdit1_4->clear();
    ui->lineEdit1_5->clear();
    ui->lineEdit1_6->clear();
    ui->lineEdit1_7->clear();
    ui->lineEdit1_8->clear();
    ui->lineEdit1_9->clear();

    ui->lineEdit2_0->clear();
    ui->lineEdit2_1->clear();
    ui->lineEdit2_2->clear();
    ui->lineEdit2_3->clear();
    ui->lineEdit2_4->clear();
    ui->lineEdit2_5->clear();
    ui->lineEdit2_6->clear();
    ui->lineEdit2_7->clear();
    ui->lineEdit2_8->clear();
    ui->lineEdit2_9->clear();

    ui->list->setCurrentIndex(0);
    ui->list_2->setCurrentIndex(0);
    ui->list_3->setCurrentIndex(0);

     ui->wScore->clear();
     ui->rScore->clear();
}

bCalcu::~bCalcu()
{
    delete helpWindow;
    delete validator;
    delete ui;

}


void bCalcu::on_pushButton_clicked() // this function creates an event when the button is clicked
{

    calculateAction();

}

void bCalcu::on_clearAll_clicked()
{
    clearAll();
}


void bCalcu::on_helpWindow_clicked()
{    
   helpWindow->setModal(true);
   helpWindow->show();
}
