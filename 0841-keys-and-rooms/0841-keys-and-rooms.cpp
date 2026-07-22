class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // first make an adj list

        vector<bool> vis(rooms.size(), false);
        queue<int> q;
        int source = 0;
        q.push(0);
        vis[0] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int i = 0; i < rooms[node].size(); i++) {
                int neighbour = rooms[node][i];

                if (!vis[neighbour]) {
                    vis[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        for (int i = 0; i < vis.size(); i++) {
            if (vis[i] == false) {
                return false;
            }
        }
        return true;
    }
};