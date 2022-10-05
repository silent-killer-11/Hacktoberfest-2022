class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            vector<int>temp(i+1,1);
            for(int j=1;j<i;j++){
                temp[j]=res[i-1][j]+res[i-1][j-1];
            }
            res.push_back(temp);
        }
        return res;
    }
};
