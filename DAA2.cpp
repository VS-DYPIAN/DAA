#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct job{
    char id;
    int deadline;
    int profit;
};

bool compare(job A, job B){
    return (A.profit>B.profit);
}

void job_seq(vector<job> jobs){
    int n=jobs.size();
    
    sort(jobs.begin(),jobs.end(),compare);
    
    vector<char> res(n);
    vector<bool> slot(n,false);
    
    for(int i=0;i<n;i++){
        for(int j=min(n,jobs[i].deadline)-1;j>=0;j--){
            if(slot[j]==false){
                slot[j]=true;
                res[j]=jobs[i].id;
                break;
            }
        }
    }
    
    
    for(int i=0;i<n;i++){
       if(slot[i]){
           cout<<res[i]<<" ";
       }
    }
    
}
int main()
{
    vector<job> jobs = {
        {'a', 2, 100},
        {'b', 1, 43},
        {'c', 3, 56},
        {'d', 1, 17},
        {'e', 3, 65}};

    job_seq(jobs);

    return 0;
}
/*Algorithm:-
Sort all jobs in decreasing order of profit.
Iterate on jobs in decreasing order of profit.
For each job , do the following :
Find a time slot i, such that slot is empty and i < deadline and i is greatest.Put the job in  this slot and mark this slot filled.
If no such i exists, then ignore the job. */
//Time Complexity: O(N2)
// Auxiliary Space : O(N)