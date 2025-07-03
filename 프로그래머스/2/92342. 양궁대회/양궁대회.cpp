#include <string>
#include <vector>

using namespace std;

// 어피치가 쏜 화살보다 적게 쏘는 건 무의미하다. 무조건 + 1만큼 더 쏴야 함.
// 따라서 k 점 과녁에 화살을 쏠 것인지 말 것인지 결정만 하면 된다.

vector<int> answer;
vector<int> rion(11, 0);
int maxScoreDiff = -1;

// 어피치 - 라이언
// 0보다 커야 라이언이 이긴것.
int GetScoreDiff(const vector<int>& apeach)
{
    int rionScore = 0;
    int apeachScore = 0;

    for (int i = 0; i < apeach.size(); i++)
    {
        if (apeach[i] == 0 && rion[i] == 0)
            continue;

        if (apeach[i] >= rion[i])
            apeachScore += 10 - i;
        else
            rionScore += 10 - i;
    }

    return rionScore - apeachScore;
}

// 화살을 k 점수 과녁에 쏘는가/안 쏘는가 선택의 조합들.
void Solve(int remainingArrow, int k, const vector<int>& apeach)
{
    // 화살 다 썼거나 0점 과녁까지 다 순회한 경우 
    if (remainingArrow <= 0 || k < 0)
    {
        // 화살이 남아 있으면 0점에 다 쏜다.
        rion[10] = remainingArrow;
        int scoreDiff = GetScoreDiff(apeach);
        if (scoreDiff > 0 && maxScoreDiff < scoreDiff)
        {
            maxScoreDiff = scoreDiff;
            answer = rion;
        }
        rion[10] = 0; // 복구
        return;
    }

    // 화살을 쏠 수 있는 경우 (어피치보다 확정적으로 많이 쏠 수 있을 때)
    if (remainingArrow > apeach[k])
    {
        rion[k] = apeach[k] + 1;
        Solve(remainingArrow - rion[k], k - 1, apeach);
        rion[k] = 0; // 복구
    }

    // 화살을 안 쏘는 선택
    Solve(remainingArrow, k - 1, apeach);
}

vector<int> solution(int n, vector<int> info) 
{
    // 10점 구역부터 쏘기
    Solve(n, 10, info);

    // 라이언이 어피치를 한 번도 못 이겼을 때
    // answer는 비어있다.
    if (maxScoreDiff == -1)
        answer.push_back(-1);

    return answer;
}