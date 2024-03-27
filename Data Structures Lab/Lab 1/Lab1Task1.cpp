#include <iostream>

using namespace std;

int main()
{
    int n;
    int arr[100];
    cin >> n;
    arr[0] = n;
    int i=1, num=1;
    while(n>0)
    {
        cin >> n;
        arr[i] = n;
        i++;
        num++;
        if(n<=0)
        {
            break;
        }
    }
    for(int i=0;i<num;i++)
    {
        if(arr[i]==0)
        {
            continue;
        }
        else
        {
            cout << arr[i] << " occurs: ";
            int count = 1;
            for(int j=i+1;j<num;j++)
            {
                if(arr[i]==arr[j] && arr[i]!=0)
                {
                    arr[j] = 0;
                    count++;
                }
            }
            cout << count << endl;
        }
        
    }
    return 0;
}