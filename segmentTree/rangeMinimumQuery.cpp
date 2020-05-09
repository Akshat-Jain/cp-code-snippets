/**** [ AkJn ] ****/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define vi vector<ll>
#define vii vector <pair<ll,ll> >
#define pb push_back
#define mp make_pair
#define ld long double
#define ll long long
#define min3(a, b, c) min(a,min(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max3(a, b, c) max(a,max(b, c))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define yay(x) cout<<endl<<"yay"<<x<<endl;
#define yay1 cout<<"yay1"<<endl;
#define yay2 cout<<"yay2"<<endl;
#define yay3 cout<<"yay3"<<endl;
#define yay4 cout<<"yay4"<<endl;
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
const ll inf = 1e18L + 5;
const ll mod = 1e9+7;
 
/* 
 * THINK MATHEMATICALLY. IT IS NOT AS TOUGH AS IT SEEMS.
 * Check EDGE CASES!! Seriously, even in 2B, saving 8 points by being
 * 2 minutes faster will bite you in the ass if you don't make sure
 * it works on edge cases.
 * Pretests != Tests. READ THIS POINT AGAIN.
 * You do know how to use structs. God damn use them when required.
 * 0 is better than -1.
 * Keep adding to this list.
*/
 
std::vector<ll> tree,a;
 
ll n,q;
 
void build(ll node, ll start, ll end){
    if(start==end){
        tree[node] = a[start];
    }
    else{
        ll mid = (start+end)/2;
        build(2*node+1,start,mid);
        build(2*node+2,mid+1,end);
        tree[node] = min(tree[2*node+1],tree[2*node+2]);
    }
}
 
void update(ll node, ll start, ll end, ll idx, ll val){
    if(start==end){
        tree[node] = a[idx];
    }
    else{
        ll mid = (start+end)/2;
        if(idx<=mid){
            update(2*node+1,start,mid,idx,val);
        }
        else{
            update(2*node+2,mid+1,end,idx,val);
        }
        tree[node] = min(tree[2*node+1],tree[2*node+2]);
    }
}
 
ll query(ll node, ll start, ll end, ll l, ll r){
    if(start==l and end==r){
        return tree[node];
    }
    if(l>r){
        return 1e18;
    }
    ll mid = (start+end)/2;
    return min(query(2*node+1,start,mid,l,min(r,mid)), query(2*node+2,mid+1,end,max(l,mid+1),r));
}
 
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
 
    fastIO
    cin>>n>>q;
    tree.resize(4*n);
    a.resize(n);
    for (ll i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    build(0,0,n-1);
    for (ll i = 0; i < q; ++i)
    {
        char c;
        cin>>c;
        if(c=='q'){
            // In this query you need to print the minimum in the sub-array A[l,r].
            ll l,r;
            cin>>l>>r;
            l--;
            r--;
            ll ans = query(0,0,n-1,l,r);
            cout << ans << endl;
        }
        else{
            // In this query you need to update A[x]=y.
            ll x,y;
            cin>>x>>y;
            x--;
            a[x]=y;
            update(0,0,n-1,x,y);
        }
    }
    return 0;
}