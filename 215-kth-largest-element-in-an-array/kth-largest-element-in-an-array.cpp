class Solution
{
public:
    void maxHeapify(vector<int> &nums, int N, int i)
    {
        int largest = i;       // Initialize largest as root
        int left = 2 * i + 1;  // Left child
        int right = 2 * i + 2; //

        if (left < N && nums[left] > nums[largest])
        {
            largest = left;
        }

        if (right < N && nums[right] > nums[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(nums[i], nums[largest]);
            maxHeapify(nums, N, largest); // Recursively heapify the affected subtree
        }
    }

    void buildMaxHeap(vector<int> &nums)
    {
        int N = nums.size();
        for (int i = N / 2 - 1; i >= 0; i--)
        {
            maxHeapify(nums, N, i);
        }
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        buildMaxHeap(nums);
        int N = nums.size();

        //sorting
        for (int i = N - 1; i >= N - k + 1; i--)
        {
            swap(nums[0], nums[i]);
            maxHeapify(nums, i, 0);
        }
        return nums[0];
    }
};