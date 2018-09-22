#include<bits/stdc++.h>
using namespace std;

stack <char> stk;
char str[100];

int main(){
    int i;
    char front_char;
    cout<<"Enter infix notation\n";
    scanf("%s",str);
    cout<<"Postfix notation is: ";

    for(i=0; str[i]; i++){
      if(str[i] == '(')
            stk.push('(');
      else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^' )
            stk.push(str[i]);
      else if(str[i] == ')'){
        while(!stk.empty()){
            front_char = stk.top();
            stk.pop();
            if(front_char == '(')
                break;
           cout<<front_char;
         }
      }
         else
            cout<<str[i];
    }
    while(!stk.empty()){
        front_char = stk.top();
        stk.pop();
        cout<<front_char;
    }
return 0;
}
