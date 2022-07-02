#include<iostream>
using namespace std;
#include<vector>
#include<queue>

template<typename T>
class treeNode{

    public:
    T data;
    vector<treeNode*>children;

    treeNode(T data){
        this->data= data;
    }
    ~treeNode(){
        for(int i=0;i<this->children.size();i++){
            delete children[i];
        }
    }


};

void printTree(treeNode<int>*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<": ";

    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;

    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }

}

treeNode<int>* takeInput(){
    int rootNode;
    cout<<"Enter data :"<<endl;
    cin>>rootNode;
    treeNode<int>*root=new treeNode<int>(rootNode);
    cout<<"Enter Number of Children for Above Node: "<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        treeNode<int>*child=takeInput();
        root->children.push_back(child);
    }

    return root;
}

treeNode<int>* takeInput2(){
    int rootname;
    cout<<"Enter root :"<<endl;
    cin>>rootname;

    treeNode<int>*root=new treeNode<int>(rootname);
    queue<treeNode<int>*>node;
    node.push(root);
    while(node.size()!=0){
    treeNode<int>*front=node.front();
    cout<<front->data<<"+++++++++"<<endl;
    node.pop();
    cout<<"Enter the number of Children for "<<front->data<<" :"<<endl;
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        cout<<"Enter Children"<<endl;
        int data;
        cin>>data;
    treeNode<int>*newNode=new treeNode<int>(data);
    node.push(newNode);
    front->children.push_back(newNode);
    }
    }
    return root;

}

int countNodes(treeNode<int>*root){
    if(root==NULL){
        return 0;
    }
    int count=0;
    count++;

    for(int i=0;i<root->children.size();i++){
        count=count+countNodes(root->children[i]);
    }
    return count;
}

//wrong implementation(may be correct now--reviewed)
int heightTree(treeNode<int>*root){

    if(root==NULL){
        return 0;
    }
    int max=0;
    for(int i=0;i<root->children.size();i++){
    int count=1;
        count=count+heightTree(root->children[i]);
        if(count>max){
            max=count;
        }
    }
    return max;
}

void nodeAtKLevel(treeNode<int>*root,int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<endl;
    }
    for(int i=0;i<root->children.size();i++){
        nodeAtKLevel(root->children[i],k-1);
    }
}

int countLeafNodes(treeNode<int>*root){
    if(root->children.size()==0){
        return 1;
    }
    int count=0;
    for(int i=0;i<root->children.size();i++){
        count=count+countLeafNodes(root->children[i]);
    }

return count;
}

void preorder(treeNode<int>*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        preorder(root->children[i]);
    }
}

void postorder(treeNode<int>*root){
    if(root==NULL){
        return;
    }
    for(int i=0;i<root->children.size();i++){
        postorder(root->children[i]);
    }
    cout<<root->data<<" ";
}


int nextLargerValue(treeNode<int>*root,int n){
    if (root==NULL){
        return 0;
    }
    int ans=0;
    if(root->data>n){
        ans=root->data;
    }

    for(int i=0;i<root->children.size();i++){
        int temp= nextLargerValue (root->children[i],n);
        if(temp==0){
            continue;
        }
        if( ans>temp || ans==0){
            ans=temp;
        }

    }

    return ans;
}
void changewithDepth(treeNode<int>*root,int n){
    root->data=n;
    for(int i=0;i<root->children.size();i++){
        changewithDepth(root->children[i],n+1);
    }
}

pair<treeNode<int>*,int> maxChildSum(treeNode<int>*root){
int sum=root->data;
    for(int i=0;i<root->children.size();i++){
sum=sum+root->children[i]->data;
    }
    pair<treeNode<int>*,int>p;
    p.first=root;
    p.second=sum;

    for(int i=0;i<root->children.size();i++){
       pair<treeNode<int>*,int>smallpart=maxChildSum(root->children[i]);

       if(smallpart.second>p.second){
           p=smallpart;
       }
    }

    return p;
}

int main(){
    // treeNode<int> *root=new treeNode<int>(10);
    // treeNode <int>*node1=new treeNode<int>(11);
    // treeNode <int>*node2=new treeNode<int>(12);

    // root->children.push_back(node1);
    // root->children.push_back(node2);


    // cout<<root->data<<" "<<root->children[0]->data<<" "<<root->children[1]->data<<endl;

    // treeNode<int>*root = takeInput();
    treeNode<int>*root = takeInput2();


    printTree(root);
    // cout<<countNodes(root)<<endl;
    // // cout<<heightTree(root)<<endl;
    // nodeAtKLevel(root,3);
    // cout<<"Count leafNodes :"<<countLeafNodes(root)<<endl;
    // preorder(root);
    // cout<<endl;
    // postorder(root);
    // cout<<nextLargerValue(root,1)<<endl;
    // changewithDepth(root,0);
    // printTree(root);

    // cout<<maxChildSum(root).first->data<<" "<<maxChildSum(root).second<<endl;
    cout<<heightTree(root)<<endl;




}
// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0