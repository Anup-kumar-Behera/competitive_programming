#include<stdio.h>
int main()
{
    int n;
    printf("Enter size of the array: ");
    scanf("%d",&n);
    int a[n];
    int i;
    printf("Enter array elements: \n");
    for(i = 0;i < n;i++)
        scanf("%d",&a[i]);
    int j = n,temp;
    i = 0;
    printf("Original array is:\n");
    for(i = 0;i < n;i++)
        printf("%d ",a[i]);
    while(i < j)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
    printf("\nReversed array is: \n");
    for(i = 0;i < n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}