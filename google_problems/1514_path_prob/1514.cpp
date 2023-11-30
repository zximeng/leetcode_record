class Solution {
public:

    //bellman ford
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_n, int end_n) {

        vector<vector<pair<int, double>>> graph(n);
        vector<double> res(n, 0.0);
        res[start_n] = 1.0;

        for (int i = 0; i < edges.size(); i++) {
            int s = edges[i][0];
            int e = edges[i][1];
            double p = succProb[i];
            graph[s].push_back(e, p);
            graph[e].push_back(s, p);
        }
        
        for (int i = 0; i < n; i ++) {
            bool updated = false;
            for (int j = 0; j < n; j++) {
                for (const auto& e : graph[j]) {
                    if (res[j] * e.second> res[e.first]) {
                        updated = true;
                        res[e.first] = res[j] * e.second;
                    }
                }
            }
            if (!updated) {
                break;
            }
        }

        return res[end_n];
        
    }

};

class Solution {
public:
    // dijkstra
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_n, int end_n) {

        vector<vector<pair<int, double>>> graph(n);
        vector<double> res(n, 0.0);
        res[start_n] = 1.0;

        for (int i = 0; i < edges.size(); i++) {
            int s = edges[i][0];
            int e = edges[i][1];
            double p = succProb[i];
            graph[s].push_back(make_pair(e, p));
            graph[e].push_back(make_pair(s, p));
        }
        
        priority_queue<pair<double, int>> pq;
        pq.push(make_pair(1.0, start_n));

        while (!pq.empty()) {
            double p = pq.top().first;
            int s = pq.top().second;

            pq.pop();

            for (const auto& e: graph[s]) {

                if (p * e.second > res[e.first]) {
                    res[e.first] = p * e.second;
                    pq.push(make_pair(res[e.first], e.first));
                }
            }

        }

        return res[end_n];
        
    }
};