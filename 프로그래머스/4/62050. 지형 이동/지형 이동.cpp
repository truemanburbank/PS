#include <string>
#include <vector>
#include <queue>
using namespace std;

// 현재 위치에서 상,하,좌,우 비용을 비교하여 비용이 적게 드는 곳으로 방문한다.
// 우선순위 큐 + bfs

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
bool visited[301][301];

struct Pos
{
    int r;
    int c;
    int heightDiff;

    // 사다리 비용이 낮은 Pos 순대로 정렬 (우선 순위 큐 정렬 기준)
    bool operator<(const Pos& p) const { return heightDiff > p.heightDiff; }
};

int solution(vector<vector<int>> land, int height)
{
    int answer = 0;
    int N = land.size();
    priority_queue<Pos> pq;
    pq.push({ 0, 0, 0 });

    while (!pq.empty())
    {
        Pos current = pq.top();
        // 현재 가능한 최소 비용 경로를 우선으로 뽑음
        pq.pop();

        if (visited[current.r][current.c]) continue;

        // land[current.r][current.c]로 가는 최소 비용을 꺼낸 후 확정적으로 방문 처리.  
        visited[current.r][current.c] = true;

        answer += current.heightDiff;

        for (int i = 0; i < 4; i++)
        {
            int nr = current.r + dy[i];
            int nc = current.c + dx[i];

            if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;

            int diff = abs(land[current.r][current.c] - land[nr][nc]);
            if (diff <= height)
                pq.push({ nr, nc, 0 });
            else
                pq.push({ nr, nc, diff });
        }
    }

    return answer;
}
