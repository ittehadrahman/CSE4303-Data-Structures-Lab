#include<bits/stdc++.h>

using namespace std;

class BST {
    
    struct node {
        int val;
        node* left;
        node* right;
        node* parent;
    };

    node* root;

    node* bstInsert(int x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->val = x;
            t->left = t->right = NULL;
            t->parent = NULL;
        }
        else if(x < t->val && (((t->val) - x) > 3))
        {
            node* leftChild = bstInsert(x, t->left);
            t->left = leftChild;
            leftChild->parent = t;
        }
        else if(x > t->val)
        {
            node* rightChild = bstInsert(x, t->right);
            t->right = rightChild;
            rightChild->parent = t;
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
    
    int subtree_size(node* t)
    {
        int x = 0;
        int y = 0 ;
        if(t != nullptr)
        {
            x=subtree_size(t->left);
            y=subtree_size(t->right);
            return x + y + 1;
        }
        return 0;
    }

    int previous_reservations(node* t)
    {
        int cnt = 0;
        cnt += subtree_size(t->left);
        while(t->parent != nullptr && t->parent->right == t)
        {
            t = t->parent;
            cnt += (subtree_size(t->left) + 1);
        }
        return cnt;
    }

public:
    BST() {
        root = NULL;
    }

    void bstInsert(int x) 
    {
        root = bstInsert(x, root);
    }

    void display() 
    {
        inorder(root);
        cout << endl;
    }

    int reservations(int x)
    {
        return previous_reservations(find(root,x));
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
        int n;
        cin >> n;
        cout << airport.reservations(n)<<endl;
    }
    return 0;
}