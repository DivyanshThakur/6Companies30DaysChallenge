#include <iostream>

using namespace std;

class Solution{
    int partition(char arr[], int l, int r, int pivot) {
        int j=0;
        for(int i = 0; i<r; i++) {
            if(arr[i] < pivot) swap(arr[i], arr[j++]);
            else if(arr[i] == pivot) swap(arr[i--], arr[r]);
        }
        swap(arr[j], arr[r]);
        return j;
    }
    
    void quickSort(char nuts[], char bolts[], int i, int j) {
        if(i>=j) return;
        
        int ind = partition(nuts, i, j, bolts[j]);
        partition(bolts, i, j, nuts[ind]);
        quickSort(nuts, bolts, i, ind-1);
        quickSort(nuts, bolts, ind+1, j);
    }
public:	

	void matchPairs(char nuts[], char bolts[], int n) {
	    quickSort(nuts, bolts, 0, n-1);
	}

};