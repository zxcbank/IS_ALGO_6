//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//struct node {
//  int val;
//  int left, right;
//  int lt=0, rt=0;
//
//  node(int x, int ln, int rn) : val(x), left(ln), right(rn) {};
//};
//
//int height(vector<node*>& t, int i)
//{
//  if (i == 0) {
//    return 0;
//  }
//  if (t[i]->lt == 0 && t[i]->rt == 0){
//    t[i]->rt = height(t, t[i]->right);
//    t[i]->lt = height(t, t[i]->left);
//  }
//
//  return 1 + max(t[i]->rt, t[i]->lt);
//}
//
//int main() {
//  int n;
//  int c, t, k;
//  cin >> n;
//  vector <node*> tree(n+1);
//  tree[0] = nullptr;
//  for (int i = 1; i < n+1; i++){
//    cin >> c >> t >> k;
//    tree[i] = new node(c, t, k);
//  }
//  for (int i = 1; i <= n; i++) {
//    int l = height(tree, tree[i]->left);
//    int r = height(tree, tree[i]->right);
//    cout << r - l << "\n";
//  }
//}
