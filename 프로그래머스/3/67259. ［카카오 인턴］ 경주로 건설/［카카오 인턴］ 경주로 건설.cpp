#include <string>
#include <vector>
#include <queue>
using namespace std;

// 직선 100
// 코너 500
// bfs로 하면 되지 않을까
// 정사각형

// 상하좌우
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int ans = 987654321;

struct State
{
    int x, y, dir, cost;
    bool operator>(const State& a) const
    {
        return cost > a.cost;
    }
};

int solution(vector<vector<int>> board) 
{
    int max = board.size();
    vector<vector<vector<int>>> cost(max, vector<vector<int>>(max, vector<int>(4, 987654321)));
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({ 0, 0, -1, 0 });

    for (int d = 0; d < 4; d++)
        cost[0][0][d] = 0;

    while (!pq.empty())
    {
        State cur = pq.top();
        pq.pop();

        if (cur.x == max - 1 && cur.y == max - 1)
            return cur.cost;

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= max || ny >= max) continue;
            if (board[nx][ny] == 1) continue;

            int newCost = cur.cost + 100;
            if (cur.dir != -1 && cur.dir != i) newCost += 500;

            if (cost[nx][ny][i] > newCost)
            {
                cost[nx][ny][i] = newCost;
                pq.push({ nx, ny, i, newCost });
            }
        }
    }

    return 0;
}