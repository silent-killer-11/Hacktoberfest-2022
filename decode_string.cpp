class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        st.push(s[0]);
        int i = 0;
        while(i<s.length())
        {
            i++;
            
            if(i>=s.length())
                break;
            
            if(s[i]==']')
            {
                string temp = "";
                while(st.top()!='[')
                {
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();
                
                string times = "";
                while(!st.empty()&&isdigit(st.top()))
                {
                    times = st.top()+times;
                    st.pop();
                }
                
                cout<<times;
                string fin = "";
                for(int k=0;k<stoi(times);k++)
                {
                    fin = temp + fin;
                }
                for(int w=0;w<fin.length();w++)
                {
                    st.push(fin[w]);
                }
                
            }
            else
            {
                st.push(s[i]);
            }
        }
        
        string res = "";
        while(!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }
        
        return res;
    }
};
