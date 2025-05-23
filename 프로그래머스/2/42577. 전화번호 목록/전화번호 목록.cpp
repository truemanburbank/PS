#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 1. 정렬으로 하는 방법
// 2. 해시

unordered_map<string, bool> phone;

// 현재 번호가 접두사로 이루어진 번호인지 확인
bool isPrefix(string number)
{
    string prefix = "";
    for (char c : number)
    {
        prefix += c;
        
        if (phone.find(prefix) != phone.end() && prefix != number)
            return true;
    }

    return false;
}

bool solution(vector<string> phone_book) {
    // hash에 등록
    for (string str : phone_book)
        phone[str] = true;

    for (string str : phone_book)
    {
        if (isPrefix(str))
            return false;
    }

    return true;
}