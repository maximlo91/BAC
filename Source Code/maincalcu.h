#ifndef MAINCALCU_H
#define MAINCALCU_H
#include <vector>

class mainCalcu
{
private:
    int m_unitCount; // unit counter
    int m_rScoreSum; // real score sum
    double m_wScoreSum; // weighted score sum
    int m_professionCount;
    std::vector<double> m_gradeArray;

public:
    mainCalcu(): m_unitCount(0), m_rScoreSum(0),m_wScoreSum(0), m_professionCount(0)
    {
       this->m_gradeArray.reserve(10);
    }

    int getUnit() const {return m_unitCount;}

    void insert(unsigned int index, int id, int unit, int score);
    double wShow(unsigned int index);

    int rCalculate() const;
    double wCalculate() const;

    ~mainCalcu(){}



};

enum ID_TABLE
{
    e_biology = 4,
    e_chemistry = 14,
    e_physics = 34,
    e_other = 42,
    e_noBonus = 44,
    e_regular = 100,
    e_special,
    e_mathB,
    e_englishB
};

enum PROF_INDEX
{
    e_citizenship,
    e_english,
    e_hebrew,
    e_history,
    e_math,
    e_literature,
    e_bible,
    e_select1,
    e_select2,
    e_select3

};

#endif // MAINCALCU_H
