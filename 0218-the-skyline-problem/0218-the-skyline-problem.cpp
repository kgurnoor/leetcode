class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> result;
        vector<pair<int,int>> store; //stores the coordinates of the building start,hight and end,height
        multiset<int> pq{0}; // sorted, with duplicates allowed and min and max element, accessible and removable , starts with 0
        for(auto b:buildings){ //b is [x,y,height]
            store.push_back({b[0], -b[2]});
            store.push_back({b[1], b[2]});
        }
        //sort coordinates 
        sort(store.begin(), store.end());
        int ongoingheight = 0;
        //store.first = x coordinate and store.second = height
        for(int i = 0; i < store.size(); i++){
            int curr_x = store[i].first;
            int curr_h = store[i].second;
            if (curr_h < 0){   // start of building -> add its height
                pq.insert(-curr_h);
            }
            else{  // end of building -> remove its height
                pq.erase(pq.find(curr_h));
            }
            int pqTop = *pq.rbegin(); //max height in multiset -> reverse begin
            if(ongoingheight != pqTop){  // height changed -> new key point
                ongoingheight = pqTop;
                result.push_back({curr_x, ongoingheight});
            }
        }
        return result;
    }
};