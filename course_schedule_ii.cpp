class Solution {
public:
    
    bool checkCycle(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& dfsVis, vector<int>& res)
    {
        vis[node] = 1;
        dfsVis[node] = 1;
        for(auto each: adj[node])
        {
            if(not vis[each])
            {
                if(checkCycle(each, adj, vis, dfsVis, res))
                    return true;
            }
            else if(dfsVis[each] == 1)
            {
                return true;
            }
        }
        
        dfsVis[node] = 0;
        res.push_back(node);
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> res;
        vector<int> vis(n);
        vector<int> dfsVis(n);
        
        //build graph
        for(auto each: prerequisites)
        {
            adj[each[1]].push_back(each[0]);
        }
        
        //check for cycle
        for(int i=0;i<n;i++)
        {
            if(not vis[i])
            {
                if(checkCycle(i,adj,vis,dfsVis,res))
                {
                    return {};
                }
            }
        }
        
        reverse(res.begin(),res.end());
       
        return res; 
        
    }
};
