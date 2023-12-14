////
//// Created by Святослав on 10.12.2023.
////
//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//
//struct node {
//  int val;
//  int r_index = 0, l_index = 0;
//  node* left = nullptr;
//  node* right = nullptr;
//  int index;
//  int r_height = 0, l_height = 0;
//  int bal = 0;
//
//  node(int x, int ln, int rn, int ix): val(x), r_index(rn), l_index(ln), index(ix){};
//  node(int x, int ln, int rn): val(x), r_index(rn), l_index(ln){};
//  node(int x): val(x){};
//
//
//};
//
//
//struct bst{
//  node* root = nullptr;
//
//  int height(node* t) {
//    if (t == nullptr) {
//      return 0;
//    }
//    if (t->l_height == 0 && t->r_height == 0){
//      t->r_height = height(t->right);
//      t->l_height = height(t->left);
//      t->bal = t->l_height - t->r_height;
//    }
//
//    return 1 + max(t->r_height, t->l_height);
//  }
//  node* right_rotate(node* q){
//    node* p = q->left;
//    q->left = p->right;
//    p->right = q;
//
//    q->r_height = height(q->right);
//    q->l_height = height(q->left);
//
//    p->r_height = height(p->right);
//    p->l_height = height(p->left);
//    return p;
//  }
//
//  node* left_rotate(node* q) {
//    node* p = q->right;
//    q->right = p->left;
//    p->left = q;
//    if (q) {
//      q->r_height = height(q->right);
//      q->l_height = height(q->left);
//    }
//    if (p) {
//      p->r_height = height(p->right);
//      p->l_height = height(p->left);
//    }
//    return p;
//  }
//
//  node* insert(node* x, int k){
//    if (!x){
//      return new node(k);
//    }
//    if (k < x->val){
//      x->l_height++;
//      x->bal++;
//      x->left = insert(x->left, k);
//
//    }
//    else {
//      x->r_height++;
//      x->bal--;
//      x->right = insert(x->right, k);
//    }
//    return balance(x);
//  }
//
//  node* balance(node* x){
//    x->l_height = height(x->left);
//    x->r_height = height(x->right);
//    x->bal = x->l_height - x->r_height;
//    if (x->bal == 2){
//      if (x->left->bal < 0)
//        x->left = left_rotate(x->left);
//      return right_rotate(x);
//    }
//    if (x->bal == -2){
//      if (x->right->bal > 0)
//        x->right = right_rotate(x->right);
//      return left_rotate(x);
//    }
//    x->l_height = height(x->left);
//    x->r_height = height(x->right);
//    x->bal = x->l_height - x->r_height;
//    return x;
//  }
//};
//
//int main(){
//  int n;
//  int t, m, k;
//  bst tree;
//
//  cin >> n;
//  vector<node*> array;
//
//  array.push_back(nullptr);
//  for (int i = 0; i < n; i++){
//    cin >> t >> m >> k;
//    if (i == 0){
//      tree.root = new node(t, m, k, 1);
//    }
//    array.push_back(new node(t, m , k, i+1));
//  }
//  queue<node*> TEAM_SPIRIT;
//
//  TEAM_SPIRIT.push(tree.root);
//  node* tmp = nullptr;
//  while (!TEAM_SPIRIT.empty()){
//    tmp = TEAM_SPIRIT.front();
//    TEAM_SPIRIT.pop();
//    if (tmp && tmp->l_index != 0){
//      tmp->left = array[tmp->l_index];
//      TEAM_SPIRIT.push(tmp->left);
//    }
//    if (tmp && tmp->r_index != 0){
//      tmp->right = array[tmp->r_index];
//      TEAM_SPIRIT.push(tmp->right);
//    }
//  }
//  tree.height(tree.root);
//  cin >> t;
//  n++;
//  tree.root = tree.insert(tree.root, t);
//
//
//
//  TEAM_SPIRIT.push(tree.root);
//  int MLG = 2;
//  cout << n << "\n";
//  while (!TEAM_SPIRIT.empty()){
//    tmp = TEAM_SPIRIT.front();
//    TEAM_SPIRIT.pop();
//    if (tmp && tmp->left)
//      TEAM_SPIRIT.push(tmp->left);
//    if(tmp && tmp->right)
//      TEAM_SPIRIT.push(tmp->right);
//    if (tmp)
//      cout << tmp->val << " " << ((tmp->left == nullptr) ? 0 : MLG++) << " " << ((tmp->right == nullptr) ? 0 : MLG++) << "\n";
//  }
//}