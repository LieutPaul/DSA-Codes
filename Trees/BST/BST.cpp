#include <iostream>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
bool isBST(node* root, node* l=NULL, node* r=NULL){
	if (root == NULL)
		return true;
	if (l != NULL and root->data <= l->data)
		return false;

	if (r != NULL and root->data >= r->data)
		return false;

	return isBST(root->left, l, root) && isBST(root->right, root, r);
}
int size(node* node){
    if(node == NULL)
        return 0;
    else
        return(size(node->left) + 1 + size(node->right));
}
struct node *inorderSucc(struct node *root){
    node *temp=root;
    while(temp && temp->left){
        temp=temp->left;
    }
    return temp;
}
struct node *deleteinBST(struct node* root, int key){
    if(key < root->data){
        root->left=deleteinBST(root->left,key);
    }else if(key > root->data){
        root->right=deleteinBST(root->right,key);
    }else{
        if(root->left==NULL){
            struct node *temp=root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        struct node* temp=inorderSucc(root->right);
        root->data=temp->data;
        root->right=deleteinBST(root->right,temp->data);
    }
    return root;
}
void insert(struct node *head, int data){
    struct node *newnode=new node(data);
    if(head->left!=NULL && head->right!=NULL){
        if(data > head->data){
            insert(head->right,data);
        }else{
            insert(head->left,data);
        }
    }else if(head->left ==NULL && head->right){
        if(data < head->data){
            head->left=newnode;
        }else{
            insert(head->right,data);
        }
    }else if(head->right ==NULL && head->left){
        if(data > head->data){
            head->right=newnode;
        }else{
            insert(head->left,data);
        }
    }else{
        if(data>head->data){
            head->right=newnode;
        }else{
            head->left=newnode;
        }
    }
}
bool search(struct node *head, int data){
    if(head){
        if(head->data==data){
            return true;
        }else if(data>head->data){
            return search(head->right,data);
        }else{
            return search(head->left,data);
        }
    }
    return false;
}
int lca(node* root, node* p, node* q){
    if(p->data > q->data)
        swap(p,q);
    if(root->data < p->data){
        return lca(root->right,p,q);
    }else if(root->data > q->data){
        return lca(root->left,p,q);
    }else if(root->data >= p->data && root->data <= q->data){
        return root->data;
    }
    return -1;
}
void inorder(struct node *head){
    if(head==NULL){
        return;
    }
    inorder(head->left);
    cout<<head->data<<" ";
    inorder(head->right);
}
int main(){
    struct node *head = new node(50);
    struct node *head2=head; 
    insert(head,5);
    insert(head,30);
    insert(head,8);
    insert(head,12);//delete
    insert(head,89);//delete
    insert(head,1);
    insert(head,34);
    insert(head,13);//delete
    insert(head,100);
    insert(head,25);
    head=deleteinBST(head,89);
    head=deleteinBST(head,13);
    head=deleteinBST(head,12);
    inorder(head);
    cout<<endl;
}