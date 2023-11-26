//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:void push_to_vec(vector<int> &res,int N){
        if(N<=0){
            res.push_back(N);
            return;
        }
        res.push_back(N);      //pushes for first time while decreasing
        push_to_vec(res,N-5); //call for next number to push
        res.push_back(N);    //pushes for second time while increasing
        return;
    }
    vector<int> pattern(int N){
       vector<int> res;              //declaration
        push_to_vec(res,N);        //funtion call
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends