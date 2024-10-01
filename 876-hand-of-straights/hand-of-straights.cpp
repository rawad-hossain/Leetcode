class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        if (hand.size() % groupSize != 0)
            return false;

        unordered_map<int, int> freq;
        priority_queue<int, vector<int>, greater<int>> pq;

        /*
      map = {key: value}
      freq= { key: value}
      here, i = key ; value = freq[i]
      here, keys are the array elements // i
      values are the frequency/count of the array elements // freq[i]
      */

        for (auto i : hand)
            freq[i]++;

        /*
        freq = {
              1 : 1, // card 1 appears once
              2 : 2, // card 2 appears twice
              3 : 2, // card 3 appears twice
              4 : 1, // card 4 appears once
              6 : 1, // card 6 appears once
              7 : 1, // card 7 appears once
              8 : 1  // card 8 appears once
        }
        */

        for (auto it : freq)
            pq.push(it.first);

        /*
        pq = [1, 2, 3, 4, 6, 7, 8]
        */

        while (!pq.empty())
        {
            int top_element = pq.top(); // top = 1

            for (int i = top_element; i < top_element + groupSize;
                 i++) // 1 -> 3, 3 times
            {
                if (freq.find(i) == freq.end())
                    // finds the key at ith index,
                    // When find(i) returns freq.end(), it means the key i was
                    // not found in the map.
                    return false;

                freq[i]--;

                if (freq[i] == 0)
                {
                    if (i != pq.top()) // let i = 2
                        return false;
                    /*
                    1: 1
                    2:0 //freq of 2 is 0 but not the top element. so false
                    3: 1
                    */
                    pq.pop();
                }
            }
        }
        return true;
    }
};