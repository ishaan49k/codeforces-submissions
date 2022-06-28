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
#define take_array_input(n) int n;cin>>n;vector<int> arr(n);for(int i=0; i<n; i++){cin >> arr[i];}

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






void solve() {


	int n;
	cin >> n;
 
	map<pair<int, int>, int> edges;
	vector<int> degree(n+1);
    vector<vector<int>> adjList(n+1);
	for(int i=0; i<n-1; i++){
		int a, b;
		cin >> a >> b;
 
		pair<int, int> e = {a , b};
		edges[e] = i;
		swap(e.first , e.second);
		edges[e] = i;
 
		degree[a]++;
		degree[b]++;
 
		adjList[a].push_back(b);
		adjList[b].push_back(a);

	}
 

    int start = -1;
	for(int i=1 ; i<=n ; i++){
		if(degree[i]==1 start==-1){
			start = i;
		}
        else if(degree[i] > 2){
			cout << -1 << endl;
			return;
        }

    }
 
	int w = 2;
 
	queue<int> queue;
	vector<int> vis(n+1);
	vis[start] = 1;
	queue.push(start);
	vector<int> ans(n-1);
	while(!queue.empty()){
		int curr = queue.front();
		queue.pop();
		for(auto x: adjList[curr]){
			if(!vis[x]){
				vis[x] = 1;
				queue.push(x);
 
				pair<int, int> e = {curr, x};
				int idx = edges[e];
				ans[idx] = w;
 
				if(w == 2){
					w = 5;
                }
				else{
					w = 2;
                }

			}

		}

	}
 
	for(auto wt: ans){
		cout << wt <<  " ";
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



