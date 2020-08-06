#include<bits/stdc++.h>
using namespace std;

bool checkBalanced(string expr){
    stack<char> s;
    char top;
    for(int i=0 ;i<expr.length(); i++){
        if(expr[i]== '(' || expr[i]== '{' || expr[i]== '['){
            s.push(expr[i]);
            continue;
        }
        if(s.empty())
            return false;
        switch(expr[i]){
        case ')':
            top= s.top();
            s.pop();
            if(top== '{' || top=='[')
                return false;
            break;
        case '}':
            top= s.top();
            s.pop();
            if(top== '(' || top=='[')
                return false;
            break;
        case ']':
            top= s.top();
            s.pop();
            if(top== '(' || top=='{')
                return false;
            break;
        }
    }
    return (s.empty());
}
int main(){
    cout<< "Enter the string of parenthesis you want to check : ";
    string s;
    cin>>s;
    bool ans= checkBalanced(s);
    if(ans == true )
        cout<< "BALANCED "<<endl;
    else
        cout<< "NOT BALANCED "<<endl;
}
