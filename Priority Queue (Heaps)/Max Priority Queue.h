// Implementation of Max Priority Queue
class PriorityQueue {
    vector<int> pq;

public:
    PriorityQueue() {

    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] > pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int getMax() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    int removeMax() {
        if (isEmpty())
        {
            return INT_MAX;
        }
        int lastIndex = pq.size() - 1;
        int ans = pq[0];
        pq[0] = pq[lastIndex];
        pq.pop_back();

        int parentIndex = 0;

        while (parentIndex < (pq.size() - 2))
        {
            int lCI = (2 * parentIndex) + 1;
            int rCI = (2 * parentIndex) + 2;
            int maxIndex = 0;
            lastIndex = pq.size() - 1;
            if (lCI <= lastIndex || rCI <= lastIndex)
            {
                int maxValue = 0;
                if (lCI <= lastIndex && rCI > lastIndex)
                {
                    maxValue = pq[lCI];
                }
                else if (rCI <= lastIndex && lCI > lastIndex)
                    maxValue = pq[rCI];
                else
                    maxValue = max(pq[lCI], pq[rCI]);

                if (maxValue == pq[lCI])
                    maxIndex = lCI;
                else
                    maxIndex = rCI;

                if (pq[parentIndex] < maxValue)
                {
                    int temp = pq[parentIndex];
                    pq[parentIndex] = pq[maxIndex];
                    pq[maxIndex] = temp;
                }
                else {
                    break;
                }

                parentIndex = maxIndex;
            }
            else
            {
                break;
            }
        }
        return ans;
    }

// int removeMax() {
//     if (data.size() == 0) {
//         return INT_MIN;
//     }
//     int ans = data[0];
//     data[0] = data[data.size() - 1];
//     data.pop_back();
//     int parentIndex = 0;
//     int leftIndex = parentIndex * 2 + 1;
//     int rightIndex = leftIndex + 1;
//     while (leftIndex < data.size()) {
//         int maxIndex = parentIndex;
//         if (data[leftIndex] > data[maxIndex]) {
//             maxIndex = leftIndex;
//         }
//         if (rightIndex < data.size() && data[rightIndex] > data[maxIndex]) {
//             maxIndex = rightIndex;
//         }
//         if (maxIndex == parentIndex) {
//             break;
//         }
//         int temp = data[maxIndex];
//         data[maxIndex] = data[parentIndex];
//         data[parentIndex] = temp;
//         parentIndex = maxIndex;
//         leftIndex = parentIndex * 2 + 1;
//         rightIndex = leftIndex + 1;
//     }
//     return ans;
// }

    int getSize() {
        return pq.size();
    }

    bool isEmpty() {
        return pq.size() == 0;
    }
};
