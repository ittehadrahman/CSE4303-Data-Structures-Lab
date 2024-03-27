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
        void Copy(int t)
        {
            node *cur = head;
            int arr[t], i=0;
            while(cur != nullptr)
            {
                arr[i] = cur->val;
                cur = cur->next;
                i++;
            }
            for(int i=t/2;i<t;i++)
            {
                cout << arr[i] << " ";
            }
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
        int arr[t];
        for(int i=0 ; i<t; i++)
        {   
            cin >> temp;
            a.PushBack(temp);
        }
        a.Copy(t);
        return 0;
    }