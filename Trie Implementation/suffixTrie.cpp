#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
     char data;
     int wordCount;
     TrieNode* child[26];

     TrieNode() {
          data = '*';
          wordCount = 0;
          for(int i=0; i<26; ++i) {
               child[i] = nullptr;
          }
     }
};

class SuffixTrie {
public:
     TrieNode *root;
     SuffixTrie() {
          root = new TrieNode();
     }

     // babc
     void createSuffixTrie(string str) {
          for(int i=0; i<str.length(); ++i) {
               insertSubstring(str, i);
          }
     }

     void insertSubstring(string str, int i) {
          TrieNode *parent = root;
          for(int j=i; j<str.length(); ++j) {
               int idx = str[j] - 'a';
               if(parent->child[idx] == NULL) {
                    parent->child[idx] = new TrieNode();
               }
               parent->child[idx]->data = str[j];
               parent = parent->child[idx];
          }
          ++parent->wordCount;
     }

     bool containsSuffix(string suffix) {
          TrieNode *parent = root;
          for(int i=0; i<suffix.size(); ++i) {
               int idx = suffix[i] - 'a';
               if(parent->child[idx] == NULL) {
                    return false;
               }
               parent = parent->child[idx];
          }
          return parent->wordCount != 0 ? true : false;
     }
};

int main() {
     SuffixTrie *S = new SuffixTrie();
     S->createSuffixTrie("babc");

     // All possible suffixes
     cout << S->containsSuffix("babc") << endl;
     cout << S->containsSuffix("abc") << endl;
     cout << S->containsSuffix("bc") << endl;
     cout << S->containsSuffix("c") << endl;


     // Not a suffix
     cout << S->containsSuffix("ab") << endl;
     cout << S->containsSuffix("bab") << endl;
     cout << S->containsSuffix("ab") << endl;
     return 0;
}