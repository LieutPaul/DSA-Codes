#include<iostream>
using namespace std;
struct BST{
    long long int key;
    int height;
    long long int count;
    struct BST *left, *right;
};
struct BST *newNode(long long int key){
    struct BST *temp = (struct BST *) malloc (sizeof (struct BST));
    temp->key = key;
    temp->left = temp->right = NULL;
    temp->height = 0;
    temp->count = 1;
    return temp;
}
int Height (struct BST *node){
    if(node){
        if (node->left && node->right){
            return 1 + max(node->left->height, node->right->height);
        }else if (node->left){
            return 1 + node->left->height;
        }else if (node->right){
            return 1 + node->right->height;
        }else{
            return 0;
        }
    }else{
        return -1;
    }
}
long long int Count (struct BST *node){
    if (node){
        if (node->left && node->right){
            return 1 + node->left->count + node->right->count;
        }else if(node->left){
            return 1 + node->left->count;
        }else if (node->right){
            return 1 + node->right->count;
        }else{
            return 1;
        }
    }else{
        return 0;
    }
}
bool AVL(struct BST * node){
    if(abs(Height (node->left) - Height (node->right)) < 2){
        return true;
    }else{
        return false;
    }
}
void Inorder(struct BST *node){
    if(node){
        Inorder (node->left);
        printf ("%lld  ", node->key);
        Inorder (node->right);
    }
}
struct BST *Search (struct BST *node, long long int X){
    while (node){
        if (X == node->key){
            return node;
        }else if (X < node->key){
            node = node->left;
        }else{
            node = node->right;
        }
    }
    return NULL;
}
struct BST *FindRank (struct BST *node, long long int rank){
    long long int r;
    if (node && rank > 0 && rank < node->count + 1){
        while (node){
            if (node->right){
                r = node->right->count + 1;
            }else{
                r = 1;
            }
            if (r == rank){
                return node;
            }else if (rank > r){
                node = node->left;
                rank = rank - r;
            }
            else{
                node = node->right;
            }
        }
    }
    return NULL;
}
long long int Rank(struct BST *node, long long int X){
    long long int rank = 1;
    while(node){
        if(X == node->key){
            if(node->right){
                rank += node->right->count;
                return rank;
            }
        }else if(X < node->key){
            rank++;
            if (node->right){
                rank += node->right->count;
            }
            node = node->left;
        }else{
            node = node->right;
        }
    }
    return rank;
}
long long int Rangecount (struct BST *node, long long int l, long long int r){
    long long int count;
    count = Rank (node, l) - Rank (node, r);
    if(Search(node, l)){
        count++;
    }
    return count;
}
struct BST *Rotate (struct BST *Z){
    struct BST *X, *Y, *T1, *T2, *T3, *T4;
    int c = 0;
    if (Height(Z->left) + 1 == Z->height){
        Y = Z->left;
    }else{
        Y = Z->right;
        c++;
    }
    c = c * 2;
    if (Height (Y->left) + 1 == Y->height){
        X = Y->left;
    }else{
        X = Y->right;
        c++;
    }
    if (c == 0){
        T3 = Y->right;
        Y->right = Z;
        Z->left = T3;
        Z->height = Height (Z);
        X->height = Height (X);
        Y->height = Height (Y);
        Z->count = Count (Z);
        X->count = Count (X);
        Y->count = Count (Y);
        return Y;
    }else if(c == 3){
        T2 = Y->left;
        Y->left = Z;
        Z->right = T2;
        Z->height = Height (Z);
        X->height = Height (X);
        Y->height = Height (Y);
        Z->count = Count (Z);
        X->count = Count (X);
        Y->count = Count (Y);
        return Y;
    }else if (c == 1){
        T2 = X->left;
        T3 = X->right;
        Y->right = T2;
        Z->left = T3;
        X->left = Y;
        X->right = Z;
        Z->height = Height (Z);
        Y->height = Height (Y);
        X->height = Height (X);
        Z->count = Count (Z);
        Y->count = Count (Y);
        X->count = Count (X);
        return X;
    }else{
        T2 = X->left;
        T3 = X->right;
        Y->left = T3;
        Z->right = T2;
        X->left = Z;
        X->right = Y;
        Z->height = Height (Z);
        Y->height = Height (Y);
        X->height = Height (X);
        Z->count = Count (Z);
        Y->count = Count (Y);
        X->count = Count (X);
        return X;
    }
}

struct BST *Insert (struct BST *node, long long int key){
    if(!node){
        return newNode (key);
    }
    if (key < node->key){
        node->left = Insert (node->left, key);
    }else if (key > node->key)
        node->right = Insert (node->right, key);
    
    node->height = Height(node);
    node->count = Count(node);
    if (!AVL(node)){
        node = Rotate (node);
    }
    return node;
}
struct BST *Delete (struct BST *node, long long int X){
    if (!node){
        return node;
    }
    
    if (node->key > X){
        node->left = Delete(node->left, X);
        node->height = Height(node);
        node->count = Count(node);
        if(!AVL(node))
            node = Rotate (node);
        return node;
    }else if(node->key < X){
        node->right = Delete (node->right, X);
        node->height = Height (node);
        node->count = Count (node);
        if (!AVL (node))
            node = Rotate (node);
        return node;
    }
    if(node->left && node->right){
        struct BST *temp = node->left;
        while (temp->right)
            temp = temp->right;
        node->key = temp->key;
        node->left = Delete(node->left, temp->key);
    }else{
        struct BST *child;
        if (node->left)
            child = node->left;
        else
            child = node->right;
        free (node);
        return child;
    }
}
int main(){
    struct BST *MedianNode=(struct BST*) malloc(sizeof(struct BST));
    struct BST *root = NULL;
    int choice;
    long long int x,number=0;
    while(true){
        cout<<"1 for insert, 2 for delete, 3 for median, 4 for printing numbers"<<endl;
        cin>>choice;
        if(choice == 1){
            number++;
            cin>>x;
            root=Insert(root,x);
        }else if(choice == 2){
            cin>>x;
            root=Delete(root,x);
            number--;
        }else if(choice == 3){
            MedianNode=FindRank(root,(number/2)+1);
            cout<<MedianNode->key<<endl;
        }else if(choice == 4){
            Inorder(root);
            cout<<endl;
        }
    }
}

