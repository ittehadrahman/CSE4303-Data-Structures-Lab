#include<bits/stdc++.h>

using namespace std;

struct node
{
    int val;
    node *next;
};

class Singly_linked_list{
public:
    node *head, *tail;

    Singly_linked_list()
    {
        head = nullptr;
        tail = nullptr;
    }

    void PushFront(int n)
    {
        //struct node* newNode = (struct node*) malloc(sizeof(struct node));
        node* newNode = new node();//create new empty node
        newNode->val  = n;//value assign
        newNode->next = head;//point next node
        head = newNode;
    }

    void PushBack(int n)
    {
        //struct node* newNode = (struct node*) malloc(sizeof(struct node));  
        node* newNode = new node();//create new node
        newNode->val = n;//value assign
        newNode->next = nullptr;//points null pointer
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;//second last node points to the last new node
            tail = newNode;//tail pointer points to the last node
        }         
    }
    int PopFront()
    {
        int key;
        key = head->val;
        head = head->next;
        return key;
    }

    int PopBack()
    {
        node* cur = head;//create a current pointer
        while(cur->next!=tail)
        {
            cur = cur->next;//traversing through the list until my next pointer is tail
        }
        int key;
        key = tail->val;//storing the value of the last node 
        cur->next = nullptr;//second last pointer now points to nullptr
        tail = cur;
        return key;
    }

    void display()
    {
        node *cur = head;

        while(cur != nullptr)
        {
            cout << cur->val << endl;
            cur = cur->next;
        }
        cout<<endl;
    }

    void Reverse()
    {
        node* current = head;
        node *prev = NULL, *next = NULL;
        while (current != NULL) 
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};

int main()
{
    Singly_linked_list a;
    for(int i =1 ; i < 10; i++)
    {   
        a.PushFront(i);
    }    
    a.display();
    a.Reverse();
    a.display();
    a.PopFront();
    a.PopBack();
    a.PushFront(100);
    a.display();
    a.display();
}