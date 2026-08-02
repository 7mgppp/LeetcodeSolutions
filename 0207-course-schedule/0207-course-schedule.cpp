class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int count = 0;

        //adjency list
        vector<vector<int>> adj(numCourses);
        for (auto& it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        //count indegree
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (int neigh : adj[i]) {
                indegree[neigh]++;
            }
        }


        queue<int> q;

        //push all the nodes with indegree = 0 in queue
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        //bfs
        while(!q.empty()){
            int node = q.front();
            q.pop();

            
            for(int i = 0; i < adj[node].size(); i++){
                int neigh = adj[node][i];

                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
                
            }
            count++;

        }

        return numCourses == count;

    }
};