#include "maincalcu.h"

void mainCalcu::insert(unsigned int index, int id, int unit, int score)
{
    this->m_unitCount += unit; // add current unit into the sum of units
    this->m_rScoreSum += score; // add current score to real sum
    this->m_professionCount++; // add profession to count

    if( (score < 60 || unit < 4) || id == ID_TABLE::e_noBonus)// no bonus
    {
    this->m_gradeArray[index] = score;
    this->m_wScoreSum += (score*unit);
    }
    else // bonus required
    {
        if(unit == 4)
        {
            if(id == ID_TABLE::e_mathB || id == ID_TABLE::e_englishB) // if math or english do 12.5
            {
                this->m_gradeArray[index] = (score+12.5);
                this->m_wScoreSum += ((score+12.5)*unit);
            }
            else
            {
                this->m_gradeArray[index] = (score+10);
                this->m_wScoreSum += ((score+10)*unit);
            }
        }
        if(unit == 5)
        {
            if(id == ID_TABLE::e_mathB) // special case math
            {
                this->m_gradeArray[index] = (score+35);
                this->m_wScoreSum += ((score+35)*unit);
            }
            else if(id == ID_TABLE::e_englishB || id == ID_TABLE::e_biology
                    || id == ID_TABLE::e_chemistry || id == ID_TABLE::e_physics || id == ID_TABLE::e_other)
            {
                this->m_gradeArray[index] = (score+25);
                this->m_wScoreSum += ((score+25)*unit);

            }
            else
            {
                this->m_gradeArray[index] = (score+20);
                this->m_wScoreSum += ((score+20)*unit);
            }
        }
    }
}

double mainCalcu::wShow(unsigned int index)
{
return double(this->m_gradeArray[index]);
}

int mainCalcu::rCalculate() const // division function to calculate real average
{
    return (m_rScoreSum / m_professionCount);
}

double mainCalcu::wCalculate() const // division function to calculate weighted average
{
    return (m_wScoreSum / m_unitCount);
}


