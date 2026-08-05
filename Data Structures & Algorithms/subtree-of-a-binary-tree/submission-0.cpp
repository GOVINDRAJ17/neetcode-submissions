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
    bool issame(TreeNode* p,TreeNode* q){
        if(p==nullptr && q==nullptr){
            return true;
        }
        if(p==nullptr ||q==nullptr){
            return false;
        }
        if(p->val != q->val){
            return false;
        }
        return issame(p->left,q->left) && issame(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(root==nullptr){
            return false;
        }
        if(issame(root,subroot)){
            return true;
        }
        return isSubtree(root->left,subroot)||
        isSubtree(root->right,subroot);
    }
    
};
