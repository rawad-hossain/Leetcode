class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        //copies arr elemts to temp
        vector<int> temp(arr.begin(), arr.end());

        // Sort the copied array
        sort(temp.begin(), temp.end());

        map<int, int> mp;

        int rank = 1;

        for (int i = 0; i < arr.size(); i++) {
            int element = temp[i];
            if (mp[element] == 0) // mp["2"] = 1, key 2, value of 2 is 1
            {
                mp[element] = rank;
                rank++;
            }
        }

        /* key value pair stored in mp
        {2, 1}  index 0
        {6, 2}  index 1
        {6, 2}  index 2
        {15, 3} index 3
        ....
        ..
        */

        //    replace the elements in original arr with the ranks of those
        //    elements from mp

        for (int i = 0; i < arr.size(); i++) {
            int element = arr[i];
            arr[i] = mp[element];
        }

        return arr;
    }
};