#include <iostream>
using namespace std;
#define MAX_HEIGHT 100000
struct Node{
    int data;
    Node *left;
    Node *right;
};
void solution(Node *root, int &s){
    if(root==NULL){
        return;
    }
    solution(root->right,s);
    s+=root->data;
    root->data=s;
    solution(root->left,s);
}
Node* modify(Node *root){
    int s=0;
    solution(root,s);
    return root;
}