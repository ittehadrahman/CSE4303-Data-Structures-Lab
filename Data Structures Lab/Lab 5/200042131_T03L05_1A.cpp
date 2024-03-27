#include<bits/stdc++.h>

using namespace std;

int PAREnT(int i) {
    return (i - 1) / 2;
}

int LEFT(int i) {
    return (2*i + 1);
}

int RIGHT(int i) {
    return (2*i + 2);
}

void heapify(int a[], int n, int i)
{
    int largest = i; 
    int left = LEFT(i);
    int right = RIGHT(i);
 
    //left child is larger than root
    if (left < n && a[left] < a[largest])
        largest = left;
 
    //right child is larger than largest so far
    if (right < n && a[right] < a[largest])
        largest = right;
 
    //largest is not root
    if (largest != i) {
        swap(a[i], a[largest]);
 
        //recursion to heapify subtree
        heapify(a, n, largest);
    }
}

void minHeap(int a[], int n)
{
    
    int nonlIndex = (n / 2) - 1;
 
    //iterate from last non-leaf node
    for (int i = nonlIndex; i >= 0; i--) {
        heapify(a, n, i);
    }

}

int heap_minimim(int a[])
{
    return a[0];
}

int heap_extractmin(int a[], int n)
{
    for(int i = 1 ;i<n ;i++)
    {
        a[i-1] = a[i];
    }
    a[n-1] = 0;
    minHeap(a, n-1);
    return a[0];
} 

void minHeapInsert(int val, int a[], int n)
{
    a[n] = val;
    minHeap(a, n + 1);
}

void printHeap(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << "\n";
}


int main()
{
    int n , k;
    cin >> n >>k;
    int *a;
    for(int i = 0 ; i<n ; i++)
    {
        cin>>a[i];// 1 2 3 9 10 12
    }
    minHeap(a,n);
    printHeap(a,n);
    int count = 0;
    while(n!=0)
    {
        int check = heap_minimim(a);
        if(check>7)
        {
            break;
        }
        int val = 0;
        int L1 = 0, L2 = 0;
        L1 = heap_extractmin(a,n);
        --n;
        if(n == 0)
        {
            break;
        }
        L2 = heap_extractmin(a,n);
        --n;
        val = L1 + (2*L2);
        minHeapInsert(val, a, n);
        ++n;
        ++count;
    }
    cout<<count;
    return 0;
}