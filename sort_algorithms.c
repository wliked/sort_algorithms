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
    for (int i=0; i<len-1; ++i)
    {
        for (int j=0; j<len-i-1; ++j)
        {
            if a[j] > a[j+1]
                swap(&a[j], &a[j+1]);
        }
    }
}


//partition for quick sort
int partition(int a[], int low, int high)
{
    while (low < high)
    {
        while (low < high && a[low] <= a[high])
        {
            --high;
        }
        swap(&a[low],&a[high]);
        while (low < high && a[low] <= a[high])
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
    if (low < high)
    {
        int partition_pos = partition(a, low, high);
        quick_sort(a, low， partition_pos-1);
        quick_sort(a, partition_pos+1,high);
    }

}


//mergr operation for merge sort
//@para int src[]:  source integer array which must be an order array from small to large
//@para int dst[]:  ouput of the sorted array
//@para int begin:  begin index of the first part of src[] : src[begin ... mid]
//@para int mid:    end index of the first part of src[] : src[begin... mid]
//@para int end  :  end index of the seconde part of src[]: src[mid+1 ... end]
void merge(int src[], int dst[], int begin, int mid, int end)
{
    for (int i=begin, int j = mid+1, int k = begin; i<=mid && j <=end; ++k)
    {
        if (src[i] <= src[j])
            dst[k]=src[i++];
        else
            det[k]=src[j++];
    }
    while (i <=mid)
        dst[k++] = src[i++];
    while (j <=end)
        dst[k++] = src[j++];
}

//merge sort
//@para int src[]:  source integer array
//@para int dst[]:  ouput of the sorted array
//@para int begin:  begin index of src[] from where to start the merge sort
//@para int end  :  end index of src[] end at where to stop the merge sort
void merge_sort(int src[], int dst[], int begin, int end)
{
    if (begin < end)
    {
        int mid =(begin+end)/2;
        merge_sort(src,dst,begin,mid);
        merge_sort(src,dst,mid+1,end);
        merge(src,dst,begin,mid,end);
    }
}