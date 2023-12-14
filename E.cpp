//// 6Е
//// 6Е
//// 6Е
//// 6Е
//// 6Е
//// 6Е
//// 6Е
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//
//struct node {
//  string val;
//  node* left = nullptr;
//  node* right = nullptr;
//  int cnt = 1;
//  int r_height = 0, l_height = 0;
//  int bal = 0;
//
//  node(string x): val(x){};
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
//    p->left =q;
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
//  node* insert(node* x, string k){
//    if (!x){
//      return new node(k);
//    }
//    if (x->val == k){
//      x->cnt++;
//      return x;
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
//  node* find (node* t, string s){
//    if (s == t->val){
//      return t;
//    } else if (s < t->val) {
//      return find(t->left, s);
//    } else {
//      return find(t->right, s);
//    }
//  }
//};
//
//int main(){
////  ios::sync_with_stdio(0);
////  cin.tie(0);
//  bst tree;
//  int n;
//  cin >> n;
//  vector <vector <string>> data(3);
//  for (int i = 0; i < 3; i++){
//    data[i] = vector<string>(n);
//    for (int j = 0; j < n; j++){
//      cin >> data[i][j];
//      tree.root = tree.insert(tree.root, data[i][j]);
//    }
//  }
//
//  for (int i = 0; i < 3; i++){
//    int ans = 0;
//    for (int j = 0; j < n; j++){
//      int count = tree.find(tree.root, data[i][j])->cnt;
//      if (count == 2)
//        ans++;
//      else if (count == 1)
//        ans+=3;
//    }
//    cout << ans << " ";
//  }
//}
