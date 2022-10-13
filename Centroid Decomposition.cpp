set<int> adj[LIM];
int sz[LIM];

int dfsForSize(int u, int p)
{
    sz[u] = 1;

    for (int x : adj[u])
    {
        if (x != p)
            sz[u] += dfsForSize(x, u);
    }

    return sz[u];
}

int findCentroid(int u, int p, int n)
{
    for (int x : adj[u])
    {
        if (x != p)
        {
            if (sz[x] > n / 2)
                return findCentroid(x, u, n);
        }
    }

    return u;
}

void centroidDecomposition(int u, int p = -1)
{
    int n = dfsForSize(u, p);
    int centroid = findCentroid(u, p, n);

    vector<int> v;

    for (int x : adj[centroid])
        v.pb(x);

    for (int x : v)
    {
        adj[x].erase(centroid);
        adj[centroid].erase(x);

        centroidDecomposition(x, centroid);
    }
}
