class Solution:
    def isHappy(self, n: int) -> bool:
        seen = set()
        s = str(n)
        while(1) :
            t = 0
            l = list(s)
            for ll in l :
                t += int(ll) * int(ll)
            if t == 1:
                return True
            if t not in seen :
                seen.add(t)
            else :
                return False
            s = str(t)
        return False
