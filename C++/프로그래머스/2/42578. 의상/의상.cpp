#include <string>
#include <vector>
#include <unordered_map>


using namespace std;

int solution(vector<vector<string>> clothes) {
    // 1 3 1  //3 + 5 = 8
    int result = 1;
    unordered_map<string, int> clotheMap; 
    for( auto& clothepair : clothes )
        clotheMap[clothepair[1]]++;
    
    for(auto& [_, count] : clotheMap)
        result *= ( count + 1); 
    
    return result - 1;
}