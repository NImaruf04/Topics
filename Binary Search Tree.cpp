#include<bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
using namespace std;
class node {
public:
    int val;
    node *left;
    node *right;
    
    node (int val) {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

node * input_tree(){
    int x;
    cin>>x;
    node* rote;
    if(x==-1)rote=NULL;
    else rote=new node(x);
    queue<node*>q;
    if(rote)q.push(rote);
        
    //take one value from queue and add two adjacent to it ;if the node is null then skip;
    while(!q.empty()){
        node* f=q.front();
        q.pop();
        int ab,ac;
        cin>>ab>>ac;
        node* left;
        node* right;
        if(ab!=-1)left=new node(ab);
        else left=NULL;
        if(ac!=-1)right=new node(ac);
        else right =NULL;
        f->left=left;
        f->right=right;
   if(f->left)q.push(f->left);
   if(f->right)q.push(f->right);

    }
    return rote;
 }

bool search(node* root, int val){
    if(root==NULL)return false;
    if(root->val==val)return true;
    if(root->val<val)return search(root->right,val);
    else return search(root->left,val);
}

//works
//insert a value

void insert(node* &root,int val){
    if(root==NULL){
        root=new node(val);
        return;
    }
    if(root->val<val){
        if(root->right==NULL){root->right=new node(val);}
        else insert(root->right,val);
    }
    else {
        if(root->left==NULL){root->left=new node(val);}
        else insert(root->left,val);
    }

}


void printlevelth(node* rote){
    if(rote==NULL){cout<<"tree nai"<<endl;return;}
    queue<node *>x;
    x.push(rote);
    while(!x.empty()){
        node* p=x.front();
        x.pop();
        cout<<p->val<<" ";
        if(p->left)x.push(p->left);
        if(p->right)x.push(p->right);
    }
}
//create bst from array ;
node* convert(int ar[],int size,int l,int r){
    if(l>r)return NULL;
    int mid=(l+r)/2;
    node* root=new node(ar[mid]);
    root->left=convert(ar,size,l,mid-1);
    root->right=convert(ar,size,mid+1,r);
    
    return root;
}

 int32_t main(){
    //node* root=input_tree();
    int k;
    cin>>k;
    int ar[k];
    for(int i=0;i<k;i++){cin>>ar[i];}
    node* root=convert(ar,k,0,k-1);

    //insert(root,k);
  printlevelth(root);
   
 }
