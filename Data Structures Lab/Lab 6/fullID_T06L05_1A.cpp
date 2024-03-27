#include<bits/stdc++.h>

using namespace std;

class BST { 

    struct node 
    {
        int data;
        int subTreeSize;
        node* left;
        node* right;
    };

    node* root;

    node* bstInsert(int x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
        {
            t->left = bstInsert(x, t->left);
        }
        else if(x > t->data)
        {
            t->right = bstInsert(x, t->right);
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
        cout << t->data << " ";
        inorder(t->right);
    }

    node* find(node* t, int x) 
    {
        if(t == NULL)
        {
            return NULL;
        }
        else if(x < t->data)
        {
            return find(t->left, x);
        }
        else if(x > t->data)
        {
            return find(t->right, x);
        }
        else
        {
            return t;
        }
    }

    int maxNum(node* t, int x)
    {
        int ans = 0;
        if(x <= t->data) 
        {
            ans = x;
        }
        if(x > t->data)
        {
            ans = x;
            while (t->data != x)
            {
                if(t->data > ans)
                {
                    ans = t->data;
                }
                if(t->data > x)
                {
                    t = t->left;
                }
                else
                {
                    t = t->right;
                }
            }
        }
        return ans;
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

    int findMaxNum(int x){
        return maxNum(root, x);
    }
};
 

int main()
{    
    BST airport;

    while(true)
    {
        int x;
        cin>>x;
        if(x == -1){
            break;
        }
        airport.bstInsert(x);
    }
    int t;
    cin >> t;
    while(t--)
    {        
        int x,y;
        cin >> x >> y;
        cout << airport.findMaxNum(y)<<endl; 
    }
    return 0;
}