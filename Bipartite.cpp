#include<iostream>
using namespace std;

#define M 6
#define N 6

bool Check(int a[][N],int m[],bool c[], int u) 
{
  for(int i=0;i<N;i++)
  {
    if(a[u][i] && !c[i])
    {
      c[i]=true;
      if(m[i]<0 || Check(a,m,c,m[i])) 
      {
        m[i]=u;
        return true;
      }
    }
  }
  return false;
}

int Bipartite(int a[][N])
{
    int match[N],result=0;
    bool check[N]; 

    for(int i=0;i<N;i++)
    {
      match[i]=-1;
      check[i]=false;
    }

    for(int i=0;i<M;i++) 
    {
      if(Check(a,match,check,i))
        result++;
    }

    return result;
}

int main()
{
    int a[M][N];
    cout<<"Enter the adjacency matrix\n";

    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>a[i][j];
        }
    }

    cout<<Bipartite(a);
    return 0;
}
