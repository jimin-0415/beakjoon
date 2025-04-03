#include <string>
#include <vector>
#include <unordered_set>


using namespace std;

bool solution(vector<string> phone_book) {
    //1안. sotring 후 1중 loop를 통해 앞의 번호가 뒷번호의 접두어인지 확인.
    //2안. 해시를 통해 접두어가 존재하는지 확인.
    
    unordered_set<string> numberSet;
    for( auto number : phone_book )
        numberSet.insert( number );
   
    for( auto number : phone_book ){
        for( int i = 0; i < number.size() - 1; i++ ){
            if( numberSet.find(number.substr(0, i+1)) != numberSet.end()){
                return false;   
            } 
        }
    }
    
    return true;
}