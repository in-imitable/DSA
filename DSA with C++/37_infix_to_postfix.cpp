#include<bits/stdc++.h>
using namespace std;

int precedence(char ch){
    if(ch=='^')
    return 3;
    else if(ch=='*' || ch=='/')
    return 2;
    else if(ch=='+' || ch=='-')
    return 1;
    else
    return -1;
}

//The main function to convert infix expression to postfix
void infixToPostfix(string infix){
    stack<char> s; //Builld in stack from standard library
    string postfix;

    for(int i=0; i<infix.length(); i++){
        char ch = infix[i];

        //If the scanned character in infix is an operand, add it to postfix
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
            postfix += ch;

        }
        else if(ch=='('){
            s.push('(');
        }
        else if(ch==')'){
            while(s.top()!='('){
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            while(!s.empty() && precedence(infix[i])<= precedence(s.top())){
                if(ch=='^' && s.top()!='^'){
                    break;
                }
                else{
                    postfix += s.top();
                    s.pop();
                }
                
            }
            s.push(ch);
        }
    }

    while(!s.empty()){
        postfix += s.top();
        s.pop();
    }
    cout<<"The postfix is "<<postfix<<endl;
}

int main(){

    string infix;
    cout<<"Enter infix expression: ";
    cin>>infix;

    infixToPostfix(infix);

    return 0;
}