#include <bits/stdc++.h>

using namespace std;

int binarySearchRe(int arr[], int left, int right, int x)
{
    if (right >= left) //0 2 6 11 12 18 34 45 55 99 
    {
        int middle = left + (right - left) / 2;
        if (arr[middle] == x)
        {
            return middle;
        }
        if (arr[middle] > x)
        {
            return binarySearchRe(arr, left, middle - 1, x);
        } 
        else
        {
            return binarySearchRe(arr, middle + 1, right, x);
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int arr[100000]={0};
    int i=0;
    int arrsize = sizeof(arr)/sizeof(arr[0]);
        arr[i]=n;
    while(n!=-1)
    {
        i++;
        cin>>n;
        arr[i]=n;
    }
    int a;
    cin>>a;
    int s = binarySearchRe(arr, 0, i, a);
    if(s==-1)
    {
        cout<<"-1"<<endl;   
    }
    else
    {
        cout<<s<<endl;
    }
    return 0;
}
int binarySearchIt(int arr[], int left, int right, int x)
{
    while (left <= right) 
    {
        int middle = left + (right - left) / 2;
        if (arr[middle] == x)
        {
            return middle;
        }
        if (arr[middle] < x)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
    return -1;
}
