#include <SDL.h>
extern int arr[];
extern const int arrSize;
extern SDL_Renderer* renderer;
extern bool complete;
void visualize(int, int, int);

void selectionSort() {
    for (int i = 0; i < arrSize - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < arrSize; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
                visualize(i, minIdx);
            }
            SDL_Delay(1);
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

void inplaceHeapSort(int* input, int n)
{
    for(int i=1; i<n; i++)
    {
       int childIndex=i;
       int parentIndex=(childIndex-1)/2;

       while(childIndex>0)
       {
           if(input[childIndex]>input[parentIndex])
           {
               int temp=input[parentIndex];
               input[parentIndex]=input[childIndex];
               input[childIndex]=temp;

           }
           else
           {
               break;
           }

           visualize(parentIndex, childIndex);
           SDL_Delay(40);

           childIndex=parentIndex;
           parentIndex=(childIndex-1)/2;
       }
    }

    for(int heapLast=n-1; heapLast>=0 ; heapLast--)
    {
        int temp=input[0];
        input[0]=input[heapLast];
        input[heapLast]=temp;

        int parentIndex=0;
        int leftChildIndex=2*parentIndex + 1;
        int rightChildIndex=2*parentIndex + 2;

        while(leftChildIndex<heapLast)
        {
            int maxIndex=parentIndex;

            if(input[leftChildIndex]>input[maxIndex])
            {
                maxIndex=leftChildIndex;
            }
            if(rightChildIndex<heapLast && input[rightChildIndex]>input[maxIndex])
            {
                maxIndex=rightChildIndex;
            }
            if(maxIndex==parentIndex)
            {
                break;
            }

            int temp=input[parentIndex];
            input[parentIndex]=input[maxIndex];
            input[maxIndex]=temp;

            visualize(maxIndex, parentIndex, heapLast);
            SDL_Delay(40);

            parentIndex=maxIndex;
            leftChildIndex=2*parentIndex + 1;
            rightChildIndex=2*parentIndex + 2;
        }
    }
}

int partition_array(int a[], int si, int ei)
{
    int count_small=0;

    for(int i=(si+1);i<=ei;i++)
    {
        if(a[i]<=a[si])
        {
            count_small++;
        }
    }
    int c=si+count_small;
    int temp=a[c];
    a[c]=a[si];
    a[si]=temp;
    visualize(c, si);

    int i=si, j=ei;

    while(i<c && j>c)
    {
        if(a[i]<= a[c])
        {
            i++;
        }
        else if(a[j]>a[c])
        {
            j--;
        }
        else
        {
            int temp_1=a[j];
            a[j]=a[i];
            a[i]=temp_1;

            visualize(i, j);
            SDL_Delay(70);

            i++;
            j--;
        }
    }
    return c;
}

void quickSort(int a[], int si, int ei)
{
    if(si>=ei)
    {
        return;
    }

    int c=partition_array(a, si, ei);
    quickSort(a, si, c-1);
    quickSort(a, c+1, ei);

}

void merge2SortedArrays(int a[], int si, int ei)
{
    int size_output=(ei-si)+1;
    int* output=new int[size_output];

    int mid=(si+ei)/2;
    int i=si, j=mid+1, k=0;
    while(i<=mid && j<=ei)
    {
        if(a[i]<=a[j])
        {
            output[k]=a[i];
            visualize(i, j);
            i++;
            k++;
        }
        else
        {
            output[k]=a[j];
            visualize(i, j);
            j++;
            k++;
        }

    }
    while(i<=mid)
    {
        output[k]=a[i];
        visualize(-1, i);
        i++;
        k++;
    }
    while(j<=ei)
    {
        output[k]=a[j];
        visualize(-1, j);
        j++;
        k++;
    }
    int x=0;
    for(int l=si; l<=ei; l++)
    {
        a[l]=output[x];
        visualize(l);
        SDL_Delay(15);
        x++;
    }
    delete []output;
}

void mergeSort(int a[], int si, int ei)
{
    if(si>=ei)
    {
        return;
    }
    int mid=(si+ei)/2;

    mergeSort(a, si, mid);
    mergeSort(a, mid+1, ei);

    merge2SortedArrays(a, si, ei);
}

void bubbleSort()
{
    for(int i=0; i<arrSize-1; i++)
    {
        for(int j=0; j<arrSize-1-i; j++)
        {
            if(arr[j+1]<arr[j])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

                visualize(j+1, j, arrSize-i);
            }
            SDL_Delay(1);
        }
    }
}

void insertionSort()
{
    for(int i=1; i<arrSize; i++)
    {
        int j=i-1;
        int temp=arr[i];
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;

            visualize(i, j+1);
            SDL_Delay(5);
        }
        arr[j+1]=temp;
    }
}
