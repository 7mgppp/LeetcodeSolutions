class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<vector<int>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        queue<int> q;

        q.push(source);
        vis[source]=true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(node == destination){
                return true;
            }

            for(auto neighbour : adj[node]){
                if(!vis[neighbour]){
                    vis[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        return false;
    }
};