//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
	    // code here
	     long long result=0;
        for(int i=0;i<32;i++){
            long long countOne=0;
            long long countZeros=0;
            for(int j=0;j<n;j++){
                if(arr[j] & (1<<i))
                    countOne++;
               else
                    countZeros++;
            }
            result+=countOne*(countZeros)*2;
        }
        return result;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends