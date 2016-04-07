//*************************************************************
//*
//* Copyright (c) 2016 : wang liang
//* License : Distributed under the GNU General Public License
//* created on : 4/02/2016,  by wang liang (wliked@outlook.com)
//* 
//*************************************************************

//swap value of two integers
void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;	
}


//bubble sor
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