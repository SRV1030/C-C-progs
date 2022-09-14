int tmr = 0;
void dfs(vector<vector<int>> &adj, vector<int> &vis, int i, vector<int> &ds, vector<int> &intm, vector<int> &otme, int dis)
{
    vis[i] = 1;
    intm[i] = tmr++;
    ds[i] = dis;
    for (auto a : adj[i])
    {
        if (vis[a] == 0)
        {
            dfs(adj, vis, a, ds, intm, otme, dis + 1);
        }
    }
    otme[i] = tmr++;
}
vector<int> solve(int N, int Q, vector<vector<int>> &Edge,
                  vector<vector<int>> &query)
{
    // code here
    vector<vector<int>> adj(N);
    vector<int> ds(N, 0), intm(N, 0), otme(N, 0);
    for (int i = 0; i < Edge.size(); i++)
    {
        adj[Edge[i][0]].push_back(Edge[i][1]);
        adj[Edge[i][1]].push_back(Edge[i][0]);
    }
    vector<int> vis(N, 0);
    dfs(adj, vis, 0, ds, intm, otme, 0);
    vector<pair<int, int>> vp;
    for (int i = 0; i < N; i++)
    {
        vp.push_back({intm[i], ds[i]});
    }
    sort(vp.begin(), vp.end());

    //   for(int i=1;i<N;i++)
    //   {
    //       cout<<vp[i].first<<" "<<vp[i].second<<"\n";
    //   }
    vector<int> lft(N, 0), rt(N + 1, 0), ser;
    lft[0] = vp[0].second;
    ser.push_back(vp[0].first);
    for (int i = 1; i < N; i++)
    {
        lft[i] = max(vp[i - 1].second, lft[i - 1]);
        ser.push_back(vp[i].first);
    }
    rt[N - 1] = vp[N - 1].second;
    rt[N] = 0;
    for (int i = N - 2; i >= 0; i--)
    {
        rt[i] = max(vp[i].second, rt[i + 1]);
    }
    vector<int> ans;
    for (int i = 0; i < Q; i++)
    {
        int a = query[i][0], b = query[i][1];
        int l = max(intm[a], intm[b]);
        int h = min(otme[a], otme[b]);
        int id1 = lower_bound(ser.begin(), ser.end(), l) - ser.begin();

        int id2 = upper_bound(ser.begin(), ser.end(), h) - ser.begin();
        ans.push_back(max(lft[id1], rt[id2]));
    }
    return ans;