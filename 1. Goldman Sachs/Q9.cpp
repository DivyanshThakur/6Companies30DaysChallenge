#include <iostream>

using namespace std;

class Solution{   
public:
    // TC: O(N)
    // SC: O(1)
    string printMinNumberForPattern(string S){
        string res;
        int maxElement = 0, prev = 0;
        
        for(int i=0; i<S.size(); i++) {
            int j, nextNoOfD = 0;
            
            switch(S[i]) {
                case 'I':
                    j = i+1;
                    while(j<S.size() and S[j] == 'D') {
                        nextNoOfD++;
                        j++;
                    }
                    
                    if(i == 0) {
                        res += to_string(++prev);
                        prev = maxElement = nextNoOfD + 2;
                        res += to_string(maxElement);
                    } else {
                        prev = maxElement += nextNoOfD + 1;
                        res += to_string(prev);
                    }
                break;
                
                case 'D':
                    if(i == 0) {
                        j = i+1;
                        while(j<S.size() and S[j] == 'D') {
                            nextNoOfD++;
                            j++;
                        }
                        
                        prev = maxElement = nextNoOfD + 2;
                        
                        res += to_string(prev);
                        res += to_string(--prev);
                    } else {
                        res += to_string(--prev);
                    }
                break;
            }
        }
        return res;
    }
};
