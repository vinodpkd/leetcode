//832. Flipping an Image
/*
Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the resulting image.
To flip an image horizontally means that each row of the image is reversed.
    For example, flipping [1,1,0] horizontally results in [0,1,1].
To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.
  */

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {

        for(int i = 0;i < image.size();i++)
        {
            std::reverse(image[i].begin(),image[i].end());

            for(int j = 0;j < image[i].size();j++)
            {
                if(0 == image[i][j])
                    image[i][j] = 1;
                else
                    image[i][j] = 0;
            }
        }

        return image;
    }
};
