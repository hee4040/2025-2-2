#include <iostream>
using namespace std;

struct node
{
  int key;
  struct node *left, *right;
};

struct node *newNode(int item)
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp -> key = item;
  temp -> left = temp -> right = NULL;
  return temp;
}

struct node *insert(struct node *node, int key)
{
  if(node == NULL)return newNode(key);                    // 현재 노드가 NULL이면 새로운 노드를 만들어줌

  if(key < node->key)                                     // 키가 노드의 값보다 작으면 왼쪽에 insert
    node -> left = insert(node->left, key);
  else                                                    // 키가 노드의 값보다 크면 왼쪽에 insert
    node-> right = insert(node->right, key);
  return node;
}

struct node *search(struct node *node, int key)
{
  if(node==NULL) return NULL;
  if(key == node->key)return node;
  else if(key<node->key) return search(node-> left, key);
  else if(key>node->key) return search(node-> right, key);
}

struct node *deleteNode(struct node *root, int key)
{
  if(root==NULL) return root;

  if(key < root -> key)
    root -> left = deleteNode(root -> left, key);
  else if(key > root -> key)
    root -> right = deleteNode(root -> right, key);
  else{
    if(root->left == NULL){                               // 자식이 하나만 있거나 없는 경우
      struct node *temp = root-> right;
      free(root);
      return temp;
    }
    else if(root-> right == NULL){
      struct node *temp = root->left;
      free(root);
      return temp;
    }
    struct node *temp = minValueNode(root->right);       // 자식이 두개일때

    root->key = temp->key;

    root->right = deleteNode(root->right, temp->key);
  }
  return root;
};

struct node *minValueNode(struct node *node)
{
  struct node *current = node;

  while (current && current->left != NULL)
    current = current->left;
  
  return current;
};


