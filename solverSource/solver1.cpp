#include <solver.h>
bool isLessThan(Rectangle i,Rectangle j)
{
    return (i.x1<j.x1);
}
bool isInside(Rectangle inside,Rectangle outside)
{
    return (inside.x1>=outside.x1) 
            && (inside.x2<=outside.x2) 
            && (inside.y1>=outside.y1)
            && (inside.y2<=outside.y2);
}
int getMostNestedCount(std::vector<Rectangle> rectangleList)
{
    // Your implementation to find the most nested rectangle count goes here
    // For illustration purposes, let's just return the number of rectangles
    std::sort(rectangleList.begin(), rectangleList.end(), isLessThan);
    std::vector<int> nestedCount;
    int max=1;
    for (int i = 0; i < rectangleList.size(); i++)
    {
        nestedCount.push_back(1);
        for (int j = 0; j < i; j++)
        {
            if (isInside(rectangleList[i],rectangleList[j]))
            {
                if (nestedCount[i]<=nestedCount[j])
                {
                    nestedCount[i] = nestedCount[j]+1;
                    if (nestedCount[i]>max)
                    {
                        max = nestedCount[i];
                    }
                }
            }
        }
    }

    return max;
}