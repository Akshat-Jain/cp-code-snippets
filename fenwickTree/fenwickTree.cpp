/**** [ AkJn ] ****/
#include <bits/stdc++.h>
using namespace std;
 
#define fastIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define ld long double
#define ll long long
#define min3(a, b, c) min(a,min(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max3(a, b, c) max(a,max(b, c))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define yay(x) cout<<endl<<"yay"<<x<<endl;
// #define debug(a) do { std::cout << "Value of " << #a << " is: " << (a) << '\n'; } while(false);
// #define dbg(a) do { std::cout << "Value of " << #a << " is: " << (a) << '\n'; } while(false);
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dbgendl(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cout<<endl;}
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

/* CHECK THESE POINTS BEFORE SUBMITTING
 * Read the question carefully.
 * Read the code once before final submission.
 * Check the extremities of the constraints.
 * Always check if Binary Search can be applied.
 * 0 is better than -1.
*/

const ll INF = 1e18L + 5;
const ll mod = 1e9+7;

ll int n;

ll sum(ll index, vector<ll> &tree){
    ll sum = 0;
    while(index>=1){
        sum += tree[index];
        index -= index&-index;
    }
    return sum;
}

ll sum(ll a, ll b,vector<ll> &tree){
    return sum(b,tree) - sum(a-1,tree);
}

void updateTree(vector<ll> &tree, ll index, ll newValue){
    while(index<=n){
        tree[index] += newValue;
        index += index&-index;
    }
}

void constructFenwickTree(vector<ll> v, vector<ll> &tree){
    for (ll int i = 1; i <= n; ++i)
    {
        updateTree(tree,i,v[i]);
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
 
    /* 
     * THINK MATHEMATICALLY. IT IS NOT AS TOUGH AS IT SEEMS.
    */
 
    fastIO
    cin>>n;
    std::vector<ll> v(n+1), tree(n+1,0);
    for (ll int i = 1; i <= n; ++i)
    {
        cin>>v[i];
    }

    constructFenwickTree(v,tree);

    for (ll int i = 1; i <= n; ++i)
    {
        cout << tree[i] << " ";
    }
    cout << endl;

    cout << sum(1,1,tree) << endl;
    cout << sum(1,2,tree) << endl;
    cout << sum(1,3,tree) << endl;
    cout << sum(1,4,tree) << endl;
    cout << sum(1,5,tree) << endl;
    cout << sum(1,6,tree) << endl;
    cout << sum(1,7,tree) << endl;
    cout << sum(1,8,tree) << endl;

   return 0;
}
 
// DFS for trees
// Time Complexity = O(n)
// ll dfs(ll int v,ll int p)
// {
//     for(ll int i=0;i<g[v].size();i++)
//     {
//         if(g[v][i]!=p)
//         {
//             dfs(g[v][i],v);
//         }
//     }
//     return 1;
// }


// ll int binsearch(ll int l, ll int r){
//     while(l<r){
//         ll int mid = l+(r-l)/2;
//         if(check(mid)){
//             r = mid;
//         }
//         else{
//             l = mid + 1;
//         }
//     }
//     return r;
// }
 
// int find_set(int a){
//     if(a==parent[a]){
//         return a;
//     }
//     return parent[a] = find_set(parent[a]);
// }
 
// void union_sets(int a, int b){
//     a = find_set(a);
//     b = find_set(b);
//     if(a!=b){
//         parent[b] = a;
//         size[a] += size[b];
//     }
// }
 
// bool isPrime(ll int n) 
// {
//     if (n <= 1) return false; 
//     if (n <= 3) return true; 
 
//     if (n%2 == 0 || n%3 == 0) return false; 
  
//     for (ll int i=5; i*i<=n; i=i+6) 
//         if (n%i == 0 || n%(i+2) == 0) 
//            return false;
 
//     return true; 
// }
 
// ll int gcd(ll int a, ll int b)  
// {
//     if (a==0 || b==0){
//         return 0;
//     }
//     if(a==b){
//         return a;
//     }
//     if(a>b){
//         return gcd(a-b, b);
//     }
//     return gcd(a, b-a);
// }