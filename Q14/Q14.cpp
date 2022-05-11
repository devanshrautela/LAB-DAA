#include <iostream>
#include <algorithm>
using namespace std;
void merge(int *arr,int l,int e,int mid)
{
    int i=0,j=0,k=l;
    int n1=mid-l+1;
    int n2=e-mid;
    int L[n1];
    int R[n2];
    for(int i=0;i<n1;i++)
    {
        L[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        R[i]=arr[mid+1+i];
    }
    while(i<n1&&j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
          arr[k]=R[j];
            j++;   
        }
        k++;
    }
    while(i<n1)
    {
          arr[k]=L[i];
            i++;
        k++;
    }
    while(j<n2)
    {
          arr[k]=R[j];
            j++;
        k++;
    }
}
void mergesort(int *arr,int l,int e)
{
    if(l<e)
    {
        int mid=l+(e-l)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,e);
        merge(arr,l,e,mid);
    }
}
int main(){
 cout<<"DevanshRautela_C_20_2018314"<<endl;
int t;
 cout<<"enter no. of test"<<endl;
 cin>>t;
 while(t!=0)
 {
 int n;
 cout<<"enter the size of array"<<endl;
 cin>>n;
 int arr[n];
 int j;
 cout<<"enter the element of array"<<endl;
 for(int i=0;i<n;i++)
 {
     cin>>arr[i];
 }
 int key;
 cout<<"enter key"<<endl;
 cin>>key;
  mergesort(arr,0,n-1);
  int l=0,r=n-1,f=0;
  while(l<r)
  {
      if(arr[l]+arr[r]==key)
      {
          cout<<arr[l]<<" "<<arr[r]<<endl;
          f=1;
          l++,r--;
      }
      else if(arr[l]+arr[r]<key)
        l++;
      else
        r--;
  }
  if(f==0)
    cout<<"no such pairs"<<endl;
  t--;
 }
}
