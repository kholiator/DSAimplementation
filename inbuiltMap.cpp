#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;


int main(){

    unordered_map<string,int> unmap;

    pair<string,int>p("ab",1);
    unmap.insert(p);
    unmap["cd"]=2;

    cout<<"Size:"<<unmap.size()<<endl;
    cout<<unmap["ef"]<<endl;
    cout<<"Size:"<<unmap.size()<<endl;

    // cout<<unmap.at("gh")<<endl;

    if(unmap.count("ef")){
        cout<<"ef is present"<<endl;
    }
    if(unmap.count("gh")){
        cout<<"gh is present"<<endl;
    }

    unmap.erase("ef");
     if(unmap.count("ef")){
        cout<<"ef is present"<<endl;
    }
    cout<<"Size:"<<unmap.size()<<endl;



}