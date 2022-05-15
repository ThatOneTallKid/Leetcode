/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    
    
    int level(TreeNode * root, int k, int cur){
        
        if(!root)
            return 0;
        
        if(cur == k-1)
            return root->val;
        
        return level(root->left,k,cur+1) + level(root->right, k, cur+1);
    }
    
    int height(TreeNode *root){
        if(root== NULL)
            return 0;
        
        return max(height(root->left), height(root->right))+1;
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int h = height(root);
        int sum = level(root,h,0);
        return sum;
    }
};