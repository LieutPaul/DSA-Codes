#include<iostream>
#include<vector>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *generateTree(vector<int>& nums,int l,int r){
    if(l>r){
        return NULL;
    }
    int mid=(l+r)/2;
    struct node *root = (struct node*) malloc(sizeof(struct node));
    root->data=nums[mid];
    root->left=generateTree(nums,l,mid-1);
    root->right=generateTree(nums,mid+1,r);
    return root;
}
void preorder(struct node *root, vector<int> &ans){
    if(!root){
        return;
    }
    ans.push_back(root->data);
    preorder(root->left,ans);
    preorder(root->right,ans);
    
}
vector<int> sortedArrayToBST(vector<int>& nums) {
    struct node*root=generateTree(nums,0,nums.size()-1);
    vector<int> ans;
    preorder(root,ans);
    return ans;
}