#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Median 
{
    public:
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> greater;
    void AddNum(int val)
    {
        if(greater.empty() && lower.empty())
        {
            greater.push(val);
        }
        else
        {
            if(val>=greater.top())
            {
                greater.push(val);
            }
            else
            {
                lower.push(val);
            } 

            if(greater.size()-lower.size()==2)
            { 
                lower.push(greater.top());        
                greater.pop();                    
            } 
            else if(lower.size()-greater.size()==2)
            { 
                greater.push(lower.top());               
                lower.pop();                           
            }
        }
        
    }

    void FindMedian() 
    {
        if(greater.size()==lower.size())
        {
            cout << (double(greater.top())+double(lower.top()))/2 << endl;  
        }               
        else if(greater.size()>lower.size())
        {
            cout << greater.top()<< endl;
        }           
        else                   
        {
            cout << lower.top()<< endl;
        }                      
    }
};

int main()
{
    Median median;
    median.AddNum(13);
    median.AddNum(14);
    median.AddNum(16);
    median.FindMedian();
    //median.AddNum(8);
    //median.AddNum(7);
    //median.FindMedian();
    return 0;
}