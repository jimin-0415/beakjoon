#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    // arr 원소 순서 유지.
    // 1,1,3,3,0,1,1 \ 1,3,0,1
    
    //필요한 것 Queue 가 먼저 필요함. 
    // 선입 선출에 필요하니까
    
    vector<int> answer;
    queue<int> q;
    
    int old = -1;
    for( auto element : arr )
    {
        if( old == -1 )
        {
            q.push(element);
        }
        else 
        {
            if( old != element )
                q.push(element);
        }
        old = element;
    }
    
    while( !q.empty())
    {
        answer.push_back(q.front());
        q.pop();
    }

    return answer;
}