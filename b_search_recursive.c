#include<stdio.h>
#include<stdlib.h>

int * take_input(int * size)
{
    printf("Enter number of elements\n");
    int n;
    scanf("%d",&n);

    int * retarr=(int*)malloc(sizeof(int)*n);

    printf("Enter elements in sorted order\n");
    for(int i=0;i<n;i++)
        scanf("%d",&retarr[i]);

    *size=n;
    return(retarr);
}
int recur_bsearch(int * arr,int low,int high,int srch)
{
    if(low<=high)
    {
        int mid=low+(high-low)/2;
        int ret1=0,ret2=0;
        if(arr[mid]==srch)
        {
            return 1;
        }
        else if(arr[mid]>srch)
        {
            ret1=recur_bsearch(arr,low,mid-1,srch);
        }
        else
        {
            ret2=recur_bsearch(arr,mid+1,high,srch);
        }
        if(ret1||ret2)
        {
            return 1;
        }
    }
    return 0;
}
void b_search(int * arr,int size)
{
    printf("Enter element to search\n");
    int srch;
    scanf("%d",&srch);

    int found=recur_bsearch(arr,0,size-1,srch);

    if(found)
        printf("isPresent\n");
    else
        printf("isNotPresent");
}
int main()
{
    int size=0;
    int *arr=take_input(&size);
    b_search(arr,size);
    return 0;
}
