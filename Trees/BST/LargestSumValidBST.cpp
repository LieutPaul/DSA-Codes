#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    public:
    class Pair{
        public:
        int sum; 
        int maxi; 
        int mini; 
        bool isBST; 
    };
    Pair helper(TreeNode* root,int &res){
        if(root==NULL){
            Pair bp; // bp-> Base Pair
            bp.sum = 0;
            bp.maxi = INT_MIN;
            bp.mini = INT_MAX;
            bp.isBST = true; 
            return bp;
        }
        Pair lp = helper(root->left,res); // lp -> left pair
        Pair rp = helper(root->right,res); // rp -> right pair
        Pair resp; // resp -> resultant pair
        resp.mini = min(root->val,min(lp.mini,rp.mini)); 
        resp.maxi = max(root->val,max(lp.maxi,rp.maxi));
        bool flag = false;
        if(lp.isBST && rp.isBST && root->val>lp.maxi && root->val<rp.mini)
            flag=true;
        resp.isBST = flag;
        if(flag==false)
            resp.sum = -1e9;
        else{
            resp.sum = lp.sum+rp.sum+root->val;
            res = max(resp.sum,res);
        }
        return resp;
    }
    int maxSumBST(TreeNode* root) {
        int res = 0;
        helper(root,res);
        return res;
    }
};