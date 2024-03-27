// Rabin-Karp algorithm in C++

#include <string.h>

#include <iostream>
using namespace std;

#define d 10

void rabinKarp(char pattern[], char text[], int q) 
{
    int patternlength = strlen(pattern);
    int textlength = strlen(text);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    int temp=0;
    for (i = 0; i < patternlength - 1; i++)
    {
        h = (h * d) % q;
    }

    // Calculate hash value for pattern and text
    for (i = 0; i < patternlength; i++) 
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Find the match
    for (i = 0; i <= textlength - patternlength; i++) 
    {
        if (p == t) 
        {
            for(int j = 0; j < patternlength; j++) 
            {
                if (text[i + j] != pattern[j])
                {
                    break;
                }
            }   
            if(j == patternlength)
            {   
                cout << i  << endl;
                temp=1;

            }
        }
        // Calculate hash value for next window of text
        if (i < textlength - patternlength) 
        {
            t = (d * (t - text[i] * h) + text[i + patternlength]) % q;
            if (t < 0)
            {
                t = (t + q);
            }
        }
    }   
    if(temp == 0)
    {   
        cout<<"-1";
    }   
}

int main() 
{
    char text[100];
    cin >> text;
    char pattern[100];
    cin >> pattern;
    int q = 13;
    rabinKarp(pattern, text, q);
    return 0;
}