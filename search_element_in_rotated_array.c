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
int rotation_count(int * arr,int size)
{
    int low=0,high=size-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(mid>low&&arr[mid]<arr[mid-1])
        {
            return mid;
        }
        else if(mid<high&&arr[mid+1]<arr[mid])
        {
            return mid+1;
        }
        else if(arr[high]>arr[mid])
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return 0;
}
void find_element(int * arr,int size,int rot)
{
    int srch;
    scanf("%d",&srch);
    int low,high;
    if(rot==0)
    {
        low=0;
        high=size-1;
    }
    else if(srch>=arr[0])
    {
        low=0;
        high=rot-1;
    }
    else
    {
        low=rot;
        high=size-1;
    }
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==srch)
        {
            printf("isPresent\n");
            return;
        }
        else if(arr[mid]>srch)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    printf("isNotPresent\n");
}
int main()
{
    int size;
    int * arr=take_input(&size);
    int rotation=rotation_count(arr,size);
    find_element(arr,size,rotation);
    return 0;
}
