class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        points.sort()
        i=0
        while i<len(points)-1:
            if points[i][1]>=points[i+1][0]:
                points[i][0]=max(points[i][0],points[i+1][0])
                points[i][1]=min(points[i][1],points[i+1][1])
                points.pop(i+1)
                i=i-1
            i=i+1
        return len(points)


        