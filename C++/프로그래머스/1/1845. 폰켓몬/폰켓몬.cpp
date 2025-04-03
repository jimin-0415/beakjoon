#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{    
    // 최대 포켓몬 개수와, pickup 개수의 차이 문제
 
    int pickupCount = nums.size() / 2;
    unordered_set<int> pocketSet;
    
    for( int num : nums )
        pocketSet.insert( num );
    
    if( pocketSet.size() > pickupCount )
        return pickupCount;

    return pocketSet.size();
}