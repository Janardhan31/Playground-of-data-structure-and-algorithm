class Solution:
    def isPalindrome(self, x: int) -> bool:
        dummy = x
        if x<0:
            return False
        m = 0
        while x>0:
            rem=x%10
            m = m*10+rem
            x = x//10
        return m==dummy