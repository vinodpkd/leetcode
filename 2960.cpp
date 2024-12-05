//2960. Count Tested Devices After Test Operations
/*
You are given a 0-indexed integer array batteryPercentages having length n, denoting the battery percentages of n 0-indexed devices.

Your task is to test each device i in order from 0 to n - 1, by performing the following test operations:

    If batteryPercentages[i] is greater than 0:
        Increment the count of tested devices.
        Decrease the battery percentage of all devices with indices j in the range [i + 1, n - 1] by 1, ensuring their battery percentage never goes below 0, i.e, batteryPercentages[j] = max(0, batteryPercentages[j] - 1).
        Move to the next device.
    Otherwise, move to the next device without performing any test.

Return an integer denoting the number of devices that will be tested after performing the test operations in order.
*/
class Solution {
public:
    int countTestedDevices(vector<int>& bp) {
        int count{0};
        for(int i = 0;i < bp.size();i++)
        {
            if(bp[i] <= 0)
                continue;
            else
            {
                count++;
                for(int j = i+1;j < bp.size();j++)
                {
                    bp[j]--;
                }
            }
        }

        return count;
    }
};
