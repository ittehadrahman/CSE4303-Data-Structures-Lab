#include<bits/stdc++.h>
int status=0;

using namespace std;

class BST {
    
    struct node 
    {
        int val;
        node* left;
        node* right;
    };

    node* root;

    node* bstInsert(int x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->val = x;
            t->left = t->right = NULL;
        }
        else if(x < t->val && (((t->val) - x) > 3))
        {
            t->left = bstInsert(x, t->left);
        }
        else if(x > t->val && ((x-(t->val)) > 3))
        {
            t->right = bstInsert(x, t->right);
        }
        else
        {
            status = 1;
        }
        return t;
    }


    void inorder(node* t) 
    {
        if(t == NULL)
        {
            return;
        }
        inorder(t->left);
        cout << t->val << " ";
        inorder(t->right);
    }

    node* find(node* t, int x) 
    {
        if(t == NULL)
        {
            return NULL;
        }
        else if(x < t->val)
        {
            return find(t->left, x);
        }
        else if(x > t->val)
        {
            return find(t->right, x);
        }
        else
        {
            return t;
        }
    }

public:
    BST() {
        root = NULL;
    }

    void bstInsert(int x) {
        root = bstInsert(x, root);
    }

    void display() {
        inorder(root);
        cout << endl;
    }

    void search(int x) {
        root = find(root, x);
    }
};


int main()
{
    BST airport;
    
    while(true){
        int x;
        cin>>x;
        if(x == -1){
            break;
        }
        airport.bstInsert(x);
        airport.display();
        if(status == 1)
        {
            status = 0;
            cout<< "(Reservation failed)" << endl;
        }
    }
    return 0;
}