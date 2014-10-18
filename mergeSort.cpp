#include<stdio.h>
#include<stdlib.h>
void Merge(int *arrayOrdenar, int *leftSubArray, int leftCount, int *rightSubArray, int rightCount){
	int i,j,k;
	i=0;j=0;k=0;
	while (i<leftCount && j < rightCount ){
		if (leftSubArray[i]<rightSubArray[j])
		{	arrayOrdenar[k]=leftSubArray[i];
			i++;
		}
		else {arrayOrdenar[k]=rightSubArray[j];
		j++;}
		k++;
	}
	while (i<leftCount) arrayOrdenar[k++]=leftSubArray[i++];
	while (j<rightCount) arrayOrdenar[k++]=rightSubArray[j++];
}
void MergeSort(int *arrayOrdenar, int size){
	int middle, *leftSubArray,*rightSubArray;
	if (size<2) return ;
	middle = size/2;
	leftSubArray= new int[middle];
	rightSubArray = new int[size-middle];
	for (int i=0; i<middle;i++)
		leftSubArray[i]=arrayOrdenar[i];
	for (int i=middle; i<size;i++)
		rightSubArray[i-middle]=arrayOrdenar[i];
	MergeSort(leftSubArray,middle);
	MergeSort(rightSubArray,size-middle);
	Merge(arrayOrdenar,leftSubArray,middle,rightSubArray,size-middle);

}
/*
int main(){
	int ArrayaOrdenar[]={5,15,24,7};
	int i,  numberOfElements;
	
	numberOfElements = sizeof(ArrayaOrdenar)/sizeof(ArrayaOrdenar[0]);
	MergeSort(ArrayaOrdenar,numberOfElements);
	for (i=0;i<numberOfElements;i++) 
	{	printf ("%d",ArrayaOrdenar[i]);	
		printf(" ");
	}
	system("pause");
}
*/