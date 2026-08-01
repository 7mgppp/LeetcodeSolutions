class Solution {
private:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& vis) {
        // base condition
        // no base condition recursion stops when all the nodes are visited

        // mark visited
        vis[node] = 1;

        // explore all neighbours
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[node][i] == 1 && !vis[i]) {
                dfs(i, isConnected, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        vector<int> visited(isConnected.size(), 0);

        for (int i = 0; i < isConnected.size(); i++) {
            if (!visited[i]) {
                count++;
                dfs(i, isConnected, visited);
            }
        }

        return count;
    }
};