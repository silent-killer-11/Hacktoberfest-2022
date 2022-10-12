class Solution {
public:
    bool checkCycle(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& currVis)
    {
        vis[node] = 1;
        currVis[node] = 1;
        for(auto each: adj[node])
        {
            if(not vis[each])
            {
                if(checkCycle(each,adj,vis,currVis))
                    return true;
            }
            else if(currVis[each]==1)
            {
                    return true;
            }
        }
        currVis[node] = 0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
      
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        vector<int> currVis(n,0);
        
        //build graph -
        for(auto each: prerequisites)
        {
            adj[each[1]].push_back(each[0]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(not vis[i])
            {
                if(checkCycle(i,adj,vis,currVis))
                    return false;
            }
        }
        return true;
    }
};
