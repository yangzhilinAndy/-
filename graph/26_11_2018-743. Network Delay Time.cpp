//The problem is not difficult, but it is a good practice to implement Dijkstra's algo using c++ STL container

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        typedef pair<int, int> edge; //adjacency list: (endnode, weight)
        vector<edge> adj[200];
        for (auto elem: times)
            adj[elem[0]].push_back(make_pair(elem[1], elem[2]));
        
        int dist[200]; //distance array (node, dist)
        typedef pair<int, int> node; //(dist, node)
        priority_queue<node, vector<node>, greater<node>> hp; //min heap
        for (int v=1; v<=N; v++)
        {
            if (v!=K)
            hp.push(make_pair(INT_MAX, v));
            else
            hp.push(make_pair(0, v));
            dist[v]=INT_MAX;
        }
        dist[K]=0;     
        while(!hp.empty())
        {
            node u=hp.top(); //delete min
            hp.pop();
            for (auto v: adj[u.second])
                if (dist[v.first]>dist[u.second]+v.second)
                {
                    dist[v.first]=dist[u.second]+v.second;
                    hp.push(make_pair(dist[v.first], v.first));
                    //!!!!! Here: no need to delete the old element in the min heap, just push the new dist
                }
        }
        
        int max_time=0;
        for (int v=1; v<=N; v++)
            if (max_time<dist[v])
                max_time=dist[v];
        
        if (max_time==INT_MAX)
            return -1;
        return max_time;
    }
};
