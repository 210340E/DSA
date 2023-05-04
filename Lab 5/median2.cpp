#include<iostream>
#include<vector>
#include<iomanip>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    int Arr[size];
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        Arr[i] = rand();
    }
    int temp = size;
    vector<int> Temp_Array;
    
    double Median;
    
    
    for(int i = 0;i<size;i++ ){
        
        Temp_Array.push_back(Arr[i]); 
        int tsize = Temp_Array.size();
        sort(Temp_Array.begin(),Temp_Array.end()); 

        
        if (tsize == 1){
            Median = Temp_Array[0];
        } else if (tsize % 2 == 0){
            int center_index = tsize / 2;
            Median = (Temp_Array[center_index] + Temp_Array[center_index-1]) / 2.0;
        } else {
            int center_index = tsize / 2;
            Median = Temp_Array[center_index];
        }
        
        for(int k : Temp_Array ){
            cout<< k << " " ;
        }
        cout<<endl;
        temp--;
        
        cout<<"Median : "<< Median <<right << endl;
    }
    
    return 0;
}