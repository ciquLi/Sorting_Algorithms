
//  QuickSort
//
//  Created by ciqu on 2018/12/19.
//  Copyright © 2018年 ciqu. All rights reserved.
//

#include <stdio.h>

//print array
void print_array(int list[],int length,char *print_string){
    printf("%s", print_string);
    for (int i = 0; i < length ; i++){
        printf("%d\t",list[i]);
    }
    printf("\n");
}
//exchange two number in array
void swap(int array[], int a, int b)
{
    int temp;
    temp = array[a];
    array[a] = array[b];
    array[b] = temp;
    return ;
}


void quicksort(int array[],int begin,int end)
{
    int i,j;
    if(begin<end)
    {
        i = begin+1;
        j = end;
        while (i<j)
        {
            if (array[i]>array[begin])
            {
                swap(array, i, j);
                j--;
            }
            else
            {
                i++;
            }
        }
        if (array[i]>=array[begin])    //identify the location of number array[begin]
        {
            i--;
        }
        swap(array, begin, i);
     
        quicksort(array, begin, i);
        quicksort(array, j, end);
    }
    
}

int main(int argc, const char * argv[]) {

    int array[] = {-1,100,25,16,2,23,33,95,34,0};
    int arrlen = 10;
    
    print_array(array, arrlen,"array unsorted:\n");
    quicksort(array, 0, arrlen-1);  // quicksort
    print_array(array, arrlen,"array after quicksort:\n");
    
    return 0;
    

}
