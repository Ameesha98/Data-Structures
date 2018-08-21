#include<iostream>
#include<stdlib.h>
using namespace std;
void insert(int arr[],int *n)
{
    int item,pos,i;
    cout<<"Enter the element you want to insert\n";
    cin>>item;
    cout<<"Enter the position where you want to insert item\n";
    cin>>pos;
    if(pos>*n)
    cout<<"Enter valid position\n";
    else
    {
    for(i=*n-1;i>=pos-1;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[i+1]=item;
    *n=*n+1;
    }
}
void display(int arr[],int n)
{
    int i;
    cout<<"Array: ";
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
        cout<<"\n";
}
void bubblesort(int arr[],int n)
{
    int i,j,flag=0,temp;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}
void selectionsort(int arr[],int n)
{
    int i,j,flag=0,temp;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}
void insertionsort(int arr[],int n)
{
    int i, j, temp;
    for(i=1;i<n;i++)
    {
        temp = arr[i];
        j = i-1;
        while(j>=0&&arr[j]>temp)
            {
                arr[j+1] = arr[j];
                j--;
            }
        arr[j+1] = temp;
    }
}
int main()
{
        int n,item,i,arr[100];
        int ch;
        char c;
        cout<<"Enter number of elements you want to insert in array\n";
        cin>>n;
        cout<<"Enter elements\n";
        for(i=0;i<n;i++)
            cin>>arr[i];
        system("CLS");
        while(1)
        {
            cout<<"Press 1 to insert item at any position\n";
            cout<<"Press 2 sort array\n";
            cout<<"Press 3 to display array\n";
            cout<<"Press E to exit\n";
            cout<<"Enter your choice: ";
            cin>>ch;
            switch(ch)
            {
            case 1:
                insert(arr,&n);
                display(arr,n);
                cout<<"Press C key to continue: ";
                cin>>c;
                break;
            case 2:
                 cout<<"1. Bubble sort\n";
                cout<<"2. Selection sort\n";
                cout<<"3. Insertion sort\n";
                cout<<"Enter choice\n";
                cin>>ch;
                if(ch==1)
                    bubblesort(arr,n);
                else if(ch==2)
                    selectionsort(arr,n);
                else if(ch==3)
                    insertionsort(arr,n);
                display(arr,n);
                cout<<"Press C key to continue: ";
                cin>>c;
                break;
            case 3:
                display(arr,n);
                cout<<"Press C key to continue: ";
                cin>>c;
                break;
            default:
                display(arr,n);
                exit(0);
            }
            system("CLS");
            }
}
