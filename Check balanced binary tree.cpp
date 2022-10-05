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
    int h(TreeNode* root){
        if(!root)
            return 0;
        return 1+max(h(root->left),h(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return 1;
        return abs(h(root->left)-h(root->right))<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
