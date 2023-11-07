#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int orangesRotting(vector<vector<int>> &grid);
int main()
{
    vector<vector<int>> v = {{0, 1, 2}, {1, 1, 1}, {1, 2, 0}};
    int result = orangesRotting(v);
    cout << result;

    system("pause");
    return 0;
}
int orangesRotting(vector<vector<int>> &grid)
{
    queue<pair<int, int>> rotten; // Luu dia chi cam thoi
    int m = grid.size();
    int n = grid[0].size();
    int freshCount = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1) // dem so cam tuoi
            {
                freshCount++;
            }
            else if (grid[i][j] == 2) // them so cam thoi vao hang doi
            {
                rotten.push({i, j});
            }
        }
    }

    int minutes = 0;
    vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Vector luu gia tri lien ke
  

    while (!rotten.empty() && freshCount > 0){
        int size = rotten.size();
        for(int i = 0; i < size; i++){
            int x = rotten.front().first;
            int y = rotten.front().second;
            rotten.pop();

            for(auto dir : direction){
                int newX = x + dir.first;
                int newY = y + dir.second;
                if(newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1){
                    grid[newX][newY] = 2;
                    freshCount--;
                    rotten.push({newX, newY});
                }
            }
           
        }
         minutes++;
    }

    return (freshCount == 0) ? minutes : -1;
}
