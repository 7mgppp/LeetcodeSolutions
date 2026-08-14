class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //detect cycle in D A G 
        //Topological Sort

        vector<vector<int>>adj(numCourses);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int>indegree(numCourses, 0);
        for(int i =0; i<numCourses; i++){
            for(int j =0; j < adj[i].size(); j++){
                int neigh = adj[i][j];
                indegree[neigh]++;
            }
        }

        queue<int>q;
        for(int i = 0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> OrderList;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            OrderList.push_back(node);

            for (int i = 0; i < adj[node].size(); i++) {
                int neigh = adj[node][i];

                indegree[neigh]--;
                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        if(OrderList.size() == numCourses){
            return OrderList;
        }
        else{
            return {};
        }

        
    }
};