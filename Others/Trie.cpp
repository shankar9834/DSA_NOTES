// 14 june 2023
// Author -- shankar wangwad

#include <bits/stdc++.h>
using namespace std;


class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char c)
    {
        data = c;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};



class Trie
{

public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // Assuming all characters to be capital
        int index = word[0] - 'A';

        TrieNode *child;
        if (root->children[index] != NULL)
        { // present
            child = root->children[index];
        }
        else
        { // absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }
  
    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

      
        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            // present

            child = root->children[index];
        }
        else
        {
            // absent
            return false;
        }

        return searchUtil(child, word.substr(1));
    
    }

   
    bool searchWord(string word)
    {
        return searchUtil(root, word);
   
    }

     void removeWordUtil(TrieNode* root,string word)
     {
           if(word.length()==0)
           {
             root->isTerminal=false;
          
            return ;
           }       
         

           int index=word[0]-'A';
           TrieNode *child;
          
           if(root->children[index]!=NULL)
           {
            //present
            child=root->children[index];

           }
           else{
            //absent
                 cout<<"The word doesn exit \n";
                 return ;
           }

           removeWordUtil(child,word.substr(1));

     }

   
    void removeWord(string word)
    {
            removeWordUtil( root, word);
     }

};



int main()
{

       Trie *t = new Trie();

       t->insertWord("SHANKAR");
       
       cout << "found the word : " << t->searchWord("SHANKAR") << endl;
      
       t->removeWord("SHANKAR");
    
       cout << "found the word : " << t->searchWord("SHANKAR") << endl;
    
    //  t->removeWord("SHANKA");
    
    return 0;
}