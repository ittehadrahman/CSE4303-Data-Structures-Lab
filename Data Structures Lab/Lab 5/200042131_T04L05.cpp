#include<bits/stdc++.h>

using namespace std;

int main()
{
    priority_queue <pair<int,bool>, vector<pair<int,bool>>, greater<pair<int,bool>>> pq;
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        pq.push({a,true});
        pq.push({b,false});
    }
    int checkRoom = 0;
    int maxRoom = 0; 
    while(!pq.empty())
    {
        pair<int,bool> top = pq.top();
        if(top.second)
        {
            checkRoom++;
        }
        else if(!top.second)
        {
            checkRoom--;
        }
        maxRoom = max(maxRoom, checkRoom);    
        pq.pop();
    }   
    cout << maxRoom <<endl;
    return 0;
}