// insert, delete, searchPrefix, searchWord, 
#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char data;
    int wordCount;
    int prefixCount;
    TrieNode *child[26];

    // Constructor
    TrieNode() {
        data = '*';
        wordCount = 0;
        prefixCount = 0;
        for(int i=0; i<26; ++i) {
            child[i] = NULL;
        }
    }
};

class Trie {
public:
    TrieNode *root;

    // Constructor
    Trie() {
        root = new TrieNode();
    }


    // member functions
    
    // insert Word in Trie
    void insertWord(string str) {
        TrieNode *parent = root;
        for(int i=0; i<str.length(); ++i) {
            int idx = str[i]-'a';
            if(parent->child[idx] == NULL) {
                parent->child[idx] = new TrieNode();
            }
            ++parent->child[idx]->prefixCount;
            parent->child[idx]->data = str[i];
            parent = parent->child[idx];
        }
        parent->wordCount += 1;
    }

    // find if word is in dictionary
    bool searchWord(string str) {
        TrieNode *parent = root;
        for(int i=0; i<str.length(); ++i) {
            int idx = str[i] - 'a';
            if(parent->child[idx] == NULL) {
                return false;
            }
            parent = parent->child[idx];
        }
        return parent->wordCount ? true : false;
    }

    // search Prefix is present or not
    // search how many words of that prefix occours
    int searchPrefix(string prefix) {
        TrieNode *parent = root;
        for(int i=0; i<prefix.length(); ++i) {
            int idx = prefix[i] - 'a';
            if(parent->child[idx] == NULL) {
                return 0;
            }
            parent = parent->child[idx];
        }
        return parent->prefixCount;
    }

    // delete Word from trie
    void deleteWord(string str) {
        // first search if the word is present or not
        if(searchWord(str)) {
            // if found go reduce the final wordCount and while traversing reduce prefixCount
            TrieNode *parent = root;
            for(int i=0; i<str.length(); ++i) {
                int idx = str[i] - 'a';
                --parent->child[idx]->prefixCount;
                parent = parent->child[idx];
            }
            --parent->wordCount;
        }
        // word is now deleted
    }
};


int main() {
    Trie *T = new Trie();

    // operations on Trie
    // insert
    T->insertWord("ayush");
    T->insertWord("chris");
    T->insertWord("christopher");
    T->insertWord("ian");
    T->insertWord("david");

    // search 
    cout << T->searchWord("dav") << endl;
    cout << T->searchWord("ayush") << endl;
    cout << T->searchWord("christ") << endl;

    // search prefixes
    cout << T->searchPrefix("ayu") << endl;
    cout << T->searchPrefix("chris") << endl;
    cout << T->searchPrefix("ie") << endl;

    // delete 
    T->deleteWord("ayush"); 
    T->searchWord("ayush") == 0 ? cout << "Not found" : cout << "found";
}