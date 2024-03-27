#include<bits/stdc++.h>

using namespace std;

class BST {
    
    struct node {
        int data;
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

    void printLevelOrder(node* t)
    {
        int h = maxDepth(t);
        for (int i = 1; i <= h; i++)
        {
            printCurrentLevel(t, i);
        }
    }
 
    /* Print nodes at a current level */
    void printCurrentLevel(node* t, int level)
    {
        if (t == NULL)
        {
            return;   
        }
        if (level == 1)
        {
            cout << t->data << " ";
        }
        else if (level > 1) 
        {
            printCurrentLevel(t->left, level - 1);
            printCurrentLevel(t->right, level - 1);
        }
    }

    node* find(node* t, int x) {
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


    node* findMin(node* t)
    {
        if(t == NULL)
        {
            return NULL;
        }
        else if(t->left == NULL)
        {
            return t;
        }
        else
        {
            return findMin(t->left);
        }
    }


    node* remove(int x, node* t) 
    {
        node* temp;
        if(t == NULL)
        {
            return NULL;
        }
        else if(x < t->data)
        {
            t->left = remove(x, t->left);
        }
        else if(x > t->data)
        {
            t->right = remove(x, t->right);
        }
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
            {
                t = t->right;
            }
            else if(t->right == NULL)
            {
                t = t->left;
            }
            delete temp;
        }
        return t;
    }

public:
    BST() {
        root = NULL;
    }

    void bstInsert(int x) {
        root = bstInsert(x, root);
    }

    void display() {
        printLevelOrder(root);
        cout << endl;
    }

    void remove(int x) {
        root = remove(x, root);
    }
};

int main()
{
    BST airport;
    
    while(true)
    {
        int x;
        cin >> x;
        if(x == -1)
        {
            break;
        }
        airport.bstInsert(x);
    }
    airport.display();
    long long int x  = 1;

    while(x)
    { 
        cin >> x;
        airport.remove(x);
        airport.display();
    }
    return 0;
}