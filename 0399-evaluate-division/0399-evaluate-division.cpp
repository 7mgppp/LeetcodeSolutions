class Solution {
private:

    double bfs(string start, string target,
               unordered_map<string, vector<pair<string, double>>>& graph) {

        
        if (graph.find(start) == graph.end() ||
            graph.find(target) == graph.end()) {
            return -1.0;
        }

        queue<pair<string, double>> q;
        unordered_set<string> visited;

        q.push({start, 1.0});
        visited.insert(start);

        while (!q.empty()) {

            auto [curr, value] = q.front();
            q.pop();

            
            if (curr == target) {
                return value;
            }

            
            for (auto [neighbor, weight] : graph[curr]) {

                if (!visited.count(neighbor)) {

                    visited.insert(neighbor);

                    q.push({
                        neighbor,
                        value * weight
                    });
                }
            }
        }

        
        return -1.0;
    }


public:

    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries) {

        
        unordered_map<string, vector<pair<string, double>>> graph;

        for (int i = 0; i < equations.size(); i++) {

            string a = equations[i][0];
            string b = equations[i][1];
            double value = values[i];

            
            graph[a].push_back({b, value});

            
            graph[b].push_back({a, 1.0 / value});
        }


      
        vector<double> answer;

        for (auto& query : queries) {

            string start = query[0];
            string target = query[1];

            answer.push_back(
                bfs(start, target, graph)
            );
        }

        return answer;
    }
};