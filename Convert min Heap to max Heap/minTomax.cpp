#include <iostream>
#include <vector>
#include <queue>

void maxHeapify(vector<int> &nums, int N, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

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
        maxHeapify(nums, N, largest);
    }
}

void convertMinToMaxHeap(vector<int> &arr, int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, N, i);
    }
}