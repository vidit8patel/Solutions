class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[101];
        for(int i = 0; i<times.size(); i++)
        {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        
        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> q;
        q.push({0, k});
        dist[k] = 0;
        while(!q.empty())
        {
            int node = q.top().second;
            int len = q.top().first;
            q.pop();
            for(auto it: adj[node])
            {
                if(len + it.second < dist[it.first])
                {
                    dist[it.first] = len + it.second;
                    q.push({dist[it.first], it.first});
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1; i<=n; i++)
        {
            ans = max(ans, dist[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};