//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        unordered_set<int>st;
        st.insert(0);
        vector<int>ans;
        ans.push_back(0);
        int prev=0;
        for(int i=1; i<=n; i++){
            int temp=prev-i;
            if(temp<0 || st.find(temp)!=st.end()){
                temp=prev+i;
            }
            st.insert(temp);
            ans.push_back(temp);
            prev=temp;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends