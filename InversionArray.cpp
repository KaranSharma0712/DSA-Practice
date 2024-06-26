/*Problem statement
There is an integer array ‘A’ of size ‘N’.
Number of inversions in an array can be defined as the number of pairs of ‘i’, ‘j’ such that ‘i’ < ‘j’ and ‘A[i]’ > ‘A[j]’.
You must return the number of inversions in the array.
For example,
Input:
A = [5, 3, 2, 1, 4], N = 5
Output:
7
Explanation: 
The pairs satisfying the condition for inversion are (1, 2), (1, 3), (1, 4), (1, 5), (2, 3), (2, 4), and (3, 4). 
The number of inversions in the array is 7.*/
int merge(vector<int>&arr,int low,int mid,int high){
    vector<int>temp;
    int count=0;
    int left = low;
    int right = mid+1;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            count+=(mid-left+1);
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i] = temp[i-low];
    }
    return count;
}

int mergeSort(vector<int>&arr,int low,int high){
    int cnt = 0;
    if(low>=high){
        return cnt;
    }
    int mid = (low+high)/2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid+1,high);
    cnt += merge(arr,low,mid,high);
    return cnt;
}
int numberOfInversions(vector<int>a,int n){
    return mergeSort(a, 0, n-1);
}
