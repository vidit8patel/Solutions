class Solution {
public:
    void dfs(vector<int> adj[], int node, vector<bool>& visited, int &c)
    {
        c++;
        visited[node] = true;
        for(auto it : adj[node])
        {
            if(!visited[it])
                dfs(adj, it, visited, c);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges)
    {
        vector<bool>visited(n, 0);
        vector<int> adj[n];
        long long count = 0, total = 0;
        for(auto edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                int c = 0;
                dfs(adj, i, visited, c);
                count += total*c;
                total += c;
            }
        }
        return count;
        
    }
  
};