class MedianFinder {
public:
    //creating the priority queues : max and min 
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    //defining object
    MedianFinder() {
    }
    //keeping sizes of max and min heap balanced
    void addNum(int num) {
        maxHeap.push(num); //put in first-half first, with low nums
        minHeap.push(maxHeap.top()); //shift to minHeap to balance the size
        maxHeap.pop(); //remove that element from maxHeap
        if(minHeap.size() > maxHeap.size()){ //balaning the minHeap
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size()){ //odd number of elements
            return maxHeap.top(); //return the last element of the first half
        }
        return (maxHeap.top() + minHeap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */