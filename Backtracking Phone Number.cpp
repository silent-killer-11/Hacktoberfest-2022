#include <iostream>
    #include <vector>
    using namespace std;

      vector<string> ans;
      string hashh[10] = {"", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };

      void fun(string digits, int index, string state)
      {
        if(index == (int)digits.size()) {
          ans.push_back(state);
         // cout<<state<<" ";
          return;
        }
        string digit = hashh[digits[index]-'0'];
        for(int i=0;i<(int)digit.length();++i)
        {
          state += digit[i];
          fun(digits, index+1, state);
          state.pop_back();
        }
      }

    int main()
    {
      int t;
      cin>>t;
      while(t--)
      {
        ans.clear();
      string str;
      cin>>str;
      if(str.empty()) return{};
        fun(str, 0, "");
      for(int i=0;i<ans.size();i++)
       cout<<ans[i]<< " ";
      cout<<endl;
      }

      return 0;
    }
