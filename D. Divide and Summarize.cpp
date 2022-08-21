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

If all the elements of the array are same, then no point in doing operatin cuz we get the same array.

To check if a given sum can be made, we can precompute all the possible sums and store them somewhere.

The cut operation dosent depend on the order of the array. hence we can sort the array. Now build a tree of transitions from the initial array to its
possible states.



*/




// fill the set with the sum of array from index l to r
void fill_sums(vector<ll> &a, set<ll> &sums, int l, int r){

    if(l > r){
        return;
    }

    ll sum = 0;
    for(int i=l; i<=r; i++){
        sum += a[i];
    }

    sums.insert(sum);

    // now call recursion on the left and right array
    // we should not call recursion if all the elements in the array are the same
    ll mxele = a[r];
    ll mnele = a[l];
    if(mxele == mnele){
        return;
    }

    // else we can split the array into left and right halves.

    // all elements less than equle to mid go in the left array and the elements more than mid go on the right half
    ll mid = a[l] + (a[r] - a[l])/2; 

    // find the index of first element which is more than mid
    int ub = -1;
    for(int i=l; i<=r; i++){
        if(a[i] > mid){
            ub = i;
            break;
        }
    }

    fill_sums(a, sums, l, ub-1);
    fill_sums(a, sums, ub, r);

    return;
}









void solve(){

    int n, q;
    cin >> n >> q;

    vector<ll> a(n);
    for(auto &x: a){
        cin >> x;
    }

    sort(a.begin(), a.end());

    // use a set to store all the possible sums
    set<ll> sums;
    fill_sums(a, sums, 0, n-1);   // recursive function that goes and fills sums with all the sums that can be made

    while(q--){
        ll s;
        cin >> s;

        if(sums.count(s)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

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



