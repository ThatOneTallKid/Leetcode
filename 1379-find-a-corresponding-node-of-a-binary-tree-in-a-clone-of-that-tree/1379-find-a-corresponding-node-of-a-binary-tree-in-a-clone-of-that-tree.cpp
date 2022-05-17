/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *ans , *ta;
    void inorder(TreeNode *o, TreeNode *c){
        if(o != NULL)
        {
            inorder(o->left, c->left);
            if(o->val == ta->val){
                ans = c;
            }
            inorder(o->right, c->right);
        }
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        ta = target;
        inorder(original, cloned);
        return ans;
    }
};