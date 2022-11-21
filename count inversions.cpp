/*
For a given integer array/list 'ARR' of size 'N' containing all the distinct values, find the total number of 'inversions' that may exist.
An inversion is defined for a pair of integers in the array/list when two conditions are met.
A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when
i) 'ARR[i]' > 'ARR[j]'
ii) 'i' < 'j'
where 'i', 'j' indicate the indices betweeen [0, N)
*/

#include <bits/stdc++.h> 
long long inv(long long* arr, long long si, long long mid, long long ei){
    long long count = 0;
    long long i = si, j = mid, k = 0;
    long long* nums = new long long[ei-si+1];
    while(i < mid and j <= ei){
        if(arr[i] <= arr[j]){
            nums[k++] = arr[i++];
        }
        else{
            nums[k++] = arr[j++];
            count += mid - i;
        }
    }
    while(i < mid){
        nums[k++] = arr[i++];
    }
    while(j <= ei){
        nums[k++] = arr[j++];
    }
    for(long long x = si; x <= ei; x++){
        arr[x] = nums[x-si];
    }
    return count;
}
long long f(long long* arr, int si, int ei){
    if(si >= ei)
        return 0;
    long long mid = (si+ei)/2;
    long long count = f(arr, si, mid);
    count += f(arr, mid+1, ei);
    count += inv(arr, si, mid+1, ei);
    return count;
}
long long getInversions(long long *arr, int n){
    // Write your code here
    return f(arr, 0, n-1);
}
