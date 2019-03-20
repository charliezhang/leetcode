class Solution(object):

    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        results = []
        self.search(target, candidates, [], results)
        return results

    def search(self, target, candidates, l, results):
        if len(candidates) == 0:
            return

        l2 = []
        while True:
            self.search(target, candidates[1:], l + l2, results)

            target -= candidates[0]
            l2.append(candidates[0])

            if target < 0:
                return

            if target == 0:
                results.append(l + l2)
                break



