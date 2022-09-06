Using GAP Algorithm


#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	
    for(int i=0;i<n;i++){
        arr1[m+i]=arr2[i];
    }
    int gap = (int)ceil((m+n)/2.00);
    
    while(gap>1){
        int i=0;
        int j=gap+i;
        while(i<j && j<(m+n)){
            if(arr1[i]>arr1[j])
                swap(arr1[i],arr1[j]);
            
            i++, j++;
        }
        gap=(int)ceil(gap/2.00);
    }
    for(int i=0; i<(m+n)-1;i++){
        if(arr1[i]>arr1[i+1])
            swap(arr1[i],arr1[i+1]);
    }
    return arr1;
}
