#include<iostream>
using namespace std;

void BubbleSort(int a[], int ln){

    for(int i =0; i < ln ; ++i){
        for(int c = 0; c < ln; ++c){
            if(a[c] > a[c+1]){
                int tmp = a[c+1];
                a[c+1] = a[c];
                a[c] = tmp;
            }
        }
    }
}


void SelectionSort(int a[], int ln){

    for(int i = 0; i < ln; ++i){
        int pi = i;
        
        for(int c = i +1; c<ln; ++c){
        
            if(a[pi]  > a[c]){
                pi = c;
            }
        }    
        
        int tmp = a[pi];
        a[pi] = a[i];
        a[i]  = tmp;
    }
}



void InsertionSort(int a[], int ln){

    for(int i=1; i< ln; ++i){
        int key = a[i];
        int pi = i -1;
        while(key < a[pi] && pi >=0){
            a[pi + 1] = a[pi];
            --pi;
        }
        a[pi + 1] = key;
    }
}



// O (n log n)
void Merging(int a[], int low, int mid, int high){

    int left_counter = mid - low + 1;
    int right_counter = high - mid;
    int left_arr[left_counter];
    int right_arr[right_counter];

    for(int i = 0; i < left_counter; ++i){
        left_arr[i] = a[low + i];
    }
    
     for(int i = 0; i < right_counter; ++i){
       right_arr[i] = a[mid + i + 1];
    }
    
    int left, org, right;
    left=right = 0;
    org = low;
    
    while(left < left_counter && right < right_counter){
        if(left_arr[left] < right_arr[right]){
            a[org] = left_arr[left];
            ++left;
        }
        else{
            a[org] = right_arr[right];
            ++right;
        }
        ++org;
    }
    
    
    while(left < left_counter){
        a[org] = left_arr[left];
        ++left;
        ++org;
    }
    
       while(right < right_counter){
        a[org] = right_arr[right];
        ++right;
        ++org;
    }
    
}


void MergSort(int a[], int low, int high){

    if(low<high){
        int mid = (low+high)/2;
        MergSort(a,low,mid);
        MergSort(a,mid+1, high);
        Merging(a, low, mid,high);
    }
}


int Part(int a[], int low, int high){
    int mid = a[(low+high)/2];
    
        while(true){
        
            while(a[low] < mid){
                ++low;
            }
            
            while(a[high] > mid){
                --high;
            }
            
            if(low>=high){
                return high;
            }
            
            int tmp = a[high];
                a[high] = a[low];
                a[low] = tmp;
                ++low;
                --high;
        }

}

void QuickSort(int a[], int low, int high){

    if(low<high){
        int piv = Part(a,low,high);
        QuickSort(a,low, piv);
        QuickSort(a,piv + 1, high);
    }

}



void Heapify(int a[], int ln, int root){
// var highest equalrs root left and right are leaf to node
    int highest = root;
    int left = root * 2 + 1;
    int right = root *2 + 2;
    
    // if left node is less the length and left node value greater then root then assign highest to left
    if(left < ln && a[left] > a[highest]){
        highest = left;
    }
    
    // assignes highest to right leaf node if it more then the root
    if(right < ln && a[right] > a[highest]){
        highest = right;
    }
    
    // swap the highest node for the root node in the tree like structer
    if(highest != root){
        int tmp = a[root];
        a[root] = a[highest];
        a[highest] = tmp;
        
        Heapify(a,ln,highest);
    }

}

void HeapSort(int a[], int ln){
    // Creats the heap
    for(int i = ln/2-1; i >= 0; --i){
        Heapify(a,ln,i);
    
    }
    
    // Sorts through the nodes zero stands for the root of each sort
    for(int i = ln-1; i >= 0; --i){
        int tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        
        Heapify(a,i,0);
    
    }

}

void Dp(int a[], int ln){

    for(int i = 0; i<ln; ++i){
        cout<<a[i]<<"\t";
    
    }

}


int main(){
    int a[] = {45,50,40,35,60,30,25,20,15,5,10,0,55};
    int ln = sizeof(a)/sizeof(a[0]);
    cout<<"Unsorted: "<<endl;
    Dp(a,ln);
    cout<<endl;
    cout<<"Sorted: "<<endl;
    
    HeapSort(a,ln);
    //QuickSort(a,0,ln-1);
    //MergSort(a,0,ln-1);
    // BubbleSort(a,ln);
    //SelectionSort( a, ln);
    //InsertionSort(a, ln);
    Dp(a,ln);
    
    return 0;
}
