class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """

        def str_to_int(s):
            num = 0
            for ch in s:
                num = num * 10 + (int(ch))
            return num

        def parse_version(s):
            version = []
            cur = ""
            for ch in s:
                if ch == '.':
                    version.append(str_to_int(cur))
                    cur = ""
                else:
                    cur += ch
            version.append(str_to_int(cur))
            return version

        v1 = parse_version(version1)
        v2 = parse_version(version2)

        n = max(len(v1), len(v2))
        for i in range(n):
            num1 = v1[i] if i < len(v1) else 0
            num2 = v2[i] if i < len(v2) else 0
            if num1 < num2:
                return -1
            if num1 > num2:
                return 1
        return 0