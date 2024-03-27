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
    if (left < n && (a[left] > a[largest]))
    {
        largest = left; 
    }
    if (right < n && a[right] > a[largest])
    {
        largest = right;
    }
    if (largest != i) 
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void maxHeap(int a[], int n)
{
    int nonleaf = (n / 2) - 1;
    for (int i=nonleaf; i>=0; i--) 
    {
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

int main()
{
    int a[100] , n=-1;
    for(int i = 0 ; ; i++)
    {
        cin>>a[i];
        n++;
        if(a[i] == -1)
        {
            break;
        }       
    }
    cout<<n<<endl;
    maxHeap(a,n);
    printHeap(a,n);
    heapSort(a,n);
    printDescHeap(a,n);
    return 0;
}