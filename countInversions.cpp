#include <stdio.h>
#include <stdlib.h>

int merge (int invArray[],int temp[], int left, int mid, int right){

 int i, j, k;
 int inv_count=0;
 i=left;
 j=mid;
 k=left;
 while ((i<= mid - 1) && (j<=right))
 {
	 if (invArray[i]<= invArray[j])
		 temp[k++]=invArray[i++];
	 else
	{	 temp[k++]=invArray[j++];
		inv_count=inv_count + (mid - i);
	}

 }
 while (i <=mid -1)
	 temp[k++]=invArray[i++];
 while (j<=right)
	 temp[k++]=invArray[j++];
 for(i=left;i<=right;i++)
	 invArray[i]=temp[i];
 return inv_count;
}

int mergeSort(int invArray[], int temp[], int left, int right)
{
	int mid, inv_count_right =0,inv_count_left=0,inv_count_merge=0;

	if (right>left){
		mid=(right + left)/2;
	inv_count_right = mergeSort(invArray, temp, left, mid);
	inv_count_left = mergeSort(invArray, temp, mid+1, right);
	inv_count_merge = merge(invArray, temp, left, mid+1, right);

	}
	return inv_count_right + inv_count_left + inv_count_merge;
}

int countInversions(int invArray[],int array_size)
{
	int *temp = new int[array_size];
	return mergeSort(invArray, temp, 0, array_size -1);
}


int main (int arg){

	int invArray[]={7,14,3,45,22};
	int numberOfElements = sizeof(invArray)/sizeof(invArray[0]);
	printf("Number of inversions are %d \n",countInversions(invArray,numberOfElements));
	system("pause");
	return 0;

}