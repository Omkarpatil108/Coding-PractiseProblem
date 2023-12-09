//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int smithNum(int n) {
        if( n == 2) return 0;
        int ans =0;
        int s = n;
        int sum = 0;
        while(s!=0){
            sum += s%10;
            s= s/10;
        }
        vector<int> vec;
        int p = n;
        for(int i =2 ; i<n; i++){
            int temp = 0;
            
            if(isprime(i)){
                while(p > 1 && p%i == 0){
                temp++;
                p /= i;
            }
            int sd =i;
            
            int c = 0; 
            while(sd != 0){
                c += sd%10;
                sd /= 10;
            }
            ans += temp *c;
            }
        }
        if(ans == sum)return 1;
        return 0;
    }bool isprime(int n){
        if(n==2)return 1;
        for(int i =3; i< sqrt(n)+1; i++){
            if(n%i == 0)return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends