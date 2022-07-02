#include<iostream>
#include<math.h>
using namespace std;

int subsequence_string(string input, string *output){

    if(input==""){
        output[0]="";
        return 1;
    }

    string smallstring=input.substr(1);

    int smallpart=subsequence_string(smallstring,output);
    for(int i=0; i<smallpart;i++){
        output[i+smallpart]=input[0] + output[i];
    }

    return 2*smallpart;
}

int main(){

    string input;
    cin>>input;
    int n=input.length();
    int outputsize=pow(2,n);
    string *output=new string[outputsize];

    int l=subsequence_string(input,output);

    for(int i=0;i<l;i++){
        cout<<output[i]<<endl;
    }


}
