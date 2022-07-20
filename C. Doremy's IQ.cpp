// RDQ
#include<bits/stdc++.h>
using namespace std;
//common file for PBDS
#include<ext/pb_ds/assoc_container.hpp>
//including tree_order_statistics_node_update
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define mii     map<int, int> 
#define pii     pair<int, int>
#define pdd     pair<double, double>
#define endl    "\n"
#define ll      long long
#define vi      vector<int>
#define vll     vector<ll>
#define vvi     vector<vi>
#define pll     pair<long long, long long>
#define vpll    vector <pair<long long,long long>>
#define mod1    1000000007
#define mod2    998244353
#define mp      make_pair
#define pb      push_back
#define ff      first
#define ss      second
#define PI      3.14159265358979323846
#define fore(i, l, r) for(int i=int(l); i<int(r); i++)
 
const int N = int(2e5) + 9;
 
// RTU FUNCTIONS HERE
// ---------------------------------------------------------------------------------------------------------
int gcd(int x, int y){
    if(!y) return x;
        return gcd(y, x % y);
}
 
// returns ceil(x/y)
ll cdiv(ll x, ll y){
    return x / y + (x%y>0);
}
 
 
bool isprime(int n){
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(int i = 5; i * i <= n; i += 6){
        if(n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
 
 
 
// ---------------------------------------------------------------------------------------------------------
 
void fast() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
 
 
 
bool isPalindrome(string S){
    for (int i = 0; i < S.length() / 2; i++) {
        if (S[i] != S[S.length() - i - 1]) {
            return false;
        }
    }
    return true;
}
 
 
 
 
 
/*
 
 
 
 
 
*/
 
 
 
 
 
 
 
 
 
void solve(){
 
    ll n, q;
    cin >> n >> q;
 
    vector<int> arr(n);
    vector<int> good;
    vector<int> bad;
 
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(arr[i] > q){
            bad.push_back(i);
        }
        else{
            good.push_back(i);
        }
    }
    ll lo = 0;
    ll hi = (int)bad.size()-1;
    int ans = n;
    while(lo <= hi){
        ll mid = lo + (hi-lo)/2;
        bool valid = true;
        ll curr_iq = q;
 
        for(ll i=bad[mid]; i<n; i++){
            if(curr_iq <= 0){
                valid = false;
                break;
            }
 
            if(arr[i] > curr_iq){
                curr_iq--;
            }
            
        }
 
        if(valid){
            ans = bad[mid];
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
 
    }
 
 
    // print answer
    for(ll i=0; i<ans; i++){
        if(arr[i] > q){
            cout << "0";
        }
        else{
            cout << "1";
        }
    }
 
    for(int i=ans; i<n; i++){
        cout << "1";
    }
 
    cout << endl;
 
    return;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
int main(){
 
    fast();
    int t;
    cin >> t;
 
    // precompute();
    while(t--){
        solve();
 
    }
    
    return 0;
 
}
 
 
