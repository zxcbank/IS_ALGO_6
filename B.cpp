//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//
//struct node {
//  int val;
//  int r_index, l_index;
//  node* left = nullptr;
//  node* right = nullptr;
//  int index;
//  int r_height = 0, l_height = 0;
//  int bal;
//
//  node(int x, int ln, int rn, int ix): val(x), r_index(rn), l_index(ln), index(ix){};
//  node(int x, int ln, int rn): val(x), r_index(rn), l_index(ln){};
//
//
//};
//
//void swap1(node* a, node* b){
//  int tmp_val = a->val;
//  a->val = b->val;
//  b->val = tmp_val;
//}
//
//struct bst{
//  node* root = nullptr;
//    int height(node* t) {
//      if (t == nullptr) {
//        return 0;
//      }
//      if (t->l_height == 0 && t->r_height == 0){
//        t->r_height = height(t->right);
//        t->l_height = height(t->left);
//        t->bal = t->l_height - t->r_height;
//      }
//
//      return 1 + max(t->r_height, t->l_height);
//    }
//    node* right_rotate(node* t){
//      swap1(t, t->left);
//      node* buffer = t->right;
//      t->right = t->left;
//      t->left = t->right->left;
//      t->right->left = t->right->right;
//      t->right->right = buffer;
//
//      t->right->r_height = height(t->right->right);
//      t->right->l_height = height(t->right->left);
//
//      t->r_height = height(t->right);
//      t->l_height = height(t->left);
//
//      return t;
//    }
//
//    node* left_rotate(node* q) {
//      node* p = q->right;
//      q->right = p->left;
//      p->left =q;
//      if (q) {
//        q->r_height = height(q->right);
//        q->l_height = height(q->left);
//      }
//      if (p) {
//        p->r_height = height(p->right);
//        p->l_height = height(p->left);
//      }
//      return p;
//    }
//
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
//    if (tmp->l_index != 0){
//      tmp->left = array[tmp->l_index];
//      TEAM_SPIRIT.push(tmp->left);
//    }
//    if (tmp->r_index != 0){
//      tmp->right = array[tmp->r_index];
//      TEAM_SPIRIT.push(tmp->right);
//    }
//  }
//  tree.height(tree.root);
//
//  if (tree.root->bal == -2 && tree.root->right->l_height <= tree.root->right->r_height){
//    tree.root = tree.left_rotate(tree.root);
//  } else if (tree.root->bal -= 2){
//    tree.root->right = tree.right_rotate(tree.root->right);
//    tree.root = tree.left_rotate(tree.root);
//  }
//
//  TEAM_SPIRIT.push(tree.root);
//  int MLG = 2;
//  cout << n << "\n";
//  while (!TEAM_SPIRIT.empty()){
//    tmp = TEAM_SPIRIT.front();
//    TEAM_SPIRIT.pop();
//    if (tmp->left)
//      TEAM_SPIRIT.push(tmp->left);
//    if(tmp->right)
//      TEAM_SPIRIT.push(tmp->right);
//
//    cout << tmp->val << " " << ((tmp->left == nullptr) ? 0 : MLG++) << " " << ((tmp->right == nullptr) ? 0 : MLG++) << "\n";
//  }
//}