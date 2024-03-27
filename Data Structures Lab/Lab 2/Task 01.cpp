#include<bits/stdc++.h>
using namespace std;

class Dynamic_Array
{
public:
    int Size;
    int Capacity;
    int *arr;
    Dynamic_Array()
    {
        Size = 0;
        Capacity = 1;
        arr = new int[Capacity];
    }
    int Get(int i)
    {
        if ((i < 0 ) or (i >= Size))
        {
            cout << "Index out of Range" << endl;
            return -1;
        }
        return arr[i];
    }
    void Set(int i,int val)
    {
        if ((i < 0 ) or (i >= Size))
        {
            cout << " Index out of Range" << endl;
            return;
        }
        arr[i] = val;
    }
    void PushBack(int val)
    {
        if(Size == Capacity)
        {
            int n = Capacity;
            int *new_arr;//create new array
            Capacity *= 2;//double the capacity
            new_arr = new int[Capacity];
            int k=0;
            for (k = 0; k < n; k++) {
                new_arr[k] = arr[k];//use for loop and copy the old array to the new one
            }
            delete(arr);//delete the old array
            new_arr[Size] = val;//add the new element to the array
            arr = new_arr;//make the old pointer arr point to the new arr
            Size++;//increment the size by 1
        }
        else
        {
            arr[Size] = val;//add the new element to the array
            Size++;//increment the size by 1
        }
    }
    int Get_Size()
    {
        return Size;
    }
    int Get_Capacity()
    {
        return Capacity;
    }
    void Remove(int i)
    {
        int *new_arr;
        new_arr = new int[Capacity];
        int k=0;
        for(int j=0;j<Capacity;j++)
        {
            if(i!=j)
            {
                new_arr[k] == arr[j];
                k++;
            }
            else if(i==j)
            {
                continue;
            }
        }
        arr = new_arr;
        Size--;
    }
};

int main()
{
    Dynamic_Array arr;
    for(int i =0;i<16;i++)
    {
        arr.PushBack(100 + i);
        cout <<"Val: "<< arr.Get(i) <<" Size: "<< arr.Get_Size()<<" Capacity: "<<arr.Get_Capacity()<< endl;
    }
}
