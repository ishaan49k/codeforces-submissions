// tud - graph

#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
#define mii     map<int, int> 
#define pii     pair<int, int>
#define pdd     pair<double, double>
#define endl    "\n"
#define ll      long long
#define ld      long double
#define vi      vector<int>
#define vll     vector<ll>
#define vvi     vector<vi>
#define pll     pair<long long, long long>
#define vpll    vector<pair<long long,long long>>
#define mod1    1000000007
#define mod2    998244353
#define mp      make_pair
#define pb      push_back
#define ff      first
#define ss      second
#define PI      3.14159265358979323846
#define fore(i, l, r) for(int i=int(l); i<int(r); i++)
#define all(x) x.begin(), x.end()

#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
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





int X = 1e6 + 10;





 
 
 
 
 
 
/*



 
*/
 
 





ll find(ll v, vector<ll> &par){
    if(par[v] == -1){
        par[v] = v;
    }

    if(par[v] == v){
        return v;
    }

    par[v] = find(par[v], par);
    return par[v];

}



 

 
 

 
void solve(){
    
    ll n, m;
    cin >> n >> m;

    vector<ll> par(100000, -1);

    ll ans = 0;
    for(ll i=0; i<m; i++){
        ll r, c;
        cin >> r >> c;
        if(r == c){
            continue;
        }
        ll par1 = find(r, par);
        ll par2 = find(c, par);

        if(par1 == par2){
            ans++;
        }
        else{
            par[r] = c;
        }
        ans++;

    }

    cout << ans << endl;
    return;
 
}
    
 
 
 
 
 
 
 
 
 
 
 
 
int main(){
 
    fast();
    int t = 1;
    cin >> t;
 
    // precompute();
    while(t--){
        solve();
 
    }
    
    return 0;
 
}
 
 






// --------------------------x-------------------------x--------------------

// another method without using DSU

#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
#define mii     map<int, int> 
#define pii     pair<int, int>
#define pdd     pair<double, double>
#define endl    "\n"
#define ll      long long
#define ld      long double
#define vi      vector<int>
#define vll     vector<ll>
#define vvi     vector<vi>
#define pll     pair<long long, long long>
#define vpll    vector<pair<long long,long long>>
#define mod1    1000000007
#define mod2    998244353
#define mp      make_pair
#define pb      push_back
#define ff      first
#define ss      second
#define PI      3.14159265358979323846
#define fore(i, l, r) for(int i=int(l); i<int(r); i++)
#define all(x) x.begin(), x.end()

#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
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





int X = 1e6 + 10;





 
 
 
 
 
 
/*



 
*/
 
 





bool count(vector<vector<ll>> &adj, ll v, vector<bool> &vec1, vector<bool> &vec2){
    vec1[v] = true;
    vec2[v] = true;
    for(int nbr: adj[v]){
        if(vec2[nbr] == true){
            return true;
        }
        else if(vec1[nbr] == false){
            bool recAns = count(adj, nbr, vec1, vec2);
            if(recAns == true){
                return true;
            }

        }
    }
    vec2[v] = false;
    return false;
}



 

 
 

 
void solve(){
    
    ll n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> rook(m);
    for(ll i=0; i<m; i++){
        cin >> rook[i].ff >> rook[i].ss;
    }

    vector<vector<ll>> adj(n+1);
    ll ans = 0;
    for(ll i=0; i<m; i++){
        if(rook[i].ff != rook[i].ss){
            adj[rook[i].ff].pb(rook[i].ss);
            ans++;
        }
    }
    vector<bool> vec1(n+1, false);
    vector<bool> vec2(n+1, false);

    for(ll i=1; i<=n; i++){
        if(vec1[i] == false){
            if(count(adj, i, vec1, vec2)){
                ans++;
            }
        }
    }

    cout << ans << endl;
    return;
 
}
    
 
 
 
 
 
 
 
 
 
 
 
 
int main(){
 
    fast();
    int t = 1;
    cin >> t;
 
    // precompute();
    while(t--){
        solve();
 
    }
    
    return 0;
 
}
 
 
