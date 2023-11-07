#include <bits/stdc++.h>
using namespace std;

// 12 11

int n;
int m = n - 1;
vector<int> adj[1001]; // luu danh sach ke
bool visited[1001];    // Danh dau mang da duoc tham

void enterFloor(int n, int k, int m)
{
    for (int i = 1; i <= n - k; i++)
    {
        adj[i].push_back(i + k);
    }
    for (int i = m + 1; i <= n; i++)
    {
        adj[i].push_back(i - m);
    }
    memset(visited, false, sizeof(visited));
}

void BFS(int s, int f)
{
    // Buoc khoi tao
    queue<int> vertexes;
    vertexes.push(s);  // push dinh
    visited[s] = true; // danh dau dinh da duoc tham

    // Buoc lap
    while (!vertexes.empty())
    {
        int v = vertexes.front(); // lay dinh dinh dau hang doi
        vertexes.pop();           // xoa no di
        cout << v << " ";
        if (v == f)
        {
            return;
        }
        else
        {
            for (auto x : adj[v])
            {
                if (!visited[x])
                {
                    vertexes.push(x);
                    visited[x] = true;
                }
            }
        }
    }
}

int main()
{
    // So tang, tang len, tang xuong, xuat phat, dich den
    int n, k, m, s, f;

    cin >> n;
    cin >> m >> k;
    cin >> s >> f;
    enterFloor(n, m, k);
    BFS(s, f);

    system("pause");
    return 0;
}
