#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

// string(uid) - string(이름)
// enter - hash에 데이터 저장
// change - hash에 등록된 이름 수정
// leave ...

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> table;

    for (int i = 0; i < record.size(); i++)
    {
        string command, uid, name;

        // 공백을 기준으로 문자열 자르기
        stringstream ss(record[i]);
        ss >> command >> uid >> name;

        if (command == "Enter" || command == "Change")
        {
            table[uid] = name;
        }
    }

    for (int i = 0; i < record.size(); i++)
    {
        string command, uid;

        // 공백을 기준으로 문자열 자르기
        stringstream ss(record[i]);
        ss >> command >> uid;

        if (command == "Enter")
        {
            string str = table[uid] + "님이 들어왔습니다.";
            answer.push_back(str);
        }
        else if(command == "Leave")
        {
            string str = table[uid] + "님이 나갔습니다.";
            answer.push_back(str);
        }
    }

    return answer;
}