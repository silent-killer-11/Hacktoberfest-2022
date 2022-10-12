class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> sub(len);
        int globalMax=0;
        for(int i=0;i<len;i++)
        {
            sub[i] = (i==0?1:0); //base case
            int localMax = 0;
            for(int j=0;j<i;j++)
            {
                
                if(nums[j]<nums[i])
                {
                   localMax = max(sub[j],localMax);
                }
            }
            sub[i] = localMax+1;
            globalMax = max(sub[i],globalMax);
        }
        
        return globalMax;
    }
};
