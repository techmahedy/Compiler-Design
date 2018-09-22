#include<bits/stdc++.h>
using namespace std;
void sentance_devider(char *x, char *y, string s);
char x[100],y[100];
class grammar{
   public:

       int checking_sentance(string s2){

           sentance_devider(x,y,s2);
           if(pronoun(x) && verbphrase(y))
            cout<<"Sentence is correct"<<endl;

           else if(determiner(x)){
            sentance_devider(x,y,y);
            if(noun(x))
            cout<<"Sentence is correct"<<endl;

            else if(noun(x) && verbphrase(y))
            cout<<"Sentence is correct"<<endl;
           }
           else
            cout<<"Sentence is not correct"<<endl<<endl;
            return 0;
       }

       bool noun(string n){
           if(n=="book" || n=="girl" || n=="boy")
            return true;
            else
            return false;
       }
       bool pronoun(string pro){
           if(pro=="he" || pro=="she")
            return true;
            else
            return false;
       }
       bool verbphrase(string v){
           if(v=="reads" || v=="gives")
            return true;
            else
            return false;
       }
       bool determiner(string t){
           if(t=="the" || t=="a")
            return true;
            else
            return false;
       }
};

int main(){
  grammar object;
  string s;
  while(1){
    getline(cin,s);
    object.checking_sentance(s);
  }
 return 0;
}


void sentance_devider(char *x, char *y, string s){
    int i,j;
    for(i=0; s[i]; i++){
        if(s[i] != ' '){
            x[i] = s[i];
        }else
         break;
    }

     x[i] = '\0';
     i++;

     for(j=0; s[i]; i++)
        y[j++] = s[i];
        y[j] = '\0';

}
