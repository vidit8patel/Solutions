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
    vector<string> binaryTreePaths(TreeNode* root)
    {
        string path;
        vector<string> ans;
        if(root == NULL)
            return ans;
        solve(root, "", ans);
        return ans;
    }
    void solve(TreeNode* root, string path, vector<string>& ans)
    {
        if(root->right == NULL && root->left == NULL)
            ans.push_back(path + to_string(root->val));
        if(root->left != NULL)
            solve(root->left, path + to_string(root->val) + "->", ans);
        if(root->right != NULL)
            solve(root->right, path + to_string(root->val) + "->", ans);
    }
};