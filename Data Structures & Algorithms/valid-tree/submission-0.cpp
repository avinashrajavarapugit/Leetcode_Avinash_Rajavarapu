class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        /*
        dont have any cycles
        all the nodes are connected

        no of edges = 2 * (n - 1)
        no of nodes = n 

        bfs 
        vis
        */
        map<int, vector<int>> mp;
        for (auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        queue<int> q;
        q.push(0);
        int nodes = 1;
        int edgecnt = 0;
        set<int> vis;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vis.insert(u);
            for (int val: mp[u]) {
                edgecnt++;
                if (!vis.contains(val)) {
                    nodes++;
                    q.push(val);
                }
            }
        }
        return (edgecnt == 2 * (n - 1) && nodes == n);
    }
};
