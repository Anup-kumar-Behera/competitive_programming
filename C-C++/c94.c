#include<stdio.h>
#include<math.h>

void swap(int *a,int *b)
{
    int k = *a;
    *a = *b;
    *b = k;
}
int partition(int *arr,int low,int high)
{
    int pivot = arr[high];
    int i = (low)-1,j;

    for(j = low;j <= high-1;j++)
    {
        if(arr[j] < pivot)
        {
            i ++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[high],&arr[i+1]);

    return (i+1);
}
void quickSort(int *arr,int low,int high)
{
    if(low < high)
    {
        int pi = partition(arr,low,high);

        quickSort(arr,low,pi-1);
        quickSort(arr, pi+1,high);
    }
}
int hackerlandRadioTransmitters(int x_count, int* x, int k) {

    int n = x_count;
    quickSort(x, 0, n);
    int i,j = 1,s = 0;
    int arr[n-1];
    for(i = 0;i < n-1;i++)
    {
        arr[i] = x[i+1]-x[i];
    }
    for(i = 0;i < n-1;i++)
    {
    	printf("%d ",arr[i]);
        s = s + arr[i];
    }
    float p = (s*1.0) / (2*k) ;
    if(p > (int)p)
        return (int)p+1;
    else {
        return (int)p;
    }

}

main()
{
	int arr[] = {7,2,4,6,5,9,12,11};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = hackerlandRadioTransmitters(n, arr, 2);
	
	printf("\n%d\n",k);
}
