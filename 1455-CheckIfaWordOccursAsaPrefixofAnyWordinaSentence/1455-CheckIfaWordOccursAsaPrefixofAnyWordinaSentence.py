class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        words = sentence.split()
        ans = 0
        for w in words :
            ans += 1
            if len(searchWord) > len(w) :
                continue 
            if(w[:len(searchWord)] == searchWord) :
                return ans

        return -1