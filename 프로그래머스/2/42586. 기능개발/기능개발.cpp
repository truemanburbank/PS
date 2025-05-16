#include <string>
#include <cmath>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> timeLeft;

    for (int i = 0; i < progresses.size(); i++)
    {
        // 각 작업이 완성될 때까지 걸리는 시간 구함
        int time = ceil((100.0 - progresses[i]) / speeds[i]);
        timeLeft.push_back(time);
    }

    int priorWork = timeLeft[0];
    int ret = 1;

    // 선행 작업 완료 시간보다 짧은 완료 시간이 있다면 ret 증가
    for (int i = 1; i < timeLeft.size(); i++)
    {
        if (priorWork >= timeLeft[i])
        {
            ret++;
        }
        else
        {
            answer.push_back(ret);
            priorWork = timeLeft[i];
            ret = 1;
        }
    }

    // 마지막으로 카운트된 작업 합함
    // 왜냐하면 위 for문에서 'else'에서만 answer에 push하고 있으므로 
    // 마지막 원소 순회가 if (priorWork >= left[i])로 들어갔다면 answer에 값을 추가하지 않기 때문
    answer.push_back(ret);

    return answer;
}