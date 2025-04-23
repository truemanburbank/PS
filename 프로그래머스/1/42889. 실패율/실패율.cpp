#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) 
{
    vector<int> fail(N + 1, 0); // 각 스테이지 도전 실패자 수
    vector<pair<int, double>> failureRate; // 실패율(스테이지 번호, 실패율)
    
    // 각 스테이지 인덱스에 해당하는 실패자 수 계산
    for(int stage : stages)
    {
        // 원소값 N+1은 모든 스테이지를 클리어한 유저이므로
        // 실패자 수에 포함시킬 필요 없다. 
        if(stage <= N)
            fail[stage]++;
    }
    
    // 전체 플레이어 인원
    int total = stages.size();
    
    // 1번 스테이지부터 실패율 계산
    for(int i = 1; i <= N; i++)
    {
        // 남은 인원이 0이면 스테이지에 도달한 유저가 없다.
        if(total == 0)
        {
            failureRate.push_back({i, 0});
        }
        else
        {
            // 실패율 계산
            // 실패한 유저 수 / 남은 인원
            double rate = (double)fail[i] / total;
            failureRate.push_back({i, rate});
            
            // 스테이지의 실패율을 구한 후
            // 현재 스테이지에서 멈춰 있는 인원을 전체 인원에서 제외
            total -= fail[i];
        }
    }
    
    // 실패율 기준 내림차순, 실패율이 같으면 스테이지 번호가 작은 순으로 정렬
    sort(failureRate.begin(), failureRate.end(), [](auto &a, auto &b)
    {
        if(a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    });
    
    vector<int> answer;
    for(auto &p : failureRate)
        answer.push_back(p.first);
    
    return answer;
}