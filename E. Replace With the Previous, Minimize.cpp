#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
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











void solve(){
int n, k;cin >> n >> k;
string s;cin >> s;
int mx = 0;
char ch1 = 'a';
char ch2 = 'a';
for(int i=0; i<n; i++){
if(mx >= s[i]-'a'){
s[i] = 'a';
}
else if(k > 0){
int df = (s[i]-'a') - mx;
if(k >= df){
mx = s[i]-'a';
k -= df;
s[i] = 'a';
}
else{
ch1 = s[i] - k;
ch2 = s[i];
s[i] -= k;
k = 0;
}
}
}
for(int i=0; i<n; i++){
if(s[i]>=ch1 && s[i]<=ch2){
s[i] = ch1;
}
}
cout << s << endl;
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



