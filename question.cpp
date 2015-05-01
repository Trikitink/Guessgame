#include "question.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iostream>

CGame::CGame()
{
    m_guess = 0;
    m_number = 0;
    randomize();
}

CGame::~CGame()
{

}

void CGame::randomize()
{
    srand ( time (NULL) );

    m_number = ( rand() % 100 + 1 );

}

int CGame::answer(int submit)
{
    m_guess = submit;

    return m_guess;
}

CGame::DECISION CGame::highlow()
{
    if ( m_number < m_guess ) return tooLow;
    else if ( m_number > m_guess ) return tooHigh;
    else return correct;
}

bool CGame::check(int numba)
{
    if ( numba == m_number ) return true;
    else return false;
}

