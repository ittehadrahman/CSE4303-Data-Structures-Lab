#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> tickets;
    int arr[1000];
    int n;
    int i=0;
    while(1)
    {
        cin >> n;
        if(n!=-1)
        {
            tickets.push(n);
            arr[i] = n;
            i++;
        }
        else
        {
            break;
        }
    }
    int count=0, j=0;
    cin >> n;
    int k = arr[n];
    while(tickets.size()!=0)
    {
        if(tickets.front()>=k)
        {
            if(j<=n)
            {
                count += k;
                tickets.pop();
                j++;
            }
            else
            {
                count += k-1;
                tickets.pop();
                j++;
            }
        }
        else
        {
            count += tickets.front();
            tickets.pop();
            j++;
        }
    }
    cout << count;
    return 0;
}