//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        if(nums.size()&1)return false;
        int arr[k]={0};
        for(auto it:nums){
            arr[it%k]+=1;
        }
        for(int i=0;i<k;i++){
            if(i==0){
                if(arr[i]&1)return false;
                else continue;
            }
            if(i==k-i){
                if(arr[i]&1)return false;
            }
            if(arr[i]!=arr[k-i])return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends