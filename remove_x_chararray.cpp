#include<iostream>
using namespace std;
 void remove_x_chararray(char str[],char x){

if(str[0]=='\0'){
    return;
}

if(str[0]!=x){
    remove_x_chararray(str+1,x);
}
else{
    int i=1;
    for(;str[i]!='\0';i++){
        str[i-1]=str[i];

    }
    str[i-1]=str[i];
remove_x_chararray(str,x);
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
    int i=0;

  
    char x;
    cout<<"x:"<<endl;
    cin>>x;

    remove_x_chararray(str,x);
     int size=size_char_array(str);

    for(int i=0;i<size;i++){
        cout<<str[i];
    }
    cout<<endl;
  
}