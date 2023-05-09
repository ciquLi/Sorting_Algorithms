
//  mergesort
//
//  Created by ciqu on 2018/12/20.
//  Copyright © 2018年 ciqu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
/*
#########################
algorithm steps:
1.divide the array
2.merge the arrays
#########################
 */
void print_array(int array[], int length, char *print_string)
{
    printf("%s\n",print_string);
    for (int i=0; i<length; i++)
    {
        printf("%d\t",array[i]);
    }
    printf("\n");
}
void mergearray(int array[], int begin, int mid, int end, int temp[])
{
    int i = begin, j = mid+1;
    int m = mid, n = end;
    int k = 0;
    while (i<=m && j<=n)    //
    {
        if (array[i]<=array[j])
        {
            temp[k++] = array[i++];
        }
        else
        {
            temp[k++] = array[j++];
        }
    }
    while (i<=m)
    {
        temp[k++] = array[i++];
    }
    while (j<=n)
    {
        temp[k++] = array[j++];
    }
    for (int l = 0; l<k; l++)    //substitute part of array with sorted temp
    {
        array[begin+l] = temp[l];
    }
}

void MergeSort(int array[], int begin, int end, int temp[])
{
    if (begin < end)
    {
        int mid = (begin+end)/2;
        MergeSort(array, begin, mid, temp);
        MergeSort(array, mid+1, end, temp);
        mergearray(array, begin, mid, end, temp);
    }
}



int main(int argc, const char * argv[]) {
    int array[] = {2,5,6,0,88,-111,33,22,33,11,22};
    int array_byte = sizeof(array);
    int len = array_byte/sizeof(int);
    print_array(array, len, "array before sort");    //Print array unsorted.
    
  //  int *temp = (int*)calloc(len,sizeof(int));    //allocate memory for temp
    int *temp = (int*)malloc(array_byte);
    MergeSort(array, 0, len-1, temp);
    print_array(array, len, "array after merge sort");    //Print array after merge sort.
    
    free(temp);  //free memory

    return 0;
}
