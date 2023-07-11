#include<vector>
#include<string>
#include<iostream>
#pragma
using namespace std;


class Trie{
        public:
        Trie* map[26];
        bool isTerminal;
    };
    void insert(Trie* root,string word){
        Trie* node = root;
        for(int i = 0;i<word.length();i++){
            char c = word[i];
             if(!node->map[c-'a']){
                 node->map[c-'a'] = new Trie();
             }
            node = node->map[c-'a'];
        }
        node->isTerminal = true;
    }
    bool search(string word,Trie* root,int idx,int words = 0){
        if(idx == word.length()) return words > 1;
        Trie* node = root;
        for(int i = idx;i<word.length();i++){
            char c = word[i];
            if(!node->map[c-'a']) return false;
            node = node->map[c-'a'];
            if(node->isTerminal){
                if(search(word,root,i+1,words+1)) return true;
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie* root = new Trie();
        for(int i = 0;i<words.size();i++){
            string word = words[i];
            insert(root,word);
        }
        vector<string> ans;
        for(int i =0;i<words.size();i++){
            string word = words[i];
            if(search(word,root,0)) ans.push_back(word);
        }
        return ans;
    }
    int main(){
        string words[] = {"cat","cats","rats","catratsdog","dog","ratdogcat"};
        vector<string> v;
        for(int i = 0;i<words->size();i++){
            v.push_back(words[i]);
        }
        vector<string> ans = findAllConcatenatedWordsInADict(v);
        for(string word : ans){
            cout<<word<<" ";
        }
        cout<<endl;
        return ans.size();
    }