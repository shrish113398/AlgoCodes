#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

vector<vector<int>> g;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
// bool isbip(int n)
// {
//     vector<int> color;
//     color.assign(n, -1);
//     queue<pair<int, int>> q;

//     for (int i = 0; i < n; i++)
//     {
//         if (color[i] == -1)
//         {
//             q.push({i, color[i]});
//             color[i] = 0;
//             while (!q.empty())
//             {
//                 pair<int, int> cur = q.front();
//                 q.pop();
//                 int c = cur.first;
//                 int d = cur.second;
//                 for (int j : g[c])
//                 {

//                     // if already coloured with parent vertex color
//                     // then bipartite graph is not possible
//                     if (color[j] == c)
//                         return 0;

//                     // if uncoloured
//                     if (color[j] == -1)
//                     {
//                         // colouring with opposite color to that of parent
//                         color[j] = (c) ? 0 : 1;
//                         q.push({j, color[j]});
//                     }
//                 }
//             }
//         }
//     }
//     return 1;
// }

bool isBipartite(int V)
{
    // vector to store colour of vertex
    // assigning all to -1 i.e. uncoloured
    // colours are either 0 or 1
      // for understanding take 0 as red and 1 as blue
    vector<int> col(V, -1);
 
    // queue for BFS storing {vertex , colour}
    queue<pair<int, int> > q;
   
      //loop incase graph is not connected
    for (int i = 0; i < V; i++) {
       
      //if not coloured
        if (col[i] == -1) {
           
          //colouring with 0 i.e. red
            q.push({ i, 0 });
            col[i] = 0;
           
            while (!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();
               
                  //current vertex
                int v = p.first;
                  //colour of current vertex
                int c = p.second;
                 
                  //traversing vertexes connected to current vertex
                for (int j : g[v]) {
                   
                      //if already coloured with parent vertex color
                      //then bipartite graph is not possible
                    if (col[j] == c)
                        return 0;
                   
                      //if uncoloured
                    if (col[j] == -1) {
                      //colouring with opposite color to that of parent
                        col[j] = (c) ? 0 : 1;
                        q.push({ j, col[j] });
                    }
                }
            }
        }
    }
    //if all vertexes are coloured such that
      //no two connected vertex have same colours
    return 1;
}
 
void solve()
{
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    if (isBipartite(n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
int main()
{
    IOS int t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
} 