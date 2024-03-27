#include<bits/stdc++.h>

using namespace std;

struct node
{
    int val;
    node *next;
} ;

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
        struct node* newNode = (struct node*) malloc(sizeof(struct node));
        newNode->val  = n;
        newNode->next = head;
        head = newNode;
    }
    

    void PushBack(int n)
    {
        //struct node* newNode = (struct node*) malloc(sizeof(struct node));  
        node* newNode = new node();
        newNode->val = n;
        newNode->next = nullptr; 
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }         
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
    void Func()
    {
        node *slow, *fast;
        slow = head;
        fast = head;
        while(fast != nullptr)
        {
            if(fast->next!=nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            else
            {
                break;
            }
        }
        while(slow!=nullptr)
        {
            cout << slow->val << " ";
            slow = slow->next;
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
    int t, temp;
    cin >> t;
    for(int i=0 ; i<t; i++)
    {   
        cin >> temp;
        a.PushBack(temp);
    }
    a.Func();
    return 0;
}