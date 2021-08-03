#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Mergesort{
    public:
        vector<int> A;
        double  num_inversions;
        int len_vec;

        Mergesort(vector<int> B){
            A=B;
            len_vec = B.size();
            num_inversions=0;
        }

        void merge_sort(vector<int>& A, int start_ind, int end_ind){
            int mid_ind = (start_ind+end_ind)/2;
            if (start_ind>=end_ind){
                return;
            }
            merge_sort(A,start_ind,mid_ind);
            merge_sort(A,mid_ind+1,end_ind);
            merge_subs(A,start_ind,mid_ind,end_ind);
        }

        void merge_subs(vector<int>& A,int start_ind, int mid_ind, int end_ind){
            vector<int> temp;
            int len_temp = end_ind-start_ind+1;
            temp.assign(len_temp,0);
            int i = start_ind;
            int j = mid_ind+1;
            int ind=0;
            while (i<=mid_ind && j<=end_ind){
                if (A[i]<=A[j]){
                    temp[ind]=A[i];
                    ind++;
                    i++;
                }else{
                    temp[ind]=A[j];
                    ind++;
                    j++;
                    num_inversions=num_inversions+(mid_ind-i+1);
                }
            }

            if (i<=mid_ind){
                for (int k=i; k<=mid_ind ; k++){
                    temp[ind]=A[k];
                    ind++;
                }
            }
            if (j<=end_ind){
                for (int k=j; k<=end_ind ; k++){
                    temp[ind]=A[k];
                    ind++;
                }
            }
            ind=0;
            for (int k = start_ind; k<=end_ind ; k++){
                A[k]=temp[ind];
                ind++;
            }

        }

};

void print(vector<int> A) {
   cout << "The vector elements are : ";

   for(int i=0; i < A.size(); i++){
    cout << A[i] << ' ';
   }
};


int main(){
    string STRING;
    ifstream infile;
    vector<int> A;
    infile.open ("G:\\My Drive\\course\\Algorithm\\Mergesort and inversion\\nums.txt");
    while (!infile.eof()){
        getline(infile,STRING);
        A.push_back(stoi(STRING));
    }
    infile.close();
    cout<<A.size()<<endl;

    Mergesort sorter  = Mergesort(A);
    sorter.merge_sort(A,0,A.size()-1);
    cout.precision(100);
    cout<<sorter.num_inversions;

}