//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        int prefixMin[n];
        prefixMin[0] = arr[0];

        for(int i = 1; i < n; i++){
            prefixMin[i] = min(prefixMin[i-1], arr[i]);
        }


        int r,l,maxDist = INT_MIN;
        r = l = n-1;

        while(r >= 0 && l >= 0){
            if(arr[r] >= prefixMin[l]){
                maxDist = max(maxDist, (r-l));
                l--;
            }else{
                r--;
            }

        }
        return maxDist;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends