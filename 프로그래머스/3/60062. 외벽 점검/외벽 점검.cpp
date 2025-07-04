#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 친구의 방향은 상관이 없다. 시계방향에서 탐색하든, 반시계방향에서 탐색하든.. 아무튼 커버만 하면 된다.
// 예시에서도 확인 가능한데, 예 2에서 9~4 탐색하거나 4~9 탐색하거나 상관이 없다는거다.
// 따라서 친구를 배치할 순서를 정해준다.
// + 취약점 시작 순서를 돌아가면서 친구 배치 순열을 차례대로 배치해준다.
// 원형으로 주어지므로 인덱스를 편하게 접근하려면... 24시간 시계와 비슷하게 구현한다.

int solution(int n, vector<int> weak, vector<int> dist) 
{
    // 원형 리스트를 선형 리스트처럼 변형
    // 모든 원소에 n을 더한 것을 뒤에 추가.
    int originalWeakCount = weak.size();
    for (int i = 0; i < originalWeakCount; i++)
    {
        weak.push_back(weak[i] + n);
    }

    // 최소값을 구하는 것이기 때문에 친구수 + 1로 초기화
    int answer = dist.size() + 1;

    // dist는 정렬되어 있단 가정이 없으므로 정렬 
    sort(dist.begin(), dist.end());

    // 취약점 시작지점을 돌아가며 경우의 수 확인해 봄
    for (int start = 0; start < originalWeakCount; ++start)
    {
        // next_permutation로 친구의 순열을 구함
        do
        {
            // 친구 카운트
            int friendCount = 1;
            // 첫 친구가 커버 가능한 영역 (마지막 위치를 반환)
            int coverage = weak[start] + dist[friendCount - 1];

            // 시작점부터 친구 배치 시작
            // start + originalWeakCount는 한 바퀴 영역
            for (int index = start; index < start + originalWeakCount; ++index)
            {
                // 커버 못한 경우
                if (weak[index] > coverage)
                {
                    ++friendCount; // 친구 추가

                    // 친구를 다 쓴 경우
                    if (friendCount > dist.size())
                        break;

                    coverage = weak[index] + dist[friendCount - 1];
                }
            }
            answer = min(answer, friendCount);

        } while (next_permutation(dist.begin(), dist.end()));
    }
    return answer > dist.size() ? -1 : answer;
}