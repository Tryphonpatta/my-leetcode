class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        ans = []
        i = 0
        for ss in s :
            ans += ss
            if len(ans) >= len(part) : 
                # print(ans[len(ans) - len(part) :])
                if "".join(ans[len(ans) - len(part) :]) == part :
                    ans = ans[:len(ans) - len(part)]
            # print("".join(ans))
        return "".join(ans)