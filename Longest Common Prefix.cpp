class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string a = strs[0];
        string ctr="";
        string b = strs[strs.size()-1];
        for(int i=0;i<a.size();i++){
            if(a[i]==b[i])
                ctr+=a[i];
            else
                break;
        }
        return ctr;
    }
};
