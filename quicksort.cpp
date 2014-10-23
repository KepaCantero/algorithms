#include<stdio.h>
#include<stdlib.h>

void swap (int * a, int index1, int index2)
{
	int temp = a[index1];
	a[index1]=a[index2];
	a[index2]=temp;

}
int Partitions(int * ArrayOrdenar, int start, int end){
	int pivot = ArrayOrdenar[end];
	int rightIndex=start;
	for (int i=start;i<end;i++){
		if (ArrayOrdenar[i]<=pivot){
			swap(ArrayOrdenar,rightIndex,i);	
			rightIndex++;
		}
	}
	swap(ArrayOrdenar,rightIndex,end);	
	return rightIndex;
}



void Quicksort(int * ArrayOrdenar, int start, int end){
	int pivoteIndex=0;
	if (start<end){
		pivoteIndex = Partitions(ArrayOrdenar,start,end);
		Quicksort(ArrayOrdenar,start, pivoteIndex-1);
		Quicksort(ArrayOrdenar,pivoteIndex+1,end);	
	}
}

int main(){
	int ArrayaOrdenar[]={5,15,24,7};
	int i,  numberOfElements;
	
	numberOfElements = sizeof(ArrayaOrdenar)/sizeof(ArrayaOrdenar[0]);
	Quicksort(ArrayaOrdenar,0,numberOfElements-1);
	for (i=0;i<numberOfElements;i++) 
	{	printf ("%d",ArrayaOrdenar[i]);	
		printf(" ");
	}
	system("pause");
}
