#include <iostream>
#include <queue>

using namespace std;    

queue<int> Stack;

void push_s(int x) {
    Stack.push(x);
}


void pop_s() 
{
    int size = Stack.size(); //1 2 3 4 5
    int key;
    for(int i=0;i<size-1;i++)
    {
        key = Stack.front();
        Stack.pop();
        Stack.push(key);
    }
    Stack.pop();
}


int top_s() {
   int size = Stack.size();
    int key;
    for(int i=0;i<size-1;i++)
    {
        key = Stack.front();
        Stack.pop();
        Stack.push(key);
    }
    key = Stack.front(); //1 2 3 4 5
    Stack.pop();
    Stack.push(key);
    return key;
}

bool empty_s() 
{
   return Stack.empty();
}

int main() {
    push_s(10);
    cout << top_s() << endl;
    push_s(20);
    cout << top_s() << endl;
    pop_s();
    cout << top_s() << endl;
    push_s(100);
    cout << top_s() << endl;
    cout << empty_s() << endl;
    pop_s();
    pop_s();
    cout << empty_s() << endl;
}
