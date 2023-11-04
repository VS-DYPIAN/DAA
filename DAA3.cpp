#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item{
     
    int value;
    int weight;
    double ratio;
    
};

bool compare(Item A,Item B){
    return A.ratio>B.ratio;
}

double Frac_knapsack(vector<Item> Items,int limit){
    
    sort(Items.begin(),Items.end(),compare);
    double total_value=0.0;
    int current_weight=0;
    
    for(Item& item:Items){
        if(item.weight+current_weight<=limit){
            total_value+=item.value;
            current_weight+=item.weight;
        }
        else{
            double remain_weight=limit-current_weight;
            total_value+=item.ratio*remain_weight;
            break;
        }
    }
    return total_value;
}
int main()
{
   vector<Item> items={
       {60, 10, 0.0},
        {100, 20, 0.0},
        {120, 30, 0.0}
   };
   int limit =50;
   for(Item& item:items){
       item.ratio=(double)item.value/item.weight;
   }
   
   double profit=Frac_knapsack(items,limit);
   
   cout<<profit<<" ";
    return 0;
}
//Dont use auto while iterating use Item& item:items for it;
/*Time Complexity:

Sorting the items: O(n log n)
Iterating through the items: O(n)
Overall: O(n log n)

Space Complexity:

Storing items: O(n)
Temporary variables: O(1)
Overall: O(n)*/
