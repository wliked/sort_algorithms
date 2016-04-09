//*************************************************************
//*
//* Copyright (c) 2016 : wang liang
//* License : Distributed under the GNU General Public License
//* created on : 4/07/2016,  by wang liang (wliked@outlook.com)
//* 
//*************************************************************

//swap value of two integers
void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;	
}


//bubble sort
//@param a  :integer array to be sorted
//@param len:length of integer array
void bubble_sort(int a[], int len)
{
	for(int i=0; i<len-1; ++i) 
	{
		for(int j=0; j<len-i-1; ++j)
		{
			if a[j] > a[j+1]
               swap(&a[j], &a[j+1]);			
		}
	}
}


//partition for quick sort
int partition(int a[], int low, int high)
{
	while(low < high)
	{
		while(low < high && a[low] <= a[high])
		{
			--high;
		}
		swap(&a[low],&a[high]);
		while(low < high && a[low] <= a[high])
		{
			++low;
		}
	    swap(&a[low], &a[high]);
	}
	return low;
}

//quick sort
//@param int a[]    : integer array to be sorted
//@param low  : lower index of integer array
//@param high : higher index of integer array
void quick_sort(int a[], int low, int high)
{
	if(low < high)
	{
		int partition_pos = partition(a, low, high);
		quick_sort(a, low， partition_pos-1);
		quick_sort(a, partition_pos+1,high);
	}	
	
}