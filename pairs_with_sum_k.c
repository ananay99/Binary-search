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
void pair_print(int * arr,int size)
{
    printf("Enter sum to find\n");
    int sum;
    scanf("%d",&sum);

    int rpt=-1;
    for(int x=0;x<size;x++)
    {
      if(rpt!=arr[x])
      {
        int low=x+1,high=size-1;
        int srch=sum-arr[x];
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]==srch)
            {
                printf("(%d,%d)\n",arr[x],arr[mid]);
                break;
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
        rpt=arr[x];
      }
    }
}
int main()
{
    int size=0;
    int *arr=take_input(&size);
    pair_print(arr,size);
    return 0;
}
