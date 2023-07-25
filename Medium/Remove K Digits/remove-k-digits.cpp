//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int K) {
          int n = S.size();
    stack<char> st;
    int i;
   for(i = 0 ;i <n;i++)
    {
        if(st.size() == 0 || st.top() <= S[i] || K==0)
        {
            st.push(S[i]);
        }
        else {
            while(st.size()!=0 && st.top() > S[i] && K!=0)
                {
                    st.pop();
                    K--;
                }
            st.push(S[i]);
        }
        
        if(st.size()==1 && st.top()=='0')
            st.pop();
    }
    if(st.size() == 0)
        return "0";
    
    while(!st.empty() && K!=0)
    {
        st.pop();
        if(st.size()==0)
            return "0";
        K--;
    }
    
    
     while(!st.empty()){
         
         S[n-1] = st.top();
         st.pop();
         n--;
         
     }
     return S.substr(n);
    
    }



};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends