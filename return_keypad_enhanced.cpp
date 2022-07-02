#include<iostream>
using namespace std;

string number_string(int n){



    if(n==2){
       return "abc";
    }
        else if(n==3){
       return "def";
        }
         else if(n==4){
       return "ghi";
        }
         else if(n==5){
       return "jkl";
         }
          else if(n==6){
       return "mno";
          }
           else if(n==7){
       return "pqrs";
           }
            else if(n==8){
       return "tuv";
            }
             else if(n==9){
       return "wxyz";
             }

    else{
        return " ";
    }
}

void return_keypad_enhanced(int number,string output){

if(number==0){
    cout<<output<<endl;
    return;
}

int lastnumber=number%10;
int newnumber=number/10;
string s=number_string(lastnumber);

for(int i=0;i<s.length();i++){
    return_keypad_enhanced(newnumber,s[i]+output);
}


}
int main(){
    int number;
    cin>>number;
    string output="";
    return_keypad_enhanced(number,output);




}