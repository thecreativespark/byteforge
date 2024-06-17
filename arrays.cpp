#include <iostream>
#include <vector>
using std::cin, std::cout, std::vector;

vector<int> unqvec(vector<int> nunq){
    vector<int> unq(nunq.size());
    int k = 0;
    for(int i =0; i<nunq.size();i++){
        bool isunq = true;
        for(int j=0; j<unq.size(); j++){
            if(nunq[i]==unq[j]){
                isunq = false;
            }
        }
        if(isunq==true){
            unq.push_back(nunq[i]);
            k++;
        }
    }
    vector<int> runq(k);
    int j=0;
    for(int i=0; i<k;i++){
        runq[j] = unq[unq.size()-1-i];
        j++;
    }
    return runq;
}

//Max of an array
int max(vector<int> a){
    int max=a[0];
    for(int i=0; i<=a.size(); i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    return max;
}

//Min of an array
int min(vector<int> a){
    int min=a[0];
    for(int i=0; i<=a.size(); i++){
        if(a[i]<min){
            min = a[i];
        }
    }
    return min;
}

//Average of an array
float avg(vector<int> a){
    float sum=0;
    for(int i=0; i<=a.size(); i++){
        sum+=a[i];   
    }
    return sum/a.size();
}


typedef struct{
    int element;
    int occurance;
} elem;

int mode(vector<int> a){
    vector<int> unq = unqvec(a);
    elem e[unq.size()];
    for(int i=0;i<unq.size();i++){
        e[i].element = unq[i];
    }
    for(int i=0; i<unq.size();i++){
        for(int j=0;j<a.size();j++){
            if(e[i].element==a[j]){
                e[i].occurance++;
            }
        }
    }

    int mode_occ =0;
    int mode = 0;

    for(int i=0; i<unq.size();i++){
        if(e[i].occurance>mode_occ){
            mode = e[i].element;
            mode_occ = e[i].occurance;
        }
    }
    return mode;
}