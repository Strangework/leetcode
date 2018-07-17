class Solution:
    def simpleMaxArea(self, height):
        """
        Simplest possible solution
        """
        # Iterate across every pair of lines
        currMax = 0
        for i in range(0, len(height)):
            for j in range(i, len(height)):
               # Find area of the 'square' between the two lines 
               area = min(height[i], height[j]) * (j-i)
               # Compare against current max
               if area > currMax:
                  currMax = area

        return currMax

    def maxArea(self, height):
