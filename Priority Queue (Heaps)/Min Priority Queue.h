// Implementation of Min Priority Queue

class PriorityQueue {
    vector<int> pq;

public:
    bool isEmpty() {
        return pq.size() == 0;
    }

    int getSize() {
        return pq.size();
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        if (isEmpty())
        {
            return INT_MIN;
        }
        int lastIndex = pq.size() - 1;
        int ans = pq[0];
        pq[0] = pq[lastIndex];
        pq.pop_back();

        int parentIndex = 0;
        
        //Down-Heapify
        while (parentIndex < (pq.size() - 2))
        {
            int lCI = (2 * parentIndex) + 1;
            int rCI = (2 * parentIndex) + 2;
            int minIndex = 0;
            lastIndex = pq.size() - 1;
            if (lCI <= lastIndex || rCI <= lastIndex)
            {
                int minValue = 0;
                if (lCI <= lastIndex && rCI > lastIndex)
                {
                    minValue = pq[lCI];
                }
                else if (rCI <= lastIndex && lCI > lastIndex)
                    minValue = pq[rCI];
                else
                    minValue = min(pq[lCI], pq[rCI]);

                if (minValue == pq[lCI])
                    minIndex = lCI;
                else
                    minIndex = rCI;

                if (pq[parentIndex] > minValue)
                {
                    int temp = pq[parentIndex];
                    pq[parentIndex] = pq[minIndex];
                    pq[minIndex] = temp;
                }
                else {
                    break;
                }

                parentIndex = minIndex;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
    
    // int removeMin() {
//   if (isEmpty()) {
//     return INT_MIN;
//   }
//   int ans = pq[0];
//   pq[0] = pq[pq.size() - 1];
//   pq.pop_back();

//   // Down-heapify
//   int parentIndex = 0;
//   int leftChildIndex = 2 * parentIndex + 1;
//   int rightChildIndx = 2 * parentIndex + 2;
//   while (leftChildIndex < pq.size()) {
//     int minIndex = parentIndex;
//     if (pq[minIndex] > pq[leftChildIndex]) {
//       minIndex = leftChildIndex;
//     }
//     if (rightChildIndx < pq.size() && pq[rightChildIndx] < pq[minIndex]) {
//       minIndex = rightChildIndx;
//     }
//     if (minIndex == parentIndex) {
//       break;
//     }
//     int temp = pq[minIndex];
//     pq[minIndex] = pq[parentIndex];
//     pq[parentIndex] = temp;
//     parentIndex = minIndex;
//     leftChildIndex = 2 * parentIndex + 1;
//     rightChildIndx = 2 * parentIndex + 2;
//   }
//   return ans;
// }
};
