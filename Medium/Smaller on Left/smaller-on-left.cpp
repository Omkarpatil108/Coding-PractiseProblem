//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> Smallestonleft(int arr[], int n);


int main() {
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n;
	    cin >> n;
	    int arr[n+1];
	    
	    for(int i=0;i<n;i++){
	        cin>> arr[i];
	    }
	    
	    vector<int> b;
	    b = Smallestonleft(arr, n);
	    for(int i=0;i<n;i++)
	        cout << b[i] << " ";
	       
	    cout << endl;
	    
	    
	}
	
	return 0;
}
// } Driver Code Ends


vector<int> Smallestonleft(int arr[], int n)
{
    // Complete the function
    // stack<int> st;
    // vector<int> ans(n);

    // for (int i = 0; i < n; i++) {
    //     while (!st.empty() && arr[i] <= st.top()) {
    //         st.pop();
    //     }

    //     if (st.empty()) {
    //         ans[i] = -1;
    //     } else {
    //         ans[i] = st.top();
    //     }

    //     st.push(arr[i]); // Push the current element into the stack for future comparisons
    // }

    // return ans;
    
    map<int,int> mp;
    mp[-1]++;
    vector<int> ans(n);
    for(int i=0; i<n; i++)
    {
        auto it = mp.end();
        --it;
        while(it->first >= arr[i])
        {
            it--;
        }
        ans[i] = it->first;
        mp[arr[i]]++;
    }
    return ans;
}

