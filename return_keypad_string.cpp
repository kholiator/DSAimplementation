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

int return_keypad(int number,string *output){

if(number==0){
    output[0]="";
    return 1;
}

int remainder=number%10;
int new_number=number/10;
string s=number_string(remainder);
int smallpart=return_keypad(new_number,output);
int s_length=s.length();
for(int i=0;i<s_length-1;i++){

    for(int j=0;j<smallpart;j++){
        output[j+((i+1)*smallpart)]=output[j];

    }

}
for(int i=0;i<s.length();i++){

    for(int j=0;j<smallpart;j++){
        output[j+((i)*smallpart)]=output[j+((i)*smallpart)]+s[i];

    }

}
return s_length*smallpart;
}

int main(){
    int number;
    cin>>number;
    string *output=new string[100];
    int answer=return_keypad(number,output);

    for(int i=0;i<answer;i++){
        cout<<output[i]<<endl;
    }

    cout<<answer<<endl;


}