#include <iostream>
#include <ctime>

using namespace std;

void non_recursive(int n){
    int fib1 =0, fib2=1 , fib =0;
    for(int i=0;i<=n;i++){
        cout<<fib1<<" ";
        fib = fib1+fib2;
        fib1 =fib2;
        fib2 =fib;
    }
}

void recursive1(int n,int fib1,int fib2,int i){
    if(i<=n){
        cout<<fib1<<" ";
        i++;
        recursive1(n,fib2,fib1+fib2,i);
    }
}

int recursive2(int n){
    if(n<=1){
        return n;
    }
    
    return recursive2(n-1)+recursive2(n-2);
}
int main()
{
    int n=15;
    cout<<"Non Recursive\n";
    clock_t start=clock();
    non_recursive(n);
    clock_t end=clock();
    double t=double(end-start)/CLOCKS_PER_SEC*1000000;
    cout<<"\ntime taken is "<<t<<" microsecond"<<endl;
    
    cout<<"Recursive 1"<<endl;
    start=clock();
    recursive1(n,0,1,0);
    end=clock();
    t=double(end-start)/CLOCKS_PER_SEC*1000000;
    cout<<"\n time taken is "<<t<<" microsecond"<<endl;
    
    cout<<"Recursive 2"<<endl;
    start=clock();
    for(int i=0;i<=n;i++){
        cout<<recursive2(i)<<" ";
    }
    end=clock();
    t=double(end-start)/CLOCKS_PER_SEC*1000000;
    cout<<"\nTime taken is "<<t<<" microsecond"<<endl;
    
    return 0;
}

//for less value of n it will show that non Recursive will take more time but it is not true as Recursive take more
//time so if we take high value of n than we will see that.
// for iterative
// time  O(n)  space O(1)

//for Recursive
//time O(2^n) space O(n)