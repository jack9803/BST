#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct treeNode{
	int data;
	struct treeNode *left;
	struct treeNode *right;
}treeNode;

treeNode* findMin(treeNode* node){
	if(node == NULL)
		return NULL;
	if(node->left != NULL)
		return findMin(node->left);
	else
		return node;
}

treeNode* findMax(treeNode* node){
	if(node == NULL)
		return NULL;
	if(node->right != NULL)
		return findMax(node->right);
	else
		return node;
}

treeNode* Insert(treeNode* node, int data){
	if(node == NULL){
		treeNode* tmp = (treeNode*)malloc(sizeof(treeNode));
		tmp->data = data;
		tmp->left = NULL;
		tmp->right = NULL;
		return tmp;
	}
	if(data > (node->data)){
		node->right = Insert(node->right, data);
	}
	else if(data < (node->data)){
		node->left = Insert(node->left, data);
	}
	// else nothing to do as the data is already in the BST
	return node;
}

treeNode* Delete(treeNode* node, int data){

	if(node == NULL){
		printf("element not found!\n");
	}
	else if(data < (node->data)){
		node->left = Delete(node->left, data);
	}
	else if(data > (node->data)){
		node->right = Delete(node->right, data);
	}
	else{
		//Find node!
		/*Delete this node and replace it with the maximum node in the left 
		sub tree or the minimum node in the right sub tree*/
		if(node->left != NULL && node->right != NULL){
			treeNode* tmp = findMin(node->right);
			node->data = tmp->data;
			node->right = Delete(node->right, tmp->data);
		}
		else{
			treeNode* tmp = node;
			if(node->left == NULL)
				node = node->right;
			else if(node->right == NULL)
				node = node->left;
			free(tmp);
		}
	}
	return node;
}

treeNode* find(treeNode* node, int data){
	if(node == NULL){
		return NULL;
	}
	if(data > (node->data)){
		return find(node->right, data);
	}
	else if(data < (node->data)){
		return find(node->left, data);
	}
	else{
		return node;
	}
}

void inorder(treeNode* node){
	if(node == NULL)
		return;
	inorder(node->left);
	printf("%d ",node->data);
	inorder(node->right);
}

void preorder(treeNode* node){
	if(node == NULL)
		return;
	printf("%d ",node->data);
	preorder(node->left);
	preorder(node->right);
}

void postorder(treeNode* node){
	if(node == NULL)
		return;
	postorder(node->left);
	postorder(node->right);
	printf("%d ",node->data);
}


int main(void){

	treeNode *root = NULL;
    root = Insert(root, 5);
    root = Insert(root, -1);
    root = Insert(root, 3);
    root = Insert(root, -14);
    root = Insert(root, 8);
    root = Insert(root, 10);
    root = Insert(root, 9);
    root = Insert(root, 6);
    preorder(root);
	printf("\n");

    root = Delete(root,5);
    root = Delete(root,-1);
    preorder(root);
    printf("\n");

    treeNode * temp;
    temp = findMin(root);
    printf("Minimum element is %d\n",temp->data);
    temp = findMax(root);
    printf("Maximum element is %d\n",temp->data);
    temp = find(root,8);
    if(temp==NULL)
    {
            printf("Element 8 not found\n");
    }
    else
    {
            printf("Element 8 Found\n");
    }
    temp = find(root,2);
    if(temp==NULL)
    {
            printf("Element 2 not found\n");
    }
    else
    {
            printf("Element 2 Found\n");
    }

	return 0;
}