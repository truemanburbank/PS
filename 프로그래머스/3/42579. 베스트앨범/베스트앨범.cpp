#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 장르 > 재생 횟수 > 고유 번호 순으로 정렬 후 장르 별로 두 개씩 뽑음
// unordered_map으로 각 장르별 재생 횟수 저장
// vector로 정렬? 위 규칙대로 함수 만들어서.

// data 생성
struct music
{
    long long plays; // 재생 횟수
    int i; // 고유 번호
};

unordered_map<string, long long> genresPlays;
unordered_map<string, vector<music>> musics_sorted;

bool cmp(const music& a, const music& b)
{
    if (a.plays == b.plays)
        return a.i < b.i;
    return a.plays > b.plays;
}

vector<int> solution(vector<string> genres, vector<int> plays) 
{
    // 장르별 재생횟수 갱신 
    for (int i = 0; i < genres.size(); i++)
        genresPlays[genres[i]] += plays[i];
    
    // 음악 데이터 저장
    for (int i = 0; i < genres.size(); i++)
    {
        music m;
        m.plays = plays[i];
        m.i = i;
        musics_sorted[genres[i]].push_back(m);
    }

    for (auto& m : musics_sorted)
        sort(m.second.begin(), m.second.end(), cmp);

    // value 값 기준 정렬을 위해 map을 vector로 변환
    vector<pair<string, long long>> genres_sorted;
    for (auto e : genresPlays)
        genres_sorted.push_back({ e.first, e.second });

    // 플레이한 횟수가 많은 장르 별로 정렬
    // 문제 조건에서 모든 장르는 재생된 횟수가 다름.
    sort(genres_sorted.begin(), genres_sorted.end(), [](const pair<string, long long>& a, const pair<string, long long>& b)
        {
            return a.second > b.second;
        });

    vector<int> answer;
    int idx = 0;

    // 정렬된 music에서 장르 별로 최대 두 개씩 뽑음
    for (const auto& genre_pair : genres_sorted) 
    {
        string genre = genre_pair.first;

        answer.push_back(musics_sorted[genre][0].i);

        if (musics_sorted[genre].size() > 1) 
            answer.push_back(musics_sorted[genre][1].i);
    }

    return answer;
}