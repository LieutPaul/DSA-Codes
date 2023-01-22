#include<iostream>
#include<vector>
using namespace std;

struct node {
	int key;
	struct node *left, *right;
};
struct node* newNode(int item)
{
	struct node* temp = new node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}
void reversePath(struct node* node, int& key){
    struct node *temp=node;
    vector<int> path;
    while(node){
        if(node->key == key){
            path.push_back(node->key);
            break;
        }else if(node->key>key){
            path.push_back(node->key);
            node=node->left;
        }else{
            path.push_back(node->key);
            node=node->right;
        }
    }
    int c=path.size()-1;
    node=temp;
    while(node){
        if(node->key == key){
            node->key=path[c];
            break;
        }else if(node->key>key){
            node->key=path[c];
            c--;
            node=node->left;
        }else{
            node->key=path[c];
            c--;
            node=node->right;
        }
    }
    
}

struct node* insert(struct node* node,int key){
	if (node == NULL)
		return newNode(key);
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	return node;
}

// Driver Program to test above functions
int main()
{
		/*	50
		/	 \
		30	 70
		/ \ / \
	20 40 60 80 */
	struct node* root = NULL;
	int k = 80;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	cout << "Before Reverse :" << endl;
	inorder(root);
    cout << "\n";
	reversePath(root,k);
	cout << "After Reverse :" << endl;
	inorder(root);

	return 0;
}
