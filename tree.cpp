#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
using namespace std;
class node
{
public:
    int val;
    node *left;
    node *right;

    node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void preorder(node *rote)
{
    if (rote == NULL)
        return;

    preorder(rote->left);
    cout << rote->val << " ";
    preorder(rote->right);
}
void printlevelth(node *rote)
{
    if (rote == NULL)
    {
        cout << "tree nai" << endl;
        return;
    }
    queue<node *> x;
    x.push(rote);
    while (!x.empty())
    {
        node *p = x.front();
        x.pop();
        cout << p->val << " ";
        if (p->left)
            x.push(p->left);
        if (p->right)
            x.push(p->right);
    }
}
node *input_tree()
{
    int x;
    cin >> x;
    node *rote;
    if (x == -1)
        rote = NULL;
    else
        rote = new node(x);
    queue<node *> q;
    if (rote)
        q.push(rote);

    // take one value from queue and add two adjacent to it ;if the node is null then skip;
    while (!q.empty())
    {
        node *f = q.front();
        q.pop();
        int ab, ac;
        cin >> ab >> ac;
        node *left;
        node *right;
        if (ab != -1)
            left = new node(ab);
        else
            left = NULL;
        if (ac != -1)
            right = new node(ac);
        else
            right = NULL;
        f->left = left;
        f->right = right;
        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
    return rote;
}
int maxlevel(node *root)
{
    int num = 0;
    if (root)
        num = 1;
    queue<pair<node *, int>> q;
    if (root)
    {
        q.push({root, 1});
    }
    while (!q.empty())
    {
        pair<node *, int> p = q.front();
        q.pop();
        node *x = p.first;
        if (x->left != NULL || x->right != NULL)
            num++;
        if (x->left)
            q.push({x->left, p.second + 1});
        if (x->right)
            q.push({x->right, p.second + 1});
    }
    return num;
}
int count_node(node *root)
{
    if (root == NULL)
        return 0;
    int l = count_node(root->left);
    int m = count_node(root->right);
    return l + m + 1;
}
int count_leaf(node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    else
    {
        int x = count_leaf(root->left);
        int y = count_leaf(root->right);
        return x + y;
    }
}
int maxheight(node *root)
{
    if (root == NULL)
        return 0;
    int x = maxheight(root->left);
    int y = maxheight(root->right);
    return max(x, y) + 1;
}
int32_t main()
{

    node *rote = input_tree();

    printlevelth(rote);
    // cout<<maxheight(rote);
    return 0;
}
