//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    static int setSetBit(int x, int y, int l, int r){
        int couple=0;
        for(int i=l-1; i<=r-1; i++){
            int mask= 1<<i;
            
            int result= y & mask;
            
            if(result!=0){
                couple= couple | mask;
            }
        }
        
        return x | couple;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends