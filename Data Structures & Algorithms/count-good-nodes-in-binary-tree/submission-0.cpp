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
    int dfs(TreeNode* root,int maxvalue){
        if(root==nullptr)
            return 0;
        int count=0;
        if(root->val >= maxvalue){
            count=1;
        }

        maxvalue=max(maxvalue,root->val);
        count += dfs(root->left,maxvalue);
        count += dfs(root->right,maxvalue);
        return count;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
};
