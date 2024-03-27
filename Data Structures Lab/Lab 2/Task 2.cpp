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
        if( Size == Capacity )
        {
            int *new_arr = new int(Capacity * 2);
            for(int i = 0 ; i < Size ; i++)
            {
                new_arr[i] = arr[i];
            }
            delete(arr);
            arr = new_arr;
            Capacity = 2 * Capacity;
        }
        arr[Size] = val;
        Size++;
    }
    void Reverse()
    {
        int *new_arr = new int(Capacity);
        int j=0;
        for(int i=Size-1;i>=0;i--)
        {
            new_arr[j] == arr[i];
            j++;
        }
        delete(arr);
        arr = new_arr;
    }
    int Get_Size()
    {
        return Size;
    }
    int Get_Capacity()
    {
        return Capacity;
    }
    int *Get_array()
    {
        return arr;
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
        Size--;
    }
};

int *increase(Dynamic_Array arr)
{
    for(int i=(arr.Get_Size()-1);i>=0;i--)
    {
        int val;
        val = arr.Get(i) + 1;//10
        if(val > 9)
        {
            arr.Set(i,0);
            if(i == 0)
            {
                arr.Set(i,1);
                arr.PushBack(0);
            }
            else
            {
                arr.Set(i-1,(arr.Get(i-1)));    
            }
        }
        else
        {
            arr.Set(i,val);      
            break;
        }
    }
    arr.PushBack(-1);
    return arr.Get_array();
}

int main()
{
    Dynamic_Array arr;
    cout << "Number of digits : " << endl;
    int size = 0 ;
    cin >> size;
    int x = 0 ;
    for(int i = 0 ; i<size ; i++)
    {
        cin>>x;
        arr.PushBack(x);
    }
    int *new_a = increase(arr);
    for(int i = 0 ;  ; i++)
    {
        if(new_a[i] == -1)
        {
            break;
        }
        cout<< new_a[i] << " ";
    }
    return 0;
}
