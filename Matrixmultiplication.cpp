#include<iostream> 
using namespace std;

void Mat(int d[],int n);

int main()
{
int n;
cout<<"Enter the number of matrices\n"; cin>>n;
int a[n][2]; int d[n+1];

cout<<"Enter the size of the matrices in order\n";

for(int i=0;i<n;i++) {
cout<<"Matrix "<<i+1<<endl; cout<<"Row: ";
cin>>a[i][0]; cout<<"Column: "; cin>>a[i][1];
}

for(int i=0;i<=n;i++){
if(i!=n) d[i]=a[i][0]; else
d[i]=a[i-1][1];
}

Mat(d,n); 
return 0;
}

void Mat(int d[],int n){
int a[n][n],b[n],min,count=0; bool var[n];
string eq="(";

for(int i=0;i<n;i++)
{
var[i]=false; 

for(int j=0;j<n-i;j++)
{
a[j][j+i]=9999; 
for(int k=j;k<j+i;k++)
{
min=a[j][k]+a[k+1][j+i]+(d[j]*d[k+1]*d[j+i+1]); 
if(min<a[j][j+i]) 
{
a[j][j+i]=min; if(j==0) b[j+i]=k;
}
}

if(i==0) a[j][j+i]=0;
}
}

for(int i=n-1;i>0;i--) {
var[b[i]+1]=true;
}

for(int i=1;i<n;i++){
if(var[i])
{
eq+="a"+to_string(i)+")"; count++;
}
else eq+="a"+to_string(i);
}

for(int i=0;i<count;i++){
eq="("+eq;
}

eq+="a"+to_string(n)+")";
cout<<endl<<"Minimum Multiplications: "<<a[0][n-1]<<endl; cout<<"The equation with minimum multiplications is: "<<eq<<endl;
}
