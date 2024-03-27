#include<bits/stdc++.h>

using namespace std;

int Parent(int i) 
{
    return (i - 1) / 2;
}

int Left(int i) 
{
    return (2*i + 1);
}

int Right(int i) 
{
    return (2*i + 2);
}

void heapify(int a[], int n, int i)
{
    int largest = i; 
    int left = Left(i);
    int right = Right(i);
    if (left < n && (a[left] < a[largest]))
    {
        largest = left; 
    }
    if (right < n && a[right] < a[largest])
    {
        largest = right;
    }
    if (largest != i) 
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void minHeap(int a[], int n)
{
    int nonlIndex = (n / 2);
    //iterate from last non-leaf node
    for (int i = nonlIndex; i > 0; i--) {
        heapify(a, n, i);
    }
}

void heapSort(int a[], int n)
{
    for (int i=n-1; i>=0; i--) 
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void printHeap(int a[], int n)
{
    for (int i=0; i<n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void printDescHeap(int a[], int n)
{
    for (int i=n-1; i>=0; --i)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int heap_minimim(int a[])
{
    return a[1];
}

int heap_extractmin(int a[], int n)
{
    int minval = a[1];
    for(int i = 2 ;i<=n ;i++)
    {
        a[i-1] = a[i];
    }
    a[n] = 0;
    minHeap(a, n);
    return minval;
} 

void minHeapInsert(int val, int a[], int n)
{
    a[n + 1] = val;
    minHeap(a, n + 2);
}

int main()
{
    int a[100] , n = -1;
    for(int i = 1 ; ; i++)
    {
        cin>>a[i];
        n++;
        if(a[i] == -1)
        {
            break;
        }
    }
    minHeap(a,n);
    printHeap(a,n); 
    int input = 51;
    while(true)
    {
        cin>>input;
        if(input == 1)
        {
            cout<<heap_minimim(a)<<endl;
            printHeap(a,n);
        }
        else if(input == 2)
        {
            cout<<heap_extractmin(a,n)<<endl;
            --n;
            printHeap(a,n);
        }
        else if(input == 3)
        {
            int x;
            cin>>x;
            minHeapInsert(x,a,n);
            ++n;
            printHeap(a,n);
        }
        else
        {
            break;
        }
    }
    return 0;
}