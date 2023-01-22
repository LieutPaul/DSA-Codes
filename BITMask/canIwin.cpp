#include<bits/stdc++.h>
using namespace std;

class Solution {
    
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        //no need to run, it will be true
        if (maxChoosableInteger >= desiredTotal){
            return true;
        }
        
        //if total > n(n+1)/2, we can;t get it, no matter what, as it is max sum
        if (desiredTotal > (maxChoosableInteger*(maxChoosableInteger+1))/2){
            return false;
        }
        
        map<int, bool> resultsMap;
        return canPlayerWin(maxChoosableInteger, desiredTotal, 0, resultsMap);
    }
    
    bool canPlayerWin(int maxChoosableInteger, int desiredTotal, int bitmask, map<int, bool> &resultsMap){
        //if it has been already stores, don't calculate again. This is dynamic programming
        
        if (desiredTotal<=0)
            return false;
        if (resultsMap.find(bitmask)!= resultsMap.end()){
            return resultsMap[bitmask];
        }
        
        
        for (int i=1; i<=maxChoosableInteger; i++){
            int curr = (1<<i);
            bool isAvailable = ((curr & bitmask) ==0) ;
            //isAvailable indicates if it is present or not. If anding them gives 0, then the position is available
            
            
            if (isAvailable){
                int updatedBitmask = curr | bitmask;
                //updated value
                
                // i+1 everywhere because cards are numbered 1 to 15, while indices are 0 to 14.
                // if desiredTotal <= i+1, we will win
                // or if the opposite player cannot win with the updated conditions, then we win.
                if (desiredTotal <= i || !canPlayerWin(maxChoosableInteger, desiredTotal-i, updatedBitmask, resultsMap)){
                    // make entry in map and return
                    resultsMap[bitmask]= true;
                    return true;
                }
                
                
            }
            
            // make entry in map and return
            
        }
        resultsMap[bitmask] = false;
        return false;
    }
};