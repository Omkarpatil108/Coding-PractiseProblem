//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long x) {
        // code here
         vector<int> v;
        
        while(x!=0)
        {
            v.push_back(x%2);
            x=x/2;
        }
        
        reverse(v.begin(),v.end());
        int p=v.size();
        
        vector<int> ans;
        
        for(int i=0;i<32-p;i++)
        {
              ans.push_back(0);
        }
        
        int j=0;
        for(int i=32-p;i<32;i++)
        {
            ans.push_back(v[j]);
            j++;
        }
        
        // reverse(ans.begin(),ans.end());
         
         long long a=0;
        for(int i=0;i<32;i++)
        {
            if(ans[i]==1)
              a=a+pow(2,i);
        }
        
        return a;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends