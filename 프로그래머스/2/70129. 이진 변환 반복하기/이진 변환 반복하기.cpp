#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

vector<int> solution(string s) 
{
    vector<int> answer;

    int binaryCnt = 0;
    int totalZero = 0;

    while (s != "1")
    {
        // 모든 0 제거
        auto zeroBegin = remove(s.begin(), s.end(), '0');
        int zeroCnt = distance(zeroBegin, s.end());
        totalZero += zeroCnt;
        s.erase(zeroBegin, s.end());

        // 0을 제거한 s의 길이를 c라 한다.
        int c = s.size();

        // 이진 변환
        // s는 최대 15만이므로, 18비트로 표현할 수 있다. 
        bitset<18> binary(c);
        s = binary.to_string();
        s = s.substr(s.find('1'));
        binaryCnt++;
    }
   
    answer = { binaryCnt, totalZero };

    return answer;
}

int main()
{
    solution("110010101001");
}