#include<bits/stdc++.h>

using namespace std;

class BST {
    
    struct node {
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

    int maxDepth(node* t)
    {
        if (t == NULL)
        {
            return 0;
        }
        else 
        {
            /* compute the depth of each subtree */
            int lDepth = maxDepth(t->left);
            int rDepth = maxDepth(t->right);
    
            /* use the larger one */
            if (lDepth > rDepth)
            {
                return (lDepth + 1);
            }
            else
            {
                return (rDepth + 1);
            }
        }
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

    void search(int x)
    {
        root = find(root, x);
    }
    int maxHeight()
    {
        return maxDepth(root) - 1;
    }
};


int main()
{    
    BST General;
    while(true)
    {
        int x;
        cin >> x;
        if(x == -1)
        {
            break;
        }
        General.bstInsert(x);    
    }
    cout<<General.maxHeight()<<endl;
    return 0;
}