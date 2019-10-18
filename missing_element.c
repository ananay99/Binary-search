#include<stdio.h>
#include<stdlib.h>
int * take_input(int *size)
{
    printf("Enter number of elements\n");
    int n;
    scanf("%d",&n);
    *size=n;
    int * arr=(int*)calloc(n,sizeof(int));
    printf("Enter elements in sorted order\n");

    for(int x=0;x<n;x++)
        scanf("%d",&arr[x]);

    return arr;
}
void missing_element(int *arr,int size)
{
    int low=0;
    int high=size-1;
    int i=-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]!=mid+1)
        {
            i=mid;
            high=mid-1;
        }
        else if(arr[mid]==mid+1)
        {
            low=mid+1;
        }
    }
    if(i>=0)
     printf("%d\n",i+1);
}
int main()
{
    int size;
    int * arr=take_input(&size);
    missing_element(arr,size);
    return 0;
}
