#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) 
{
    vector<int> score(3);   // 각 수포자가 얻은 점수
    vector<int> answer;
 
    // 수포자 2와 3의 규칙
    vector<int> person2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> person3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    for (int i = 0; i < answers.size(); i++)
    {
        // 수포자 1
        if (answers[i] == i % 5 + 1)
            ++score[0];

        // 수포자 2
        if (answers[i] == person2[i % person2.size()])
            ++score[1];

        // 수포자 3
        if (answers[i] == person3[i % person3.size()])
            ++score[2];
    }

    // 최대값 찾기
    auto maxIdx = max_element(score.begin(), score.end());

    // 최대값이 여러개일 경우를 가정하고 구현
    for (int i = 0; i < 3; i++)
    {
        if (*maxIdx == score[i])
            answer.push_back(i + 1);    // 수포자 인덱스는 1부터 시작
    }

    // 오름차순 정렬
    sort(answer.begin(), answer.end());

    return answer;
}