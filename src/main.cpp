#include <iostream>
#include <math.h>

#define freqN 7

const float c = 299792458;
const float Vc = c*80/100;
const float Re = 6.371*pow(10,3);    //±11

struct F
{
    float freq;
    float n;
};

F freqs[freqN];
//Fn = Vc/2pRe * sqrt(n(n+1)) Hz

float calculateFrequency(int );
void printFrequency();

int main()
{
    for(int i=0;i<freqN;i++)
    {
        freqs[i].freq=calculateFrequency(i+1);
        freqs[i].n=i;
    }
    
    printFrequency();
    return 0;
}

float calculateFrequency(int n)
{
    //return ((Vc/(Re*2*M_PI))*sqrt(n*(n+1)))/1000.0;
    //return (Vc/(Re*2*M_PI))/1000;               //5.99 Hz

    //return ((c/(Re*2*M_PI))*sqrt(n*(n+1)))/1000;
    return ((c/(Re*2*M_PI))/1000)*n;            //7.48 Hz, n=1 fundamental frequency
}

void printFrequency()
{
    for(int i=0;i<freqN;i++)
        std::cout << freqs[i].freq << "Hz at order " << freqs[i].n << "; " << char(10);
}