//using brian kernighan method
// class Solution {
// public:
//     int hammingWeight(int n) {
//         int count  = 0 ;
//         while (n >0 ){
//             n = n & (n - 1);
//             count = count + 1 ;
//         }
//         return count;
//     }
// };


//simple bitwise check
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0 ;
        while (n > 0){
            count = count + (n & 1);
            n = n >> 1;
        }
        return count;
    }
};