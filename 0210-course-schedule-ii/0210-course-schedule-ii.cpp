class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>res;
    

        //adj list //directed graph
        vector<vector<int>>adj(numCourses);
        
        for(auto &it :prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        //indegree
        vector<int> indeg(numCourses, 0);
        for(int i =0; i< numCourses; i++){
            for(int neigh : adj[i]){
                indeg[neigh]++;
            }
        }

        queue<int>q;
        for(int i =0; i<numCourses; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        

        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);

            for(int i =0; i<adj[node].size(); i++){
                int neigh = adj[node][i];

                indeg[neigh]--;
                if(indeg[neigh] == 0){
                    q.push(neigh);
                    
                }
            }
            
        }

        if(res.size() == numCourses){
            return res;
        }
        else{
            return {};
        }
        
    }
};