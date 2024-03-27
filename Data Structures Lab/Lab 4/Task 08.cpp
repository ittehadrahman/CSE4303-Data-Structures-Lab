#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> circle;
    int n, k, key;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        circle.push(i);
    }
    cin >> k;
    int i=0;
    while(circle.size()!=1)
    {
        i++;
        if(i!=k)
        {
            key = circle.front();
            circle.pop();
            circle.push(key);
        }
        else
        {
            circle.pop();
            i=0;
        }
    }
    cout << circle.front();
    return 0;
}