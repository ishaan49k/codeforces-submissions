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

n friends.

atleast 2 friends go to the restraunt each day.
for each grp, we need total budget >= amount to be spent by the grp.

To find the max number of grps that can be formed.

Sol:
To maximise the total number of days, we need to from pairs. It is the number of grps that matters and not the number of people in each grp.
Hence adding a 3rd person to the grp wont improve the answer in any way.

Let's solve the problem using two pointers: for the richest friend, find the first friend from the end such that the sum of their values budget 
exceeds the sum of their values spend. Then repeat this for all subsequent friends until the pointers meet.

If no pair could be formed, answer is -1.

Otherwise, print the number of pairs formed.


*/









 

 
void solve(){

    ll n;
    cin >> n;

    vector<ll> spend(n);
    vector<ll> budget(n);

    for(ll i=0; i<n; i++){
        cin >> spend[i];
    }


    for(ll i=0; i<n; i++){
        cin >> budget[i];
    }

    // diff[i] tells the amount of excess(+ive) or deficient(-ive) money a person has
    vector<ll> diff(n);
    for(int i=0; i<n; i++){
        diff[i] = budget[i] - spend[i];
    }

    sort(diff.begin(), diff.end());

    int i = 0;
    int j = n-1;
    int cnt = 0;

    while(i < j){
        int sum = diff[i] + diff[j];

        if(sum >= 0){
            // form a grp of the ith and jth person
            cnt++;
            i++;
            j--;
        }
        else{
            // jth person is not letting us form a grp with ith person due to its low value. hence skip jth person. ie dont include him in any grp
            i++;
        }
    }

    cout << cnt << endl;
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





