// Rabin-Karp algorithm in C++

#include <string.h>

#include <iostream>
using namespace std;

#define d 10

void rabinKarp(char pattern[], char text[], int q) 
{
  int m = strlen(pattern);
  int n = strlen(text);
  int i, j;
  int p = 0;
  int t = 0;
  int h = 1;

  for (i = 0; i < m - 1; i++)
    h = (h * d) % q;//sad

  // Calculate hash value for pattern and text
  for (i = 0; i < m; i++) {
    p = (d * p + pattern[i]) % q;//utsa
    t = (d * t + text[i]) % q;//sadbutsad
  }

  // Find the match
  for (i = 0; i <= n - m; i++) {
    if (p == t) {
      for (j = 0; j < m; j++) {
        if (text[i + j] != pattern[j])
          break;
      }
      
      if (j == m)
        cout << "Pattern is found at position: " << i + 1 << endl;
    }

    if (i < n - m) 
    {
      t = (d * (t - text[i] * h) + text[i + m]) % q;//sadb --> adbu --> dbut --> buts --> utsa

      if (t < 0)
        t = (t + q);
    }
  }
}

int main() {
  char text[] = "sadbutsad";
  char pattern[] = "sad";
  int q = 13;
  rabinKarp(pattern, text, q);
}