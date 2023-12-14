//
// Created by Святослав on 11.12.2023.
//

#include <iostream>
#include <vector>

using namespace std;


struct node {
  int val;
  node* left = nullptr;
  node* right = nullptr;
  int height = 0;

  node(int x): val(x){};

};


struct bst{
  node* root;


  int get_height(node* t){
    if (t)
      return t->height;
    return 0;
  }

  node* update(node* t){
    t->height= 1 + max(get_height(t->left), get_height(t->right));
    return t;
  }

  node* right_rotate(node* q){
    node* p = q->left;
    q->left = p->right;
    p->right = q;

    q = update(q);
    p = update(p);

    return p;
  }

  node* left_rotate(node* q) {
    node* p = q->right;
    q->right = p->left;
    p->left = q;
    q = update(q);
    p = update(p);
    return p;
  }

  node* insert(node* x, int k){
    if (!x){
      node* t = new node(k);
      t->height = 1;
      return t;
    }

    if (k < x->val){
      x->left = insert(x->left, k);
    }
    else if (k > x->val){
      x->right = insert(x->right, k);
    } else {
      x->val = k;
    }
    return balance(x);
  }

  node* balance(node* x){
    if (!x)
      return nullptr;
    x = update(x);
    if (get_height(x->right) - get_height(x->left) == -2){
      if (get_height(x->left->right) - get_height(x->left->left) > 0)
        x->left = left_rotate(x->left);
      return right_rotate(x);
    }
    if (get_height(x->right) - get_height(x->left) == 2){
      if (get_height(x->right->right) - get_height(x->right->left) < 0)
        x->right = right_rotate(x->right);
      return left_rotate(x);
    }
    return x;
  }

  node* find (node* t, int s){
    node* x = t;
    while (x){
      if (s > x->val){
        x = x->right;
      } else if (s < x->val) {
        x = x->left;
      } else {
        return x;
      }
    }
    return nullptr;
  }
  node* del (node* t, int n) {
    if (t == nullptr)
      return t;
    if (n < t->val){
      t->left = del(t->left, n);
    } else if (n > t->val) {
      t->right = del(t->right, n);
    } else if (t->right != nullptr && t->left != nullptr){
      node* g = maxi(t->left);
      t->val = g->val;
      t->left = del(t->left, g->val);

    } else {
      if (t->left){
        t = t->left;
      } else if (t->right){
        t = t->right;
      } else {
        t = nullptr;
      }
    }
    return balance(t);
  }

  node* mini(node* t){
    if (t->left == nullptr)
      return t;
    return mini(t->left);
  }

  node* maxi(node* t){
    if (t->right == nullptr)
      return t;
    return maxi(t->right);
  }

};


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  bst tree;
  int n, t;
  cin >> n;
  string s;
  tree.root = nullptr;
  for (int j = 0; j < n; j++) {
    cin >> s;
    if (s == "A"){
      cin >> t;
      tree.root = tree.insert(tree.root, t);
      if (tree.root)
        cout << tree.get_height(tree.root->right) - tree.get_height(tree.root->left) << "\n";
      else
        cout << 0 << "\n";

    } else if (s == "C"){
      cin >> t;
      node* flag = tree.find(tree.root, t);
      if (flag){
        cout << "Y\n";
      } else {
        cout << "N\n";
      }
    } else if (s == "D"){
      cin >> t;
      tree.root = tree.del(tree.root, t);
      if (tree.root)
        cout << tree.get_height(tree.root->right) - tree.get_height(tree.root->left) << "\n";
      else
        cout << 0 << "\n";
    }
  }
  cout << sizeof(tree) << "\n";

}
