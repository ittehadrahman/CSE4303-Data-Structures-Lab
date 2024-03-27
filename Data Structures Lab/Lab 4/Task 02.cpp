#include <iostream>
#include <queue>

using namespace std;

queue<int> val;

int ping(int t) 
{
    val.push(t);
    while(val.front()<t-3000)
    {
        val.pop();
    }
    return val.size();
}


int main() 
{
    cout << ping(1) << endl;//1
    cout << ping(2) << endl;//1 2
    cout << ping(3) << endl;//1 2 3
    cout << ping(4) << endl;//1 2 3 4
    cout << ping(3001) << endl;//1 2 3 4 3001
    cout << ping(3002) << endl;//2 3 4 3001 3002
    cout << ping(3003) << endl;//3 4 3001 3002 3003
    cout << ping(6003) << endl;//3003 6003
    cout << ping(10003) << endl;//10003
    return 0;
}