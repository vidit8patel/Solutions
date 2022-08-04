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
    void makeParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* current = q.front();
            q.pop();
            if(current->left != NULL)
            {
                parent[current->left] = current;
                q.push(current->left);
            }
            if(current->right != NULL)
            {
                parent[current->right] = current;
                q.push(current->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*, TreeNode*> parent;
        makeParent(root, parent);
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;
        q.push(target);
        visited[target] = true;
        int distance = 0;
        while(!q.empty())
        {
            int size = q.size();
            if(distance++ == k)
                break;
            for(int i = 0; i<size; i++)
            {
                TreeNode* curr = q.front(); 
                q.pop();
                if(curr->left && !visited[curr->left])
                {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if(curr->right && !visited[curr->right])
                {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if(parent[curr] && !visited[parent[curr]])
                {
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
            }
        }
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};









// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     map<TreeNode*, int> map;
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//         vector<int> ans;
//         find(root, target);
//         dfs(root, target, k, map[root], ans);
//         return ans;
//     }
//     int find(TreeNode* root, TreeNode* target)
//     {
//         if(root == NULL)
//             return -1;
//         if(root == target)
//         {
//             map[root] = 0;
//             return 0;
//         }
//         int left = find(root->left, target);
//         if(left >= 0)
//         {
//             map[root] = left+1;
//             return left+1;
//         }
//         int right = find(root->right, target);
//         if(right >= 0)
//         {
//             map[root] = right+1;
//             return right+1;
//         }
//         return -1;
//     }
//     void dfs(TreeNode* root, TreeNode* target, int k, int length, vector<int> &ans)
//     {
//         if(root == NULL)
//             return;
//         if(map.find(root) != map.end())
//             length = map[root];
//         if(length == k)
//             ans.push_back(root->val);
//         dfs(root->left, target, k, length+1, ans);
//         dfs(root->right, target, k, length+1, ans);
//     }
// };