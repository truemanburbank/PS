#include <vector>
#include <queue>
using namespace std;

// 그냥 bfs 문제
// n과 m은 다르다. (행, 열 헷갈리지 않게 주의)
int solution(vector<vector<int>> maps)
{
    const int ROW = maps.size();  // 행 (세로)
    const int COL = maps[0].size();

    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };

    vector<vector<int>> visited(ROW, vector<int>(COL, -1));
    queue<pair<int, int>> q;

    q.push({ 0, 0 });
    visited[0][0] = 1;

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (r == ROW - 1 && c == COL - 1)
            return visited[r][c];

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (nr < 0 || nc < 0 || nr >= ROW || nc >= COL) continue;
            if (maps[nr][nc] == 0 || visited[nr][nc] != -1) continue;

            q.push({ nr, nc });
            visited[nr][nc] = visited[r][c] + 1;
        }
    }

    return -1;
}