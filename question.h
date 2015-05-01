#ifndef QUESTION
#define QUESTION

class CGame
{

private:

    int m_number;
    int m_guess;
    enum DECISION
    {
        tooLow,
        tooHigh,
        correct
    };

public:

    CGame();
    ~CGame();

    int answer (int submit);
    void randomize();
    bool check(int);
    DECISION highlow();

};

#endif // QUESTION

