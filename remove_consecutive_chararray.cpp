#include<iostream>
using namespace std;
void remove_consecutive(char str[]){

if(str[0]=='\0'){
    return;
}

if (str[0]==str[1] &&str[1]!='\0'){
    int i=1;
    for(;str[i]!='\0';i++){
        str[i-1]=str[i];

    }
    str[i-1]=str[i];
remove_consecutive(str);
}
else{
    remove_consecutive(str+1);
}


}

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
    

    remove_consecutive(str);
     int size=size_char_array(str);

    for(int i=0;i<size;i++){
        cout<<str[i];
    }
    cout<<endl;
  
}