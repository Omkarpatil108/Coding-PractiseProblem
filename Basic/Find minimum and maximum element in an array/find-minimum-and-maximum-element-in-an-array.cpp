//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n) ;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}
// } Driver Code Ends


pair<long long, long long> getMinMax(long long a[], int n) {
    
    int long long  mn=INT_MAX,mx=INT_MIN;
    pair<int,int> p;
    for(int i=0;i<n;i++){
        mn=min(mn,a[i]);
        mx=max(mx,a[i]);
    }
    p.first=mn;
    p.second=mx;
    return p;
}