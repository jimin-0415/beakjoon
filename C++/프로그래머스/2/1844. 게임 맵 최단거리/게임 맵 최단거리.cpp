#include<vector>
#include<queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    // 격자 이동 + BFS
    // queue 를 이용하여 BFS 처리.
    // dist 배열의 통해서 지나온 거리중 최단거리 갱신.
    // n m 도닥하면 값 리턴.
    // 만약 도달 못했다면 -1
    int answer = 0;
    
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<int>> dist( n, vector<int>(m, -1));
    dist[0][0] = 1;
    
    int dx[4] = { 1, -1 , 0, 0 };
    int dy[4] = { 0, 0, 1, -1  };
    
    queue<pair<int,int>> q;
    q.push({0,0});
    
    while( !q.empty())
    {
        auto& [x, y] = q.front();
        q.pop();
        
        for( int i = 0 ; i < 4; i++)
        {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            
            // 1. 일단 다음 위치 정보가 레인지 범위를 벗어나지 않는다.
            // 2. 다음 위치가 이동 가능 지역이다.
            // 3. 다음 위치가 기록되기 전 상태이다. (visited)
            if( nextX >=0 && 
               nextY >= 0 && 
               nextX < n && 
               nextY < m && 
              maps[nextX][nextY] == 1 && 
              dist[nextX][nextY] == -1 )
            {
                // distance를 기록한다. 이동전 위치 + 1;
                dist[nextX][nextY] = dist[x][y] + 1;
                q.push({nextX, nextY});
            }
        }
    }
    
    return dist[ n -1 ][ m-1 ];
}