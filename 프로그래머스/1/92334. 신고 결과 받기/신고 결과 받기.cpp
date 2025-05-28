#include <string>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// 유저 신고 -> (여러 명 신고 가능)
// 한 유저가 같은 유저를 계속 신고하면 그건 1번 처리
// 신고 횟수가 k가 되면 유저 당 정지 메일 발송

// 신고 당한 사람 id - 신고한 사람 id set(중복 신고 방지)? 
// set size가 k를 넘기면 id_list에 담긴 id(신고한 사람) 순서대로 결과 메일 수 담기
// frodo - muzi, apeach
// con - ryan

vector<int> solution(vector<string> id_list, vector<string> report, int k) 
{
    vector<int> answer(id_list.size());
    unordered_map<string, int> userTable;
    unordered_map<string, unordered_set<string>> reportTable;

    // 이름으로 id 값을 바로 찾기 위해 hash 생성
    for (int i = 0; i < id_list.size(); i++)
        userTable[id_list[i]] = i;

    // 각 id 별로 신고당한 횟수와 신고한 사람(set으로 중복 x) 누적
    for (int i = 0; i < report.size(); i++)
    {
        // 공백으로 신고한 사람, 신고당한 사람 구분
        stringstream ss(report[i]);
        string reporter = "";
        string reportee = "";
        ss >> reporter >> reportee;

        reportTable[reportee].insert(reporter);
    }

    // 신고 횟수가 k 이상인 사람 구별 후 신고자에게 메일 전송
    for (const auto& pair : reportTable)
    {
        if (pair.second.size() >= k)
        {
            for (string name : pair.second)
            {
                int userId = userTable[name];
                answer[userId]++;
            }
        }
    }

    return answer;
}