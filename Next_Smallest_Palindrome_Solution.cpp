**************************************************************************  Question  ***************************************************************************************

  Given a number, in the form of an array Num[] of size N containing digits from 1 to 9(inclusive). The task is to find the next smallest palindrome strictly larger than the given number.

Example 1:

Input:
N = 11
Num[] = {9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2}
Output: 9 4 1 8 8 0 8 8 1 4 9
Explanation: Next smallest palindrome is
9 4 1 8 8 0 8 8 1 4 9
Example 2:

Input:
N = 5
Num[] = {2, 3, 5, 4, 5}
Output: 2 3 6 3 2
Explanation: Next smallest palindrome is
2 3 6 3 2
Your Task:
Complete the function generateNextPalindrome() which takes an array num, and a single integer n, as input parameters and returns an array of integers denoting the answer. You don't to print answer or take inputs.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 105
1 <= Num[i] <= 9

***********************************************************************  Solution  *************************************************************************

  //{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> generateNextPalindrome(int num[], int n) {
	    // code here
	     bool change=1;
        for(int i=0;i<n/2;i++){
            if(num[i]>num[n-i-1]){
                change=0;
            }
            else if(num[i]<num[n-i-1])change=1;
            
            num[n-i-1]=num[i];
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++)ans[i]=num[i];
        int carry=change;
        int ind=n/2;
        while(carry and ind<n){
            if(num[ind]==9){
                ans[ind]=0;
                ans[n-ind-1]=0;
            }
            else{
                ans[ind]++;
                ans[n-ind-1]=ans[ind];
                carry=0;
            }
            ind++;
        }
        if(carry){
            ans[0]=1;
            ans.push_back(1);
        }
        return ans;
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
