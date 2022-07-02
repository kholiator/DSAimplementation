#include<iostream>
using namespace std;
void subsequence_string_inhanced(string input,string output){
    if(input.length()==0){
        cout<<output<<endl;
        return;
    }

    subsequence_string_inhanced(input.substr(1),output);
    subsequence_string_inhanced(input.substr(1),output+input[0]);
}

int main(){

    string input;
    cin>>input;
    int n=input.length();
    string output="";
   

    subsequence_string_inhanced(input,output);


}
