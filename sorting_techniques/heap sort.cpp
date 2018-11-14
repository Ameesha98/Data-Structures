#include<iostream>
using namespace std;
int tree[100],n=0;
void insert(int item)
{
    int par;
    n=n+1;
    int ptr;
    ptr=n;
    while(ptr>1)
    {
        par=ptr/2;
        if(item<=tree[par])
        {
            tree[ptr]=item;
            return;
        }
        tree[ptr]=tree[par];
        ptr=par;
    }
    tree[1]=item;
}
void deletes()
{
    int item,last,ptr,left,right;
    item=tree[1];
    last=tree[n];
    n=n-1;
    ptr=1;
    left=2;
    right=3;
    if(n==0)
    {
        cout<<item;
        return;
    }
    if(n==1)
    {
        goto aa;
    }
    while(right<=n)
    {
            if(last>=tree[left]&&last>=tree[right])
            {
                tree[ptr]=last;
                return;
            }
            if(tree[right]<=tree[left])
            {
                tree[ptr]=tree[left];
                ptr=left;
            }
            else
            {
                tree[ptr]=tree[right];
                ptr=right;
            }
            left=2*ptr;
            right=2*ptr+1;
    }
    if(left==n&&last<tree[left])
    {
        tree[ptr]=tree[left];
        ptr=left;
    }
    aa:
    tree[ptr]=last;
    cout<<item<<" ";
}
int main()
{
    int  num,item,i;
    cout<<"Enter num";
    cin>>num;
    for(i=0;i<num;i++)
    {
        cin>>item;
        insert(item);
    }
      for(i=0;i<num;i++)
    {
       deletes();
    }
    /*for(i=1;i<=num;i++)
    {
    cout<<tree[i]<<" ";
    }*/
}
