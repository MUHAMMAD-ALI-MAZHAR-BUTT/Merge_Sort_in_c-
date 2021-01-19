#include<iostream>
using namespace std;
int size=10;
void merge(int arr[],int start,int mid,int end)
{
	int i=start; // starting index for left subarray
	int j=mid+1;   // starting index for right subarray
	int k=start;     //starting index for temporary array
	int temp[size]; //temporary array
	while(i<=mid && j<=end)
	{
		if(arr[i]<=arr[j])
		{
		temp[k]=arr[i];  //arr[i] is smaller than arr[j]
		i++;
		k++;
	    }
	   else
	   {
		temp[k]=arr[j]; //arr[j] is smaller than arr[i]
		j++;
		k++;
	   }		
	}

	while(i<=mid)
	{	//copying all elements from left subarray to temp as it is
		temp[k]=arr[i];
		i++;
		k++;
	}
	while(j<=end)
	{	//copying all elements from right subarray to temp as it is
		temp[k]=arr[j];
		j++;
		k++;
	}	
	for(int s=start;s<=end;s++)
	{
		arr[s]=temp[s];
	}
}
void mergeSort(int arr[],int start,int end)
{
	if(start<end)
	{
		int mid=(start+end)/2;
		mergeSort(arr,start,mid);
		mergeSort(arr,mid+1,end);
		merge(arr,start,mid,end);
	}
}
int main()
{
int arr[size]={4,88,1,5,99,2,80,6,0,10};
cout<<"Before merge sort  :\t";
for(int i=0;i<size;i++)
{
	cout<<arr[i]<<"\t";
}
cout<<endl;
mergeSort(arr,0,size-1);
cout<<"After merge sort  :\t";
for(int i=0;i<size;i++)
{
	cout<<arr[i]<<"\t";
}
cout<<endl;


}

