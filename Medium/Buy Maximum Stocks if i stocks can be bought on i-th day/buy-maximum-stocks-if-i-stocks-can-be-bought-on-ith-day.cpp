//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        multimap<int, int> mp;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            mp.insert({price[i], i + 1}); 
        }
        
        for (auto it : mp) {
            if (k >= it.first) {
                if (k / it.first <= it.second) {
                    ans += k / it.first;
                    k = k % it.first;
                }
                else {
                    ans += it.second;
                    k -= it.first * it.second;
                }
            }
            else {
                break;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends