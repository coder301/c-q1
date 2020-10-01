#include<bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    
    BinaryTreeNode(T data){
        this->data=data;
        left=NULL;
        right = NULL;
    }
    
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

BinaryTreeNode<int>* takeInputLevelwise(){
    int rootdata;
     cout<<"Enter root data"<<endl;
    cin>>rootdata;
    if(rootdata == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!= 0){
        BinaryTreeNode<int>*front = pendingnodes.front();
        pendingnodes.pop();
        cout<<"Enter the left child"<<front->data<<endl;
        int leftchilddata;
        cin>>leftchilddata;
        if(leftchilddata!=-1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftchilddata);
            front->left = child;
            pendingnodes.push(child);
        }
        cout<<"Enter the right child"<<front->data<<endl;
        int rightchilddata;
        cin>>rightchilddata;
        if(rightchilddata!=-1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightchilddata);
            front->right = child;
            pendingnodes.push(child);
        }
    }
    return root;
}

void printtree(BinaryTreeNode<int>* root){
    if(root ==NULL){
        return;
    }
    cout<<root->data<<";";
  if(root->left){
      cout<<"L"<<root->left->data;
  }    
  if(root->right){
      cout<<"R"<<root->right->data;
  }
  cout<<endl;
  printtree(root->left);
  printtree(root->right);
}
void printLevelwise(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0){
        BinaryTreeNode<int>* front = pendingnodes.front();
        pendingnodes.pop();
        cout<<front->data<<":";
        if(front->left){
            cout<<"L:"<<front->left->data<<",";
            pendingnodes.push(front->left);
        }
        else{
            cout<<"L:-1,";
        }
        if(front->right){
            cout<<"R:"<<front->right->data<<",";
            cout<<endl;
            pending.push(front->right);
        }
        else{
            cout<<"R:-1,";
            cout<<endl;
        }
        
    }
}

int numNodes(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    return 1 + numNodes(root->left)+numNodes(root->right);
}
int main(){
    
    BinaryTreeNode<int>* root = takeInputLevelwise();
    printLevelwise(root);
    cout<<"Number of Nodes is: "<<numNodes(root)<<endl;
    delete(root);
}
