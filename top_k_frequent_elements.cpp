class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto each: nums)
        {
            mp[each]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;

        for(auto each: mp)
        {
            heap.push(make_pair(each.second,each.first));
            if(heap.size()>k)
                heap.pop();
        }
        
        vector<int> res;
        while(not heap.empty())
        {
            res.push_back(heap.top().second);
            heap.pop();
        }
        
        return res;
    }
};
