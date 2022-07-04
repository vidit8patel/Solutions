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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> map;
        for (int i=0;i<inorder.size();++i)
            map[inorder[i]] = i;
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1,map);
    }
    TreeNode* build(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, unordered_map<int,int> &map)
    {
        if (ps>pe || is>ie) 
            return NULL;
        TreeNode* root = new TreeNode(postorder[pe]);
        int pivot = map[postorder[pe]];
        root->left = build(inorder, is, pivot-1, postorder, ps, ps+pivot-is-1, map);
        root->right = build(inorder, pivot+1, ie, postorder, ps+pivot-is, pe-1, map);
        return root;
    }
};