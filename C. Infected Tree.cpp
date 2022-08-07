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

Observations:
- To save max nodes, we always have to delete a vertex connected directly to the infected node.

- At each level, we have to perform an operation. We start oerforming operations from the top to bottom level to save max number of nodes.

- This is like knapsack problem.

- dp[i] stores max number of nodes we can save with ith node as infected root node.

- At every node i, we have 2 options: delete the left child(node1) or thr right child(node2).

- If we delete node1, then dp[i] = max(dp[i], no. of nodes in subtree of node1 + dp[node2])

- If we delete node2, then dp[i] = max(dp[i], no. of nodes in substree of node2 + dp[node1])




*/




// counts the number of nodes present in all the subtrees
void countSubtrees(ll v, ll par, vector<ll> &cnt, vector<vector<ll>> &graph){

    // the node itself
    cnt[v]++;

    // now go to its nbrs and find the number of nodes in the substrees of the neightbours and add their count in the count of current node.
    for(auto nbr: graph[v]){
        if(nbr != par){
            countSubtrees(nbr, v, cnt, graph);
            cnt[v] += cnt[nbr];
        }
    }

    return;

}






// this function will finc the 
void dfs(ll v, ll par, vector<ll> &dp, vector<ll> &cnt, vector<vector<ll>> &graph){


    // the node v has no children, then return
    if(graph[v].size() == 1){
        return;
    }

    // stores the children of the current node v
    vector<ll> child;

    // call dfs on all children this will fill dp[]
    for(auto nbr: graph[v]){
        if(nbr != par){
            child.pb(nbr);
            dfs(nbr, v, dp, cnt, graph);
        }
    }

    
    // if the node v has only 1 child, then we delete the child node
    if(graph[v].size() == 2){
        dp[v] = cnt[child[0]] - 1;
        return;
    }

    // node v has 2 children
    ll node1 = child[0];
    ll node2 = child[1];

    dp[v] = max(dp[node2]+cnt[node1]-1, dp[node1]+cnt[node2]-1);

    return;

}












void solve(){

    ll n;
    cin >> n;

    vector<vector<ll>> graph(n+1);   // adjacency list
    
    // dp[i] stores max nodes we can save with ith node has infected root node
    vector<ll> dp(n+1, 0);

    // cnt[i] stores no. of nodes in subtree of i including ith node
    vector<ll> cnt(n+1, 0);

    for(int i=1; i<=n-1; i++){
        ll u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    graph[1].pb(0);

    countSubtrees(1, 0, cnt, graph);

    dfs(1, 0, dp, cnt, graph);
    cout << dp[1] << endl;
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



