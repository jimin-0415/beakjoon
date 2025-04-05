#include <string>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

long long solution(int n, vector<int> works) {
    //1. Demi 는 야근을 한다 야근을 하면 피로도가 쌓인다..
    //2. 1시간에 작업량은 1이다. 
    //3. 야근 피로도 계산이 필요하다.
    // 이걸 처음 보면 우선순위 큐.
    
    long long answer = 0;
    
    priority_queue<int> pq;
    
    for( auto work : works ){
        pq.push( work );
    } 
    
    while( n > 0 ){
        auto work = pq.top();
        pq.pop();
        
        if( work == 0 )
            return 0;
        
        // 시간을 소모
        work -= 1;
        pq.push(work);
        n--;
    }
    
    while( !pq.empty() ){
        auto work = pq.top();
        pq.pop();
        answer += pow( work, 2 );        
    }
    
    return answer;
}