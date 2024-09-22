#include<bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
using namespace std;

//custom compare class;
class student{
    public:
    string name;
    int roll;
    int marks;
    student(string name,int roll,int marks){
        this->name=name;
        this->roll=roll;
        this->marks=marks;
    }

};
//custom compare operator
class compare{
      public:
      bool operator()(student a,student b){        //operator()  is a oop function 
          if(a.marks<b.marks)return true;
          else if(a.marks>b.marks) return false ;
          else {
            if(a.roll>b.roll)return false;
            else return true;
          }

      }
};


int32_t main () 
{   
    int n;
    cin>>n;
    //priority_queue<int,vector<int>,greater<int>>q;
    priority_queue<student,vector<student>,compare>q;
    while(n--){
        string s;int k;int l;
        cin>>s>>k>>l;
        student x(s,k,l);
       q.push(x);

    }
    while (!q.empty()){
        cout<<q.top().name<<" "<<q.top().roll<<" "<<q.top().marks<<endl;
        q.pop();
    }

    return 0;
}
