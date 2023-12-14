//
// Created by Святослав on 11.12.2023.
//
#include <iostream>
#include <cmath>
#include <queue>

struct node{
  long long value;
  long long depth = 1;

  node* left = nullptr;
  node* right = nullptr;

  node(long long value): value(value){};
};

long long depth(node* head){
  if(head == nullptr){
    return 0;
  } else{
    return head->depth;
  }
}

node* update(node* head){
  head->depth = std::max(depth(head->left), depth(head->right)) + 1;
  return head;
}

node* rmrotation(node* head){
  node* b = head->left;

  head->left = b->right;
  b->right = head;
  head = update(head);
  b = update(b);
  return b;
}

node* lmrotation(node* head){
  node* c = head->right;

  head->right = c->left;
  c->left = head;
  head = update(head);
  c = update(c);
  return c;
}

void preorder(node* head){
  if(head == nullptr){
    return;
  }
  std::cout << head->value << " " << head->value << '\n';
  preorder(head->left);
  preorder(head->right);
}

node* balance(node* head){
  if (head == nullptr) {
    return head;
  }
  head = update(head);
  if (depth(head->right) - depth(head->left) == 2) {
    if (depth(head->right->right) - depth(head->right->left) < 0) {
      head->right = rmrotation(head->right);
    }
    return lmrotation(head);
  }
  if (depth(head->right) - depth(head->left) == -2) {
    if (depth(head->left->right) - depth(head->left->left) > 0){
      head->left = lmrotation(head->left);
    }
    return rmrotation(head);
  }
  return head;
}

node* add(node* head, long long value){
  if(head == nullptr){
    node* tmp = new  node(value);
    tmp->depth = 1;
    return tmp;
  } else if(head->value > value){
    head->left = add(head->left, value);
  } else if(head->value < value){
    head->right = add(head->right, value);
  } else{
    head->value = value;
  }
  return balance(head);
}

node* findMin(node* head){
  if(head == nullptr || head->left == nullptr){
    return head;
  }
  return findMin(head->left);
}

node* findMax(node* head){
  if(head == nullptr || head->right == nullptr){
    return head;
  }
  return findMax(head->right);
}

node* Delete(node* head, long long value) {
  if (head == nullptr) {
    return nullptr;
  }
  else if (value > head->value) {
    head->right = Delete(head->right, value);
  } else if (value < head->value) {
    head->left = Delete(head->left, value);
  } else if (head->right != nullptr && head->left != nullptr) {
    node *max = findMax(head->left);
    head->value = max->value;
    head->left = Delete(head->left, max->value);
  } else {
    if (head->left) {
      head = head->left;
    } else if (head->right) {
      head = head->right;
    } else {
      head = nullptr;
    }
  }
  return balance(head);
}

node* search(node* head, long long value){
  node* tmp = head;
  while(tmp != nullptr){
    if(value > tmp->value){
      tmp = tmp->right;
    } else if(value < tmp->value){
      tmp = tmp->left;
    } else{
      return tmp;
    }
  }
  return nullptr;
}