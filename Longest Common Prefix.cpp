class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string a = strs[0];
        string c="";
        string b = strs[strs.size()-1];
        for(int i=0;i<a.size();i++){
            if(a[i]==b[i])
                c+=a[i];
            else
                break;
        }
        return c;
    }
};
