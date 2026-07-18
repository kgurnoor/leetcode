class Solution {
public:
    //P[i] starts with radius value while keeping i as centre. 
    string longestPalindrome(string s) {
        string t = "^#"; //to denote string boundary
        //creating string t to handle odd even cases, using # -> ^#a#b#b#$ (len = 9) && ^#a#b#$ (len = 7) both odd
        for(char c : s){
            t += c ;
            t += "#";
        }
        t+="$";
        int C = 0; //centre of last stored palindrome
        int R = 0; //right boundary of last stored palindrome that goes rightmost 
        int n = t.size(); //length of modified string
        vector <int> P(n,0); //new vector array to contain palindromic radius/ length of each i
        for(int i = 1; i < n-1; i++){ //removing boundary characters
            int mirror_idx = 2*C - i; 
            if(i < R){ //possibility of mirror or touching right boundary 
                // i is inside the current best palindrome -> mirror trick applies
                // We can safely trust AT LEAST this much before checking further:
                // - either P[mirror] (if it fits inside the boundary)
                // - or the guaranteed remaining distance to R (if P[mirror] pokes past)
                P[i] = min(P[mirror_idx], R-i);
            }
            //does not fit in palindromic boundary -> have to expand
            // else: i is outside R, no mirror info helps, P[i] starts at 0 (default)

            // Attempt to expand further beyond whatever P[i] currently is.
            // This is the "manual expansion" step -- only ever needed for the
            // part not already guaranteed by symmetry.
            while(t[i + P[i] + 1] == t[i - P[i] - 1]){
                P[i] ++; 
            }
            // If this palindrome reaches further right than our previous best,
            // update the center and boundary -- R only ever moves forward.
            if(i+P[i] > R){
                C = i;
                R = i + P[i];
            }
        }
        // Step 2: find the max radius and its center
        int maxlen = 0;
        int centreindex = 0;
        for(int i = 1; i < n-1; i++){
            if(maxlen < P[i]){
                maxlen = P[i];
                centreindex = i;
            }
        }
        // Step 3: map back from transformed-string index to original string start index
        int start = (centreindex - maxlen) / 2;
        return (s.substr(start, maxlen));
    }
};