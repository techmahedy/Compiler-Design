#include<bits/stdc++.h>
using namespace std;
stack <char> stk;
stack <int> stk2;
queue <char> que;
char str[100];

int main(){
    int i;
    char front_char;
    cout<<"Enter Equation to Check"<<endl;

    scanf("%s",str);
    for(i=0; str[i]; i++){
        if(str[i] == '(')
            stk.push('(');
        else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
            stk.push(str[i]);
        else if(str[i] == ')'){
            while(!stk.empty()){
                front_char = stk.top();
                stk.pop();
                if(front_char == '(')
                    break;
                que.push(front_char);
            }
        }
        else{
            que.push(str[i]);
        }
    }

    while(!stk.empty()){
        front_char = stk.top();
        stk.pop();
        que.push(front_char);
    }

     int a1,a2;

    while(!que.empty()){
        front_char = que.front();
        que.pop();
        if(front_char == '(' || front_char == ')'){
            cout<<"Incorrect"<<endl;
            return 0;
        }
        if(front_char == '+' || front_char == '-' || front_char == '*' || front_char == '/'){
            if(stk2.empty()){
                cout<<"Incorrect"<<endl;
                return 0;
            }
            a1 = stk2.top();
            stk2.pop();
             if(stk2.empty()){
                cout<<"Incorrect"<<endl;
                return 0;
            }
            a2 = stk2.top();
            stk2.pop();

            if(front_char == '+')
                stk2.push(a1+a2);
            if(front_char == '-')
                stk2.push(a1-a2);
            if(front_char == '*')
                stk2.push(a1*a2);
            if(front_char == '/')
                stk2.push(a1/a2);
        }
        else
           stk2.push(front_char-'0');
    }
    cout<<"Valid Equation"<<endl<<endl;
 return 0;
}
