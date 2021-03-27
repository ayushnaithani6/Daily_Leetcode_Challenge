// build this solution from scratch
// do revise
// Also check out bit manipulation approach

class Solution {
public:
    int divide(long long dividend, long long divisor) {
        long long mid,s=INT_MIN,e=INT_MAX,ans=s;
        bool neg=(divisor<0);
        
        if(neg){
            while(s <= e){
                mid=s+(e-s)/2;
                if(mid*1ll*divisor<=dividend){
                    ans=mid;
                    e=mid-1;
                }
                else s=mid+1;
            }  
        }
        else{
            while(s <= e){
                mid=s+(e-s)/2;
                if(mid*1ll*divisor<=dividend){
                    ans=mid;
                    s=mid+1;
                }
                else e=mid-1;
            }    
        }
        
        if(divisor*ans != dividend){
            if(dividend<0 && neg) --ans;
            if(dividend<0 && !neg) ++ans;   
        }
        
        return ans;
    }
};
