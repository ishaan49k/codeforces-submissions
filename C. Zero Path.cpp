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
#define all(x)  x.begin(),x.end()


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
 
void fast(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 



bool isPalindrome(string S){
    for (int i = 0; i < S.length() / 2; i++){
        if (S[i] != S[S.length() - i - 1]){
            return false;
        }
    }
    return true;
}





int X = 1e6 + 10;






/*



*/
















void solve(){

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> grid(n, vector<ll>(m, 0));
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }
    if((n+m-1)&1){
        cout << "NO" << endl;
        return;
    }
    vector<vector<ll>> minv(n, vector<ll>(m, INT_MAX));
    vector<vector<ll>> maxv(n, vector<ll>(m, INT_MIN));

    minv[0][0] = grid[0][0];
    maxv[0][0] = grid[0][0];
    for(int i=1; i<n; i++){
        minv[i][0] = minv[i-1][0] + grid[i][0];
        maxv[i][0] = maxv[i-1][0] + grid[i][0];
    }
    for(int i=1; i<m; i++){
        minv[0][i] = minv[0][i-1] + grid[0][i];
        maxv[0][i] = maxv[0][i-1] + grid[0][i];
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            minv[i][j] = min(minv[i-1][j], minv[i][j-1]) + grid[i][j];
            maxv[i][j] = max(maxv[i-1][j], maxv[i][j-1]) + grid[i][j];
        }
    }


    if(minv[n-1][m-1]<=0 && maxv[n-1][m-1]>=0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

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



