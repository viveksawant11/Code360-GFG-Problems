#include <bits/stdc++.h>
using namespace std;

vector<int> giftsLeft(int n, int k, int q, vector<int> demands) 
{
   vector<int> result;
   int currentGifts = n;

   for (int demand : demands) {
      if (demand > currentGifts) {
         result.push_back(-1);
      }
      else {
         currentGifts -= demand;

         if (currentGifts < k)
               currentGifts = n;
         
         result.push_back(currentGifts);
      }
   }

   return result;
}

int main() {
   int n, k, q;
   cin >> n >> k >> q; 
   vector<int> demands(q);
   
   for (int i = 0; i < q; i++) {
      cin >> demands[i];
   }
   
   vector<int> result = giftsLeft(n, k, q, demands);
   
   for (int r : result) {
      cout << r << endl;
   }

   return 0;
}
