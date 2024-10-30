#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++)   
    {
        printf("Enter element %d: ",i);
        scanf("%d",&arr[i]);
    }
    int min;
    int s_min;
    int x;
     if (arr[0]<arr[1])
        {
            min=arr[0];
            s_min=arr[1];
        }else{
            min=arr[1];
            s_min=arr[0];
        }
        
    for (int i=2;i<n;i++)
    {
        if(arr[i]<min)
        {
            s_min=min;
            min=arr[i];
        
        }else if(arr[i]<s_min && arr[i]>min)
        {
            s_min=arr[i];
        }
      
    }
            printf("second smallest element: %d\n",s_min);
   

    

    return 0;
}