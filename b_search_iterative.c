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
void b_search(int * arr,int size)
{
    printf("Enter element to search\n");
    int srch;
    scanf("%d",&srch);

    int low=0,high=size-1;
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

    printf("isNotPresent");
}
int main()
{
    int size=0;
    int *arr=take_input(&size);
    b_search(arr,size);
    return 0;
}
