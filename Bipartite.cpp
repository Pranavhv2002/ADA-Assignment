#include<iostream> 
using namespace std;

#define M 5

#define N 5

bool Check(int a[][N],int m[],bool c[], int u); 

int bipartite(int a[][N],int match[])
{
int result=0;
bool check[N]; 
for(int i=0;i<N;i++)
{
match[i]=-1;
}
for(int i=0;i<M;i++) {
for(int j=0;j<N;j++) check[j]=false;

if(Check(a,match,check,i)) result++;
}
return result;
}

bool Check(int a[][N],int m[],bool c[], int u) {
for(int i=0;i<N;i++)
{
if(a[u][i] && !c[i])
{
c[i]=true;
if(m[i]<0 || Check(a,m,c,m[i])) {
m[i]=u; return true;
}
}
}
return false;
}


int main()
{
int a[M][N],match[N]; 
cout<<"Enter the adjacency matrix with rows representing vertices of set A and columns representing vertices of set B\n";

for(int i=0;i<M;i++)
{
cout<<"Row "<<i+1<<endl; for(int j=0;j<N;j++)
{
cin>>a[i][j];
}
}
cout<<endl<<"The maximum number of matching is: "<<bipartite(a,match)<<endl;
cout<<endl<<"Final Matching:"<<endl; for(int i=0;i<N;i++)
{
if(match[i]!=-1)
cout<<match[i]<<" --> "<<i<<endl;
}
return 0;
}
