#include<iostream>
using namespace std;

int size_char_array(char c[]){
if(c[0]=='\0'){
    return 0;
}

int size=size_char_array(c+1);
return size+1;

}
int main(){
    char str[100];
    cin>>str;
    int i=0;

  
    int size=size_char_array(str);
    cout<<size<<endl;
}