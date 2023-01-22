#include<iostream>
using namespace std;
#define ll long long int
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
    ll isBSTUtil(TreeNode* node, ll min, ll max){
        if (node==NULL){
            return 1;
        }
        if (node->val < min || node->val > max){
            return 0;
        }
        return isBSTUtil(node->left, min, node->val-1) && isBSTUtil(node->right, node->val+1, max); 
    }
    bool isValidBST(TreeNode* root) {
        if(isBSTUtil(root,-1*(1e15),(1e15))){
            return true;
        }else{
            return false;
        }
    }
};