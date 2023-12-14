////
//// Created by Святослав on 11.12.2023.
////
//
//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//
//struct node {
//  string val;
//  node* left = nullptr;
//  node* right = nullptr;
//  int cnt = 0;
//  int r_height = 0, l_height = 0;
//  int bal = 0;
//  int unique_symbols;
//
//  node(string x, int un_symb): val(x), unique_symbols(un_symb){};
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
//  node* insert(node* x, string k, int uniq){
//    if (!x){
//      return new node(k, uniq);
//    }
//    if (x->val == k){
//      x->cnt++;
//      return x;
//    }
//    if (k < x->val){
//      x->l_height++;
//      x->bal++;
//      x->left = insert(x->left, k, uniq);
//
//    }
//    else {
//      x->r_height++;
//      x->bal--;
//      x->right = insert(x->right, k, uniq);
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
//
//
//};
//
//
//int uniqueLetterString(string& s) {
//  int n = s.size();
//  int ans = 0;
//  vector<int> cnt(260, 0);
//
//  for (int i = 0; i < n; i++){
//    char ch = s[i];
//    cnt[int(ch) - 40]++;
//    if (cnt[int(ch) - 40] == 1){
//      ans++;
//    }
//
//  }
//  return ans;
//}
//
//int main(){
////  ios::sync_with_stdio(0);
////  cin.tie(0);
//  bst tree;
//  int n;
//  cin >> n;
//  string s;
//  for (int j = 0; j < n; j++){
//    cin >> s;
//    int uniq = uniqueLetterString(s);
//    tree.root = tree.insert(tree.root, s, uniq);
//  }
//
//  queue<node*>TEAM_SPIRIT;
//  node* tmp = nullptr;
//  TEAM_SPIRIT.push(tree.root);
//  int MLG = 0;
//  while (!TEAM_SPIRIT.empty()) {
//    tmp = TEAM_SPIRIT.front();
//    TEAM_SPIRIT.pop();
//    if (tmp && tmp->left)
//      TEAM_SPIRIT.push(tmp->left);
//    if (tmp && tmp->right)
//      TEAM_SPIRIT.push(tmp->right);
//    MLG += tmp->cnt * tmp->unique_symbols;
//  }
////  cout << int('a') - 97 << endl;
//  cout << MLG;
//}
