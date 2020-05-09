// 1. Normal dfs

vector<vector<ll> > g; // graph represented as an adjacency list
ll n; // number of vertices

vector<bool> visited;

void dfs(ll v) {
    visited[v] = true;
    for (ll u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
}


// 2. Diameter of tree using dfs

vector<ll> g[200];
ll node, diameter;

void dfs(ll u, ll par, ll dist){
    if(dist >= diameter){
        diameter = dist;
        node = u;
    }
    for(auto v: g[u]){
        if(v!=par){
            dfs(v,u,dist+1);
        }
    }
}

// inside main:
dfs(u,-1,0);
dfs(node,-1,0);
ll dist=diameter;

// Explanation:
// We choose an arbitrary node (u) and find the farthest node from (u), let it be (node).
// Then we do another traversal to find the farthest node from (node) , let it be (v).
// Then diameter is the distance between (node) and (v).

// Proof: http://courses.csail.mit.edu/6.046/fall01/handouts/ps9sol.pdf
// Question: https://codeforces.com/contest/14/problem/D