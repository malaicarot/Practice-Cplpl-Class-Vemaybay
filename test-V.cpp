#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int orangesRotting(vector<vector<int>> &grid);

int main()
{
    vector<vector<int>> test{{2,1,1},{0,1,1},{1,0,1}};
    int minutes = orangesRotting(test);
    cout << minutes;

    system("pause");
    return 0;
}

int orangesRotting(vector<vector<int>> &grid)
{
    int m = grid.size();          // so hang
    int n = grid[0].size();       // so cot
    int freshOranges = 0;          // so luong cam tuoi
    queue<pair<int, int>> rotten; // Hang doi luu toa do cam thoi

    for (int i = 0; i < m; i++) // Duyet tung hang
    {
        for (int j = 0; j < n; j++) // duyet tung cot
        {
            if (grid[i][j] == 1)
            {
                freshOranges++; // dem so cam tuoi
            }
            else if (grid[i][j] == 2)
            {
                rotten.push({i, j});
            }
        }
    }
    int minutes = 0; // so phut ma tat ca cam bi thoi
    vector<pair<int, int>> direction{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!rotten.empty() && freshOranges > 0)
    {
        int size = rotten.size(); // so luong cam thoi (toa do cam thoi)
        for (int i = 0; i < size; i++)
        {
            int x = rotten.front().first;  // lay toa do x cua cam thoi
            int y = rotten.front().second; // lay toa do y cua cam thoi
            rotten.pop();
            for (auto dir : direction)
            {
                int newX = x + dir.first;  // toa do x lien ke voi cam thoi
                int newY = y + dir.second; // toa do y lien ke voi cam thoi
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1)
                {
                    grid[newX][newY] = 2;
                    rotten.push({newX, newY});
                    freshOranges--;
                }
            }
        }
        minutes++;
    }
    return (freshOranges == 0) ? minutes : -1;
}