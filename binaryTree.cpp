#include<iostream>
using namespace std;
#include<queue>

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

binaryTreeNode* takeInput(){
    int data;

    cout<<"Enter Data"<<endl;
    cin>>data;
    if(data==0){
        return NULL;
    }
    binaryTreeNode*root=new binaryTreeNode(data);

cout<<"Enter left child of "<<root->data<<" :"<<endl;
    root->left=takeInput();
cout<<"Enter right child of "<<root->data<<" :"<<endl;
    root->right=takeInput();
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

int countNodes(binaryTreeNode*root){
    if(root==NULL){
        return 0;
    }

    int smallpart=countNodes(root->left)+ countNodes(root->right);
    return smallpart+1;
}


//Something went wrong
bool findNode(binaryTreeNode*root,int nodeData){
    if(root==NULL){
        return false;
    }

    if(root->data==nodeData){
        return true;
    }

    bool small1=root->left;
    bool small2=root->right;
    // if(small1==true || small2==true){
    //     return true;
    // }
    // else{
    //     return false;
    // }

    if(small1==false && small2==false){
        return false;
    }

    else{
        return true;
    }

}
int heightTree(binaryTreeNode*root){
     if (root==NULL){
         return 0;
     }

     int small1=heightTree(root->left);
     int small2=heightTree(root->right);
     if(small1>=small2){
         return small1+1;
     }
     else{
         return small2+1;
     }
}

void mirror(binaryTreeNode*root){
    if(root==NULL){
        return;
    }
    binaryTreeNode*temp=root->left;
    root->left=root->right;
    root->right=temp;
    mirror(root->left);
    mirror(root->right);
}

void inorderTraversal(binaryTreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << "  ";
    inorderTraversal(root->right);
}
void preorderTraversal(binaryTreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << "  ";
    inorderTraversal(root->left);
    inorderTraversal(root->right);
}
void postorderTraversal(binaryTreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    inorderTraversal(root->right);
    cout << root->data << "  ";
}

binaryTreeNode* constructFromInandPreOrder(int in[],int pre[],int inst,int inend,int prest,int preend){
    if(inst>inend){
        return NULL;
    }
    int rootdata=pre[prest];
    // binaryTreeNode*root;
    // root->data=pre[prest];
    int linst=inst;
    int lprest=prest+1;
    int rootindex=-1;
    for(int i=inst;i<=inend;i++){
        if(in[i]==rootdata){
            rootindex=i;
            break;
        }
    }
    int linend=rootindex-1;
    int lpreend=(linend-linst)+lprest;

    int rinst=rootindex+1;
    int rinend=inend;
    int rprest=lpreend+1;
    int rpreend=preend;
    binaryTreeNode*root=new binaryTreeNode(rootdata);
    root->left=constructFromInandPreOrder(in,pre,linst,linend,lprest,lpreend);
    root->right=constructFromInandPreOrder(in,pre,rinst,rinend,rprest,rpreend);

    return root;
}

int diametre(binaryTreeNode*root){
    if(root==NULL){
        return 0;
    }
    int LplusR=heightTree(root->left)+heightTree(root->right);
    int smallpart1=diametre(root->left);
    int smallpart2=diametre(root->right);
    return max(LplusR,max(smallpart1,smallpart2));
}
pair<int,int> diameterHeight(binaryTreeNode*root){
    if(root==NULL){
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int>leftAns=diameterHeight(root->left);
    pair<int,int>rightAns=diameterHeight(root->right);

    int lh=leftAns.first;
    int ld=leftAns.second;
    int rh=rightAns.first;
    int rd=rightAns.second;

    int height=1+max(lh,rh);
    int diameter=max(lh+rh,max(ld,rd));
    pair<int,int>p;
    p.first=height;
    p.second=diameter;

    return p;
}


int main(){
    // binaryTreeNode*root= takeInput();
    // binaryTreeNode*root= takeInputLvL();
// printTree(root);

//     // cout<<"NUMBER OF NODES : "<<countNodes(root)<<endl;

//     // cout<<boolalpha<<findNode(root,8);
//     cout<<"Height of tree "<<heightTree(root)<<endl;

//    mirror(root);
//    printTree(root); 
// inorderTraversal(root);
// int in[]={4,2,5,1,8,6,9,3,7};
// int pre[]={1,2,4,5,3,6,8,9,7};
// binaryTreeNode*root=constructFromInandPreOrder(in,pre,0,8,0,8);
// printTree(root);


binaryTreeNode*root=takeInputLvL();
printTree(root);
// pair<int,int>p=diameterHeight(root);
// cout<<"Success"<<endl;

// cout<<"Height of tree is :"<<p.first<<endl;
// cout<<"Diameter of tree is :"<<p.second<<endl;
cout<<boolalpha<<findNode(root,1)<<endl;
cout<<boolalpha<<findNode(root,11)<<endl;


} 
// 1 2 4 -1 3 5 6 -1 -1 7 -1 -1 -1 -1 -1 