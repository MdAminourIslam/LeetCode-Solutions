def is_opening(bracket):
    return bracket in '([{'

def is_matching(opening, closing):
    return (opening == '(' and closing == ')') or \
           (opening == '[' and closing == ']') or \
           (opening == '{' and closing == '}')

class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        for bracket in s:
            if is_opening(bracket):
                stack.append(bracket)
            else:
                if stack and is_matching(stack[-1], bracket):
                    stack.pop()
                else:
                    return False
        return len(stack) == 0