//1828. Queries on Number of Points Inside a Circle
/*
You are given an array points where points[i] = [xi, yi] is the coordinates of the ith point on a 2D plane. Multiple points can have the same coordinates.
You are also given an array queries where queries[j] = [xj, yj, rj] describes a circle centered at (xj, yj) with a radius of rj.
For each query queries[j], compute the number of points inside the jth circle. Points on the border of the circle are considered inside.
Return an array answer, where answer[j] is the answer to the jth query.
*/
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        std::vector<int> inside{};
        for(int i = 0;i < queries.size();i++)
        {
            int count = 0;
            for(int j = 0;j < points.size();j++)
            {
                int sq = (points[j][0] - queries[i][0])*(points[j][0] - queries[i][0]) + (points[j][1] - queries[i][1])*(points[j][1] - queries[i][1]);
                if(sq <= queries[i][2]*queries[i][2])
                    count++;
            }
            inside.push_back(count);
        }

        return inside;
    }
};
