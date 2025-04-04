#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    //1. 첫괄호 ) 마지막 (일경우
    //2. 개수가 같지 않으면 안닫힘.
    //3. (() 같자기 비정상적으로 많아질경우 2개 -> 3개 -> 2개?
    
    //1. stack을 통해서 한다면, 초기 ( 부터 시작 만약 스택이 비었는데 ) 부터 들어오면 fail
    //2. ( 들어올경우 stack에 넣기. ) 반대가 올경우 pop처리.
    bool answer = true;
    
    stack<char> _stack;
    
    for( char ch : s ) {
        if(ch == '(')
            _stack.emplace(ch);
        else 
        {
            if(_stack.empty())
                return false;
            else 
                _stack.pop();
        }
    }
    
    return _stack.empty();
}