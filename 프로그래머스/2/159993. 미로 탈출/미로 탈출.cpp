#include <string>
#include <vector>
#include <queue>
using namespace std;

// 따라서, 출발 지점에서 먼저 레버가 있는 칸으로 이동하여 레버를 당긴 후 미로를 빠져나가는 문이 있는 칸으로 이동하면 됩니다. 
// 미로를 탈출하는데 필요한 최소 시간을 return 하는 solution 함수를 완성해주세요. 만약, 탈출할 수 없다면 -1을 return 해주세요.

// 레버와 출구는 한 개씩만 존재
// 가장 빨리 레버로 가서, visited 초기화 한 후  바로 출구로

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int bfs(const vector<string>& maps, pair<int, int> start, char target)
{
    const int max_x = maps[0].size();
    const int max_y = maps.size();

    vector<vector<int>> visited(max_y, vector<int>(max_x, -1));

    // 시작 시간 설정
    visited[start.first][start.second]++;

    queue<pair<int, int>> q;
    q.push(start);

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (maps[x][y] == target)
            return visited[x][y];

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= max_y || ny >= max_x) continue;
            if (maps[nx][ny] == 'X' || visited[nx][ny] != -1) continue;

            visited[nx][ny] = visited[x][y] + 1;
            q.push({ nx, ny });
        }
    }

    return -1;
}

int solution(vector<string> maps) 
{
    bool isLeverOpen = false;
    pair<int, int> start;
    pair<int, int> lever;

    // 시작점 찾기
    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[0].size(); j++)
        {
            if (maps[i][j] == 'S')
            {
                start = { i, j };
            }
            else if (maps[i][j] == 'L')
            {
                lever = { i, j };
            }
        }
    }

    int leverTime = bfs(maps, start, 'L');
    if (leverTime == -1) return -1;

    int exitTime = bfs(maps, lever, 'E');
    if (exitTime == -1) return -1;

    return leverTime + exitTime;
}