#include <iostream>
#include <vector>

using namespace std;

int knapsack(vector<int> value, vector<int> weight, int cap, int n)
{
	int dp[n + 1][cap + 1];

	// Initializing a 2D array 'dp' for dynamic programming
	for (int i = 0; i <= n; i++)
	{
		for (int w = 0; w <= cap; w++)
		{
			if (i == 0 || w == 0)
			{
				// Base case: If there are no items or no capacity, the value is 0.
				dp[i][w] = 0;
			}
			else if (weight[i - 1] <= w)
			{
				// If the current item can fit in the remaining capacity,
				// we have two choices: either include it or exclude it.
				// We choose the maximum value between the two.
				dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
			}
			else
			{
				// If the current item's weight exceeds the capacity, we can't include it.
				dp[i][w] = dp[i - 1][w];
			}
		}
	}

	// The final entry in the dp array contains the maximum value achievable
	// with the given capacity and items.
	return dp[n][cap];
}

int main()
{
	// Define the values and weights of items
	vector<int> value = {10, 5, 15};
	vector<int> weight = {2, 3, 5};

	int n = value.size(); // Number of items
	int cap = 5;		  // Knapsack capacity

	// Call the 'knapsack' function to find the maximum value
	int res = knapsack(value, weight, cap, n);

	// Output the result
	cout << res;

	return 0;
}

/*Absolutely, let's go through the dp table step by step with a simple explanation for each item:

markdown
Copy code
    | 0 | 1 | 2 | 3 | 4 | 5 |
---------------------------
0   | 0 | 0 | 0 | 0 | 0 | 0 |
2   |   |   |   |   |   |   |
3   |   |   |   |   |   |   |
5   |   |   |   |   |   |   |
Step 1: Consider Item 1 (2 weight, 10 value)

Cell (1, 0):

If the knapsack has no capacity, regardless of items, the value is always 0.
Cell (1, 1):

With a knapsack of capacity 1, we can't fit Item 1 (weight 2), so the value is 0.
Cell (1, 2):

With a knapsack of capacity 2, we can fit Item 1 (weight 2).
We have two choices:
Include Item 1: Value = 10 (Value of Item 1) + Value of dp[0][0] (Value without Item 1) = 10 + 0 = 10
Exclude Item 1: Value = Value of dp[0][2] (Value without Item 1) = 0
The maximum value is 10.
Cell (1, 3):

With a knapsack of capacity 3, we can fit Item 1 (weight 2).
We have two choices:
Include Item 1: Value = 10 (Value of Item 1) + Value of dp[0][1] (Value without Item 1) = 10 + 0 = 10
Exclude Item 1: Value = Value of dp[0][3] (Value without Item 1) = 0
The maximum value is 10.
Cell (1, 4):

With a knapsack of capacity 4, we can fit Item 1 (weight 2).
We have two choices:
Include Item 1: Value = 10 (Value of Item 1) + Value of dp[0][2] (Value without Item 1) = 10 + 0 = 10
Exclude Item 1: Value = Value of dp[0][4] (Value without Item 1) = 0
The maximum value is 10.
Cell (1, 5):

With a knapsack of capacity 5, we can fit Item 1 (weight 2).
We have two choices:
Include Item 1: Value = 10 (Value of Item 1) + Value of dp[0][3] (Value without Item 1) = 10 + 0 = 10
Exclude Item 1: Value = Value of dp[0][5] (Value without Item 1) = 0
The maximum value is 10.
After completing this, the first row is populated.

Step 2: Consider Item 2 (3 weight, 5 value)

Cell (2, 0):

No capacity, so the value is always 0.
Cell (2, 1):

Capacity is less than the weight of Item 2, so it can't be included. Value remains 0.
Cell (2, 2):

Capacity is less than the weight of Item 2, so it can't be included. Value remains 0.
Cell (2, 3):

We can fit Item 2 (weight 3) in a knapsack of capacity 3.
We have two choices:
Include Item 2: Value = 5 (Value of Item 2) + Value of dp[1][0] (Value without Item 2) = 5 + 0 = 5
Exclude Item 2: Value = Value of dp[1][3] (Value without Item 2) = 0
The maximum value is 5.
Cell (2, 4):

We can fit Item 2 (weight 3) in a knapsack of capacity 4.
We have two choices:
Include Item 2: Value = 5 (Value of Item 2) + Value of dp[1][1] (Value without Item 2) = 5 + 0 = 5
Exclude Item 2: Value = Value of dp[1][4] (Value without Item 2) = 0
The maximum value is 5.
Cell (2, 5):

We can fit Item 2 (weight 3) in a knapsack of capacity 5.
We have two choices:
Include Item 2: Value = 5 (Value of Item 2) + Value of dp[1][2] (Value without Item 2) = 5 + 10 = 15
Exclude Item 2: Value = Value of dp[1][5] (Value without Item 2) = 10
The maximum value is 15.

Step 3: Consider Item 3 (5 weight, 15 value)

Cell (3, 0):

No capacity, so the value is always 0.
Cell (3, 1):

Capacity is less than the weight of Item 3, so it can't be included. Value remains 0.
Cell (3, 2):

Capacity is less than the weight of Item 3, so it can't be included. Value remains 0.
Cell (3, 3):

Capacity is less than the weight of Item 3, so it can't be included. Value remains 0.
Cell (3, 4):

Capacity is less than the weight of Item 3, so it can't be included. Value remains 0.
Cell (3, 5):

We can fit Item 3 (weight 5) in a knapsack of capacity 5.
We have two choices:
Include Item 3: Value = 15 (Value of Item 3) + Value of dp[2][0] (Value without Item 3) = 15 + 0 = 15
Exclude Item 3: Value = Value of dp[2][5] (Value without Item 3) = 15
The maximum value is 15.
Here is the final dp table:

markdown
Copy code
    | 0 | 1 | 2 | 3 | 4 | 5 |
---------------------------
0   | 0 | 0 | 0 | 0 | 0 | 0 |
2   | 0 | 0 |10 |10 |10 |10 |
3   | 0 | 0 | 5 |15 |15 |15 |
5   | 0 | 0 | 5 |15 |15 |20 |
Thank you for your patience, and I appreciate your understanding. If you have any further questions or if there's anything else you'd like to discuss, feel free to let me know!
*/




