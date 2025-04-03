#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    // 중복처리가 있네..
    string answer = "";
    unordered_map<string, int> completionMap;
    
    for( auto _completion : completion) 
        completionMap[_completion]++;
    
    for(auto _participant : participant)
    {
        if( --completionMap[_participant] < 0 )
        {
            answer = _participant;
            break;
        }
    }
    
    return answer;
}