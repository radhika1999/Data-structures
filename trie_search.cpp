#include<iostream>
using namespace std;
struct TrieNode{
    char data;
    struct TrieNode* children[26];
    bool isTerminal;
    TrieNode(char x){
        data=x;
        isTerminal=false;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};
void insert(TrieNode* root, string s){
    int n=s.length();
    if(n==0){
        root->isTerminal=true;
        return;
    }
    int i=s[0]-'a';
    TrieNode* child;
    if(root->children[i]!=NULL){
        child=root->children[i];
    }
    else{
        child=new TrieNode(s[0]);
        root->children[i]=child;
    }
    insert(child, s.substr(1));
}
bool search(TrieNode* root, string s){
    int n=s.length();
    if(n==0){
        return root->isTerminal;
    }
    int i=s[0]-'a';
    if(root->children[i]!=NULL){
        return search(root->children[i], s.substr(1));
    }
    else{
        return false;
    }
}
int main(){
    TrieNode* root=new TrieNode('-');

}
