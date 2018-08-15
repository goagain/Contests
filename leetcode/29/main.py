class Solution:
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        sign = 1
        if dividend < 0:
            sign = sign * -1
            dividend = -dividend
        if divisor < 0:
            sign = sign * -1
            divisor = divisor * -1
        ret = 0
        bit = 32
        while bit >= 0:
            if dividend >= (divisor << bit):
                dividend = dividend - (divisor << bit)
                ret = ret + (1 << bit)
            bit = bit - 1
        ret = ret * sign
        if ret > (1 << 31) - 1 or ret < (-1 << 31):
            return (1 << 31)-1
        return ret 


print(Solution().divide(-2147483648, -1))
