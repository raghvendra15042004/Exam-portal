#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<sstream>
using namespace std;

vector<int> extractnum(string& str)
{
  vector<int> numbers;
  stringstream ss(str);
  string temp;
  while(ss>>temp)
  {
    size_t i=0;
    while(i<temp.size())
    {
      if(isdigit(temp[i]) || (temp[i]=='-' && i+1<temp.size() && isdigit(temp[i+1]))){
        int num;
        size_t idx;
        num=stoi(temp.substr(i),&idx);
        numbers.push_back(num);
        i+=idx;
      }
      else{
        i++;
      }
    }
  }
  return numbers;
}

int main(){
    string s1,s2;
  int r;
  cin>>s1;
  cin>>s2;
  cin>>r;
  int ct=0;
  vector<int> num1=extractnum(s1);
  vector<int> num2=extractnum(s2);
  
  int a1=num1[0],b1=num1[1],c1=num1[2],d1=num1[3],r1=num1[4],a2=num2[0],b2=num2[1],c2=num2[2],d2=num2[3],r2=num2[4];
  set<int> uniqueRes;
  
  for(int x=0;x<r;++x)
  {
    for(int y=0;y<r;++y)
    {
      for(int z=0;z<r;++z)
      {
        for(int w=0;w<r;++w)
        {
          int lhs1=a1*x+b1*y+c1*z+d1*w;
          int lhs2=a2*x+b2*y+c2*z+d2*w;
          
          if(lhs1==lhs2 && lhs1<=r1 && lhs2<=r2)
            ct++;
          }
        }
      }
    }
  
	cout<<  ct;
  
  return 0;
}