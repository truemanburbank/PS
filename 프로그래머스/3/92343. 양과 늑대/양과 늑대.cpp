#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>


using namespace std;

unordered_map<int, vector<int>> tree;
int ans;

// 최대한 많은 양을 찾는다.
// 방문했던 노드는 다시 방문할 수 있다!!
// 방문했던 노드의 자식들도 그냥 바로 방문할 수 있다.
// 방문 가능한 노드들을 모아서 넘겨준다. 
void dfs(vector<int>& info, set<int> visits, int node, int sheep, int wolf)
{
    sheep += (info[node] == 0 ? 1 : 0);
    wolf += (info[node] == 1 ? 1 : 0);

    if (sheep <= wolf)
        return;

    // 양 최대 마릿수 구하기
    ans = max(ans, sheep);

    visits.erase(node);
    for (int child : tree[node])
        visits.insert(child);

    for (int next : visits)
        dfs(info, visits, next, sheep, wolf);
}


// 0은 양, 1은 늑대를 의미합니다.
// 모든 경우의 수를 찾는다. DP (노드 최대 개수는 17으로 매우 작음.)
int solution(vector<int> info, vector<vector<int>> edges) 
{
    for (vector<int> edge : edges)
    {
        int parent = edge[0];
        int child = edge[1];

        tree[parent].push_back(child);
    }

    set<int> visits;
    for (int child : tree[0])
        visits.insert(child);
    dfs(info, visits, 0, 0, 0);

    return ans;
}