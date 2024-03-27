#include<bits/stdc++.h>

using namespace std;

int main()
{
    priority_queue<int> pq;
    for(int i = 1 ; ; i++)
    {
        int n;
        cin >> n;
        if(n == -1)
        {
            break;//8 7 4 2 1 1
        }
        pq.push(n);
    }
    while(true)
    {
        int x = pq.top();
        pq.pop();
        if(pq.empty())
        {
            pq.push(x);
            break;
        }
        int y = pq.top();
        pq.pop();
        if(x != y)
        {
            pq.push((x>y) ? (x-y) : (y-x));
        }
        else
        {
            if(pq.empty())
            {
                break;
            }
        }
    }
    if(pq.empty())
    {
        cout<<0<<endl;
    }
    else
    {
        cout<<pq.top()<<endl;
    }
    return 0;
}