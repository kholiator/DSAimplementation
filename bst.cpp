#include<iostream>
using namespace std;
#include<climits>
#include<queue>
#include<vector>

class binaryTreeNode{
    public:
    int data;
    binaryTreeNode *left;
    binaryTreeNode*right;

    binaryTreeNode(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~binaryTreeNode(){
        delete left;
        delete right;
    }

};

binaryTreeNode* insertion(int *arr,binaryTreeNode*root){
    if(root==NULL){
        root->data=*arr;
        return root;
    }
    if(*arr>=root->data){
        root->right=insertion(arr,root->right);
        arr=arr+1;
    }
    else if(*arr<root->data){
        root->left=insertion(arr,root->left);
        arr=arr+1;
    }
    return root;


}
binaryTreeNode *insert(binaryTreeNode *temp, int data)
{
    if (temp == NULL)
    {
        temp = new binaryTreeNode(data);
        return temp;
    }
    else
    {
        if (data < temp->data)
        {
            temp->left = insert(temp->left, data);
        }
        else
        {
            temp->right = insert(temp->right, data);
        }
    }
    return temp;
}
void printTree(binaryTreeNode*root){
    if(root==NULL){
        return;
    }
    else{
        cout<<root->data<<": ";
        if(root->left!=NULL){
            cout<<"L"<<root->left->data<<" ";
        }
        if(root->right!=NULL){
            cout<<"R"<<root->right->data<<" ";
            
        }
        cout<<endl;
       printTree(root->left);
        printTree(root->right);
    }
}
binaryTreeNode* takeInputLvL(){
    queue<binaryTreeNode*>helper;

    int data;
    cout<<"Enter Data"<<endl;
    cin>>data;
    binaryTreeNode*node=new binaryTreeNode(data);
    helper.push(node);
while(!helper.empty()){
    binaryTreeNode*temp=helper.front();
        cout<<"Enter left child of "<<temp->data<<" "<<endl;
        int x;
        cin>>x;
        if(x!=-1){
        binaryTreeNode*newleftnode=new binaryTreeNode(x);
        helper.push(newleftnode);
        temp->left=newleftnode;
        }
        cout<<"Enter right child of "<<temp->data<<" "<<endl;
        int y;
        cin>>y;
         if(y!=-1){
        binaryTreeNode*newrightnode=new binaryTreeNode(y);
        helper.push(newrightnode);
        temp->right=newrightnode;
        }
        helper.pop();
    }

return node;

}
binaryTreeNode* search(binaryTreeNode*root,int number){
    if(root==NULL){
        return NULL;
    }
    if(number==root->data){
        return root;
    }
    else if(number>root->data){
        binaryTreeNode*smallpart=search(root->right,number);
        return smallpart; 
    }
    else if(number<root->data){
        binaryTreeNode*smallpart=search(root->left,number);
        return smallpart;
    }
}
int maxx(binaryTreeNode*root){
    if(root==NULL){
        return INT_MIN;
    }
    int smallpart1=maxx(root->left);
    int smallpart2=maxx(root->right);
    return max(smallpart1,max(smallpart2,root->data));
}
int minn(binaryTreeNode*root){
    if(root==NULL){
        return INT_MAX;
    }
    int smallpart1=minn(root->left);
    int smallpart2=minn(root->right);
    return min(smallpart1,min(smallpart2,root->data));
}

bool isBst(binaryTreeNode*root){
    if(root==NULL){
        return true;
    }
    if(root->data>maxx(root->left) && root->data<=minn(root->right) && isBst(root->left) && isBst(root->right)){
        return true;
    }
    else{
        return false;
    }

}

/*Something Went Wrong*/
pair<pair<int,int>,bool> isbst2Helper(binaryTreeNode*root){
    if(root==NULL){
        pair<pair<int,int>,bool>p;
        p.first.first=INT_MAX;
        p.first.second=INT_MIN;
        p.second=true;
    }

    pair<pair<int,int>,bool>smallpart1=isbst2Helper(root->left);
    pair<pair<int,int>,bool>smallpart2=isbst2Helper(root->right);
    int minn=min(smallpart1.first.first,min(smallpart2.first.first,root->data));
    int maxx=max(smallpart1.first.second,max(smallpart2.first.second,root->data));
    bool res=(root->data>smallpart1.first.second)&& (root->data<=smallpart2.first.first) && (smallpart1.second)&& (smallpart2.second);

    pair<pair<int,int>,bool>p;
    p.first.first=minn;
    p.first.second=maxx;
    p.second=res;
    return p;
    
}

bool isBst2(binaryTreeNode*root){
    if(root==NULL){
        return true;
    }
    pair<pair<int,int>,bool>p=isbst2Helper(root);
    return p.second;
}


bool isBst3(binaryTreeNode*root,int min=INT_MIN,int max=INT_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data<min ||root->data>max){
        return false;
    }

    bool left=isBst3(root->left,min,root->data-1);
    bool right=isBst3(root->right,root->data,max);
    return left && right;
}

binaryTreeNode* bstFromSortedArr(int arr[],int si,int ei){
    if(si>ei){
        return NULL;
    }
    int mid=(si+ei)/2;
    binaryTreeNode*root=new binaryTreeNode(arr[mid]);
    root->left=bstFromSortedArr(arr,si,mid-1);
    root->right=bstFromSortedArr(arr,mid+1,ei);
    return root;


}

vector<int>* distanceFromRoot(binaryTreeNode*root,int number){
    if(root==NULL){
        return NULL;
    }
    if(root->data==number){
        vector<int>*output;
        output->push_back(root->data);
        return output;
    }
    if(number<root->data){
        vector<int>*leftoutput=distanceFromRoot(root->left,number);
        if(leftoutput!=NULL){
            leftoutput->push_back(root->data);
            return leftoutput;
        }
    }
    if(number>root->data){
        vector<int>*rightoutput=distanceFromRoot(root->right,number);
        if(rightoutput!=NULL){
            rightoutput->push_back(root->data);
            return rightoutput;
        }
        else{
            return NULL;
        }
    }
}
binaryTreeNode*deletion(int number,binaryTreeNode*root){
    if(root==NULL){
        return NULL;
    }

    if(number<root->data){
        root->left=deletion(number,root->left);
        return root;
        
    }
    else if(number>root->data){
        root->right=deletion(number,root->right);
        return root;
    }
    else if(number==root->data){

        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        else if(root->left==NULL && root->right!=NULL){
            binaryTreeNode*temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL && root->left!=NULL){
            binaryTreeNode*temp=root->left;
            delete root;
            return temp;
        }
        else{
            binaryTreeNode*minNode=root->right;
            while(minNode->left!=NULL){
                minNode=minNode->left;
            }
            int rightMin=minNode->data;
            root->data=rightMin;
            root->right=deletion(rightMin,root->right);
            return root;

        }

    }
}


void typeNode(binaryTreeNode*root,int number){
    binaryTreeNode*helperOutput=search(root,number);
    if(helperOutput==root){
        printTree(root);
    }
    else if(helperOutput->left==NULL && helperOutput->right==NULL){
        cout<<helperOutput->data;
    }
    else{
        if(helperOutput->left!=NULL){
            cout<<"L ->"<<helperOutput->left->data<<"  ";
        }
        if(helperOutput->right!=NULL){
            cout<<"R ->"<<helperOutput->right->data<<"  ";
        }
        cout<<endl;
    }
    

}
int main(){
    // cout<<"Enter the number of Elements int BST "<<endl;

    // int n;
    // cin>>n;
    // int *arr=new int[n];
    // for(int i=0;i<n;i++){
    //     int temp;
    //     cin>>temp;
    //     arr[i]=temp;
    // }

    // binaryTreeNode*root=NULL;
    // root=insertion(arr,root);
    // printTree(root);

    binaryTreeNode *root = NULL;
    root = insert(root, 50);
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 62);
    root = insert(root, 58);
    root = insert(root, 60);
    root = insert(root, 91);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 37);
    root = insert(root, 24);

    // binaryTreeNode*root=takeInputLvL();
    // printTree(root);

//     binaryTreeNode*findNode=search(root,72);
// if(findNode==NULL){
//     cout<<"Number not found"<<endl; 
// }
// else{
//     cout<<findNode->data<<endl; 
// }

// cout<<boolalpha<<isBst(root)<<endl;
// cout<<boolalpha<<isbst2Helper(root).second<<endl;
// cout<<boolalpha<<isBst3(root)<<endl;

/*int arr[]={1,2,3,4,5,6,7,8};
binaryTreeNode*root=bstFromSortedArr(arr,0,7);
printTree(root);*/
// deletion(62,root);
// printTree(root);

cout<<"When the Node to be searched is root node"<<endl;
typeNode(root,50);

cout<<"When the node to be search is leaf Node"<<endl;
typeNode(root,24);

cout<<"When the node to be searched is internal Node"<<endl;
typeNode(root,5);

}