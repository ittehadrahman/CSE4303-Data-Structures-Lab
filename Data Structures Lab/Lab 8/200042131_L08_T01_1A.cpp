#include <bits/stdc++.h>

using namespace std;

class WordDictionary {
public:
    int trie[300005][50];
    int id = 1;
    int endmark[300005];
    int pre[300005];
    WordDictionary() 
    {
        memset(trie,0,sizeof(trie));
        memset(endmark,0,sizeof(endmark));
        memset(pre,0,sizeof(pre));
        cout << "Object Created" <<endl;
    }

    void addWord(string word) 
    {
        int row = 1;
        for(int i = 0; i < word.size(); i++)
        {
            int ch = word[i] - 'a';
            if(trie[row][ch] == 0)
            {
                trie[row][ch] = ++id;
            }
            row = trie[row][ch];
            pre[row]++;
        }
        endmark[row] = 1;
        cout << "Word Added" << endl;
    }
   
    bool search(string word) 
    {
        int row = 1;
        for(int i = 0; i < word.size();i++)
        {
            if(word[i] == '.')
            {
                int temp = 0;
                for(int j=0;j<26;j++)
                {
                    if(trie[row][j]==1)
                    {
                        word[i]='a'+j;
                        temp=1;
                        break;
                    }
                }
                if(temp == 0)
                {
                    return false;
                }
                else if (temp==1)
                {
                    continue;
                }
                
            }
            int ch = word[i] - 'a';
            if(trie[row][ch] == 0) return false;
            row = trie[row][ch];
        }
        return (endmark[row] == 1);
    }
   
    bool startsWith(string prefix) 
    {
        int row = 1;
        for(int i = 0; i < prefix.size();i++)
        {
            int ch = prefix[i] - 'a';
            if(trie[row][ch] == 0) return false;
            row = trie[row][ch];

        }
        return (pre[row] >= 1);
    }
};

int main(){
    WordDictionary* trie = new WordDictionary();
    trie->addWord("bad");
    trie->addWord("dad");
    trie->addWord("mad");
    bool search1 = trie->search("pad");
    if(search1==true)
    {
        cout << "Word Found" << endl;
    }
    else
    {
        cout << "Word Not Found" << endl;
    }
    bool search2 = trie->search("bad");
    if(search2==true)
    {
        cout << "Word Found" << endl;
    }
    else
    {
        cout << "Word Not Found" << endl;
    }
    bool prefix = trie->startsWith("b..");
    if(prefix==true)
    {
        cout << "Word Found" << endl;
    }
    else
    {
        cout << "Word Not Found" << endl;
    }
    bool prefix1 = trie->search(".ad");
    if(prefix1==true)
    {
        cout << "Word Found" << endl;
    }
    else
    {
        cout << "Word Not Found" << endl;
    }
    return 0;
}