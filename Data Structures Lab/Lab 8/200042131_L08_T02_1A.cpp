#include <bits/stdc++.h>
using namespace std;
 
const int ALPHABET_SIZE = 26;
 

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        pNode->children[i] = NULL;
    }
    return pNode;
}

void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
 
        pCrawl = pCrawl->children[index];
    }

    pCrawl->isEndOfWord = true;
}
 
bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
        {
            return false;
        }
        else
        {
            pCrawl = pCrawl->children[index];
        }
    }
 
    return (pCrawl->isEndOfWord);
}
 
int main()
{
    string products[] = {"mobile","mouse","moneypot","monitor","mousepad"};
    int n = sizeof(products)/sizeof(products[0]);
    struct TrieNode *root = getNode();
    for (int i = 0; i < n; i++)
    {
        insert(root, products[i]);
    }
    for (int i = 0; i < n; i++)
    {
        string word = products[i];
        for(int j=i+1;j<n;j++)
        {
            string word1 = products[j];
            if(word[0]==word1[0])
            {
                for(int k=j+1;k<n;k++)
                {
                    string word2 = products[k];
                    if(word1[0]==word2[0])
                    {
                        cout<< word << " " << word1 << " " << word2 << endl;
                    }
                }
            }
        }
    }

    return 0;
}