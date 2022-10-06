#include<iostream>

using namespace std;

bool isPalindrome(string);

int main(){
    if (isPalindrome("A man, a plan, a canal: panam")){
        cout<<"A palindrome";
    }

    else{
        cout<<"not a palindrome";
    }

    return 0;
}

bool isPalindrome(string s) {
    string pre_proccesed ="";  

    for(char a : s){
        if(isdigit(a))
            pre_proccesed+=a;
        else if(isalpha(a))
            pre_proccesed+= tolower(a);
    }

    unsigned int word_size = pre_proccesed.length();

    for(int i = 0; i<word_size/2; ++i) 
        if(pre_proccesed[i] != pre_proccesed[word_size-i-1])
            return false;

    return true;   
}