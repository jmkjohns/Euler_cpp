#include <iostream>

//==============================================================================
int main( int argc, char *argv[] )
//==============================================================================
{
    //declare
    int total = 0;
    int currentDay = 2;
    int currentYear = 1;
    int currentMonth = 0;
    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //calculate
    for (; currentYear <= 100; ++currentYear)
    {
        for (int i = 0; i < 12; ++i)
        {
            //feb in leap years
            if (i == 1)
            {
                if (currentYear % 4 == 0)
                {
                    if (currentYear % 400 == 0)
                    {
                        currentDay += months[i];
                        currentDay %= 7;
                        if (currentDay == 0)
                        {
                            total++;
                        }
                    }
                    else
                    {
                        currentDay += 29;
                        currentDay %= 7;
                        if (currentDay == 0)
                        {
                            total++;
                        }
                    }
                }
                else
                {
                    currentDay += months[i];
                    currentDay %= 7;
                    if (currentDay == 0)
                    {
                        total++;
                    }
                }
            }
            //all other months
            else
            {
                currentDay += months[i];
                currentDay %= 7;
                if (currentDay == 0)
                {
                    total++;
                }
            }
        }
    }

    std::cout << total << std::endl;
}
