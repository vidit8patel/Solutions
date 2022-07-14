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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIndex = 0;
        return build(preorder, inorder, rootIndex, 0, inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int&rootIndex, int beg, int end)
    {
        if(beg > end)
            return NULL;
        int pivot = 0;
        while(inorder[pivot] != preorder[rootIndex])
            pivot++;
        rootIndex++;
        TreeNode* newTree = new TreeNode(inorder[pivot]);
        newTree->left = build(preorder, inorder, rootIndex, beg, pivot-1);
        newTree->right = build(preorder, inorder, rootIndex, pivot+1, end);
        return newTree;
    }
};