class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        if numerator == 0:
            return "0"
        
        result = ""
        
        if (numerator < 0) ^ (denominator < 0):
            result += "-"
        
        n = abs(numerator)
        d = abs(denominator)
        
        result += str(n // d)
        rem = n % d
        if rem == 0:
            return result  
        
        result += "."
        
        mp = {}  
        while rem:
            if rem in mp:
                index = mp[rem]
                result = result[:index] + "(" + result[index:] + ")"
                break
            mp[rem] = len(result)
            rem *= 10
            result += str(rem // d)
            rem %= d
        
        return result
