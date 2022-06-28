// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<bool> mst(V,0);
        vector<int> key(V, INT_MAX);
        vector<int> parent(V);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        parent[0] = -1;
        key[0]= 0;
        pq.push({0,0});
        while(!pq.empty())
        {
            int node = pq.top().second;
            pq.pop();
            mst[node] = true;
            for(auto it: adj[node])
            {
                int x = it[0];
                int weight = it[1];
                if(mst[x] == false && weight < key[x])
                {
                    key[x] = weight;
                    parent[x] = node;
                    pq.push({key[x], x});
                }
            }
        }
        int sum = 0;
        for(int i = 0; i<V; i++)
            sum += key[i];
            return sum;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends