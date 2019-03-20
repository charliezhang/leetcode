class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        candidates_dedup = []
        limits = []
        for i in xrange(0, len(candidates)):
            if i == 0 or candidates[i] > candidates[i-1]:
                candidates_dedup.append(candidates[i])
                limits.append(1)
            else:
                limits[-1] += 1

        # print candidates_dedup, limits
        results = []
        self.search(target, candidates_dedup, limits, [], results)
        return results

    def search(self, target, candidates, limits, l, results):
        if len(candidates) == 0:
            return

        l2 = []
        cnt = 0
        while True:
            self.search(target, candidates[1:], limits[1:], l + l2, results)

            cnt += 1
            target -= candidates[0]
            l2.append(candidates[0])

            if (cnt > limits[0]):
                return

            if target < 0:
                return

            if target == 0:
                results.append(l + l2)
                return


