//Homework 1, Problem 3
//Find Binary Representation of Floating Point Number
//Liam Abbott, leabbott

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int * getSignRep(float inVal);
int * getExpRep(int exp);
int * getSignifRep(float frac);

float reverseSignRep(int * signRep);
float reverseExpRep(int * expRep);
float reverseSignifRep(int * signifRep);

int main(int argc, char * argv[])
{

    float inVal = atof(argv[1]);
    float inValAbs = abs(inVal);
    float testVal = inValAbs;

    int exp;
    float frac;

    if (inValAbs <= 1.0)
    {
        for (int i=0; testVal <= 1; i--)
        {
            testVal = inValAbs*pow(2,-i);
            exp = 127+i;
        }
    }
    else if (inValAbs >= 2.0)
    {
        for (int i=0; testVal >= 2; i++)
        {
            testVal = inValAbs*pow(2,-i);
            exp = 127+i;
        }
    }
    else
    {
        exp = 127;
    }

    frac = testVal - 1.0;

    int * signRep;
    signRep = getSignRep(inVal);
    cout << *signRep;

    int * expRep;
    expRep = getExpRep(exp);
    for (int i=7; i>=0; i--)
    {
        cout << *(expRep + i);
    }

    int * signifRep;
    signifRep = getSignifRep(frac);
    for (int i=0; i<=22; i++)
    {
        cout << signifRep[i];
    }
    cout << '\n';

    float reverseSign;
    reverseSign = reverseSignRep(signRep);

    float reverseExp;
    reverseExp = reverseExpRep(expRep);

    float reverseSignif;
    reverseSignif = reverseSignifRep(signifRep);

    cout.precision(30);
    cout << reverseSign * pow(2,-reverseExp) * reverseSignif << '\n';

    return 0;
}

int * getSignRep(float inVal)
{
    static int localArray[1];
    if (inVal < 0)
    {
        localArray[0] = 1;
    }
    else
    {
        localArray[0] = 0;
    }
    return localArray;
}

int * getExpRep(int exponent)
{
    static int localArray[8];
    for (int i=7; i>=0; i--)
    {
        if (exponent & (1<<i))
        {
            localArray[i] = 1;
        }
        else
        {
            localArray[i] = 0;
        }
    }
    return localArray;
}

int * getSignifRep(float frac)
{
    static int localArray[23];
    float runningTotal = 0.0;
    float testTotal = 0.0;
    for (int i=1; i<=23; i++)
    {
        testTotal = runningTotal + (1.0/pow(2,i));
        if (testTotal <= frac)
        {
            localArray[i-1] = 1;
            runningTotal = testTotal;
        }
        else
        {
            localArray[i-1] = 0;
        }
    }
    return localArray;
}

float reverseSignRep(int * signRep)
{
    float sign = *signRep;
    return pow(-1, sign);
}

float reverseExpRep(int * expRep)
{
    float exponent = 0.0;
    for (int i=7; i>=0; i--)
    {
        exponent = exponent + expRep[i]*pow(2, i);
    }
    exponent = 127 - exponent;
    return exponent;
}

float reverseSignifRep(int * signifRep)
{
    float signif = 0.0;
    for (int i=1; i<=23; i++)
    {
        signif = signif + signifRep[i-1]*pow(2, -i);
    }
    return 1.0+signif;
}

