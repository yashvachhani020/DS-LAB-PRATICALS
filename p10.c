#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node *left, *right;
};

struct Node* createNode(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->left = NULL;
newNode->right = NULL;
return newNode;
}

// Inorder Traversal (Left -> Root -> Right)
void inorder(struct Node* root) {
if (root != NULL) {
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
}

// Preorder Traversal (Root -> Left -> Right)
void preorder(struct Node* root) {
if (root != NULL) {
printf("%d ", root->data);
preorder(root->left);

preorder(root->right);
}
}

void postorder(struct Node* root) {
if (root != NULL) {
postorder(root->left);
postorder(root->right);
printf("%d ", root->data);
}
}

void main() {

struct Node* root = createNode(10);
root->left = createNode(20);
root->right = createNode(30);
root->left->left = createNode(40);
root->left->right = createNode(50);
root->right->left = createNode(60);
root->right->right = createNode(70);

printf("Inorder Traversal: ");
inorder(root);

printf("\nPreorder Traversal: ");
preorder(root);
printf("\nPostorder Traversal: ");
postorder(root);
getch();
}