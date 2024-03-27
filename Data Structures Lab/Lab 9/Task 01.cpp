#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, int> map1;
    string arr[100];
    int i=0;
    string n;
    cin >> n;
    while(n!="-1")
    {
        map1[n]=i;
        i++;
        cin >> n;
    }
    cin >> n;
    i=0;
    while(n!="-1")
    {
        arr[i]=n;
        i++;
        cin >> n;
    }
    int x;
    x = i;
    for(int i=0;i<x;i++)
    {
        if(map1.find(arr[i]) == map1.end())
        {
            cout << "NO";
            return 0;
        }
        else
        {
            continue;
        }
    }
    cout << "YES";
    return 0;
}