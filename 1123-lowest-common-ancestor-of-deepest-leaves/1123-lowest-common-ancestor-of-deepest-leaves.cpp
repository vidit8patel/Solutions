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
    int maxDepth(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    TreeNode* lca(TreeNode* root, int depth, int curr)
    {
        if(root == NULL)
            return NULL;
        if(curr == depth)
            return root;
        TreeNode* left = lca(root->left, depth, curr+1);
        TreeNode* right = lca(root->right, depth, curr+1);
        if(left == NULL)
            return right;
        if(right == NULL)
            return left;
        return root;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
        int depth = maxDepth(root)-1;
        return lca(root, depth, 0);
    }
};