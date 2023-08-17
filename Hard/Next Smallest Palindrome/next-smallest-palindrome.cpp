//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> generateNextPalindrome(int num[], int n) {
	    // code here
	     vector<int> v(num, num+n);
        int left = n/2, right = n/2;
        
        if((n&1) == 0)
            left--;
	    
	    while(left>=0)
	    {
	        if(v[right]>v[left])
	            break;
	        if(v[left]>v[right])  
	        {
	            while(left>=0) 
	            {
	                v[right] = v[left];
	                left--;
	                right++;
	            }
	            return v;
	        }
	        left--;
	        right++;
	    }
	    
	    left = n/2;
	    right = n/2;
	    if((n&1) == 0)
	        left--;
	   
	    while(left>=0)
	    {
	        if(num[left]!=9)
	        {
	           
	            if(num[right] >= num[left])
	                num[left]++;
	            
	            while(left>=0) 
	            {
	                num[right] = num[left];
	                left--;
	                right++;
	            }
	            for(int i=0; i<n; i++)
	                v[i] = num[i];
	            return v;
	        }
             	        
	        else 
	        {
	            num[left] = 0;
	            num[right] = 0;
	            left--;
	            right++;
	        }
	    }
	    
	    vector<int> answer(n+1,0);
	    answer[0] = 1;
	    answer[n] = 1;
	    return answer;
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends