#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
using namespace std;
void insert_heap(vector<int> &v, int x)
{
    v.push_back(x);
    int cur_ind = v.size() - 1;
    while (cur_ind != 0)
    {
        int par_ind = (cur_ind - 1) / 2;
        if (v[par_ind] < v[cur_ind])
        {
            swap(v[par_ind], v[cur_ind]);
        }
        else
            break;
    }
}
void delete_heap(vector<int> &v)
{
    v[0] = v[v.size() - 1];
    v.pop_back();
    int cur_heap = 0;
    while (true)
    {
        int left_heap = (cur_heap * 2) + 1;
        int right_heap = (cur_heap * 2) + 2;
        if (left_heap < v.size() && right_heap < v.size())
        {
            if (v[left_heap] >= v[right_heap])
            {
                if (v[left_heap] > v[cur_heap])
                {
                    swap(v[left_heap], v[cur_heap]);
                    cur_heap = left_heap;
                }
                else
                    break;
              
            }
            else  if (v[left_heap] <= v[right_heap])
            {
                if (v[right_heap] > v[cur_heap])
                {
                    swap(v[right_heap], v[cur_heap]);
                    cur_heap = right_heap;
                }
                else
                    break;
              
            }
            else break;
        }
        else if(right_heap<v.size()){
            if (v[right_heap] > v[cur_heap])
                {
                    swap(v[right_heap], v[cur_heap]);
                    cur_heap = right_heap;
                }
                else
                    break;
        }
        else if(v[left_heap]<v.size()){
            if (v[left_heap] > v[cur_heap])
                {
                    swap(v[left_heap], v[cur_heap]);
                    cur_heap = left_heap;
                }
                else
                    break;
        }
        else break;
    }
}

    int32_t main()
    {
        int n;
        cin >> n;
        vector<int> v;
        while (n--)
        {
            int x;
            cin >> x;

            insert_heap(v, x);
        }
        for (auto k : v)
            cout << k << " ";
        cout << endl;
        delete_heap(v);
        for (auto k : v)
            cout << k << " ";
        cout << endl;
        return 0;
    }
