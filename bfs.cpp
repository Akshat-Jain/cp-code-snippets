vector<vector<ll> > g;  // adjacency list representation
ll n; // number of nodes
ll s; // source vertex

queue<ll> q;
vector<bool> used(n);
vector<ll> d(n), p(n);

q.push(s);
used[s] = true;
p[s] = -1;
while (!q.empty()) {
    ll v = q.front();
    q.pop();
    for (ll u : adj[v]) {
        if (!used[u]) {
            used[u] = true;
            q.push(u);
            d[u] = d[v] + 1;
            p[u] = v;
        }
    }
}