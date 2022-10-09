#include<iostream>
#include<stack>
#include<map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        
        map<char, char>bracket_check;
        bracket_check[')'] = '(';
        bracket_check[']'] = '[';
        bracket_check['}'] = '{';

        stack<char> sign;

        for(char c : s){
            if (c == '(' || c == '[' || c == '{'){
                sign.push(c);
            }
            else if ( (c == ')' || c == ']' || c == '}') && sign.empty()){
                sign.push(c);
            }
            else if ( bracket_check[c] == sign.top() ){
                sign.pop();
            }
            else{
                break;
            }
        }
         //Empty stack -> Valid parentheses
        //Filled stak -> Invalid parentheses
        return sign.empty(); 
        
    }
};
