public class Solution {
    public bool IsValid(string s) {
        var buffer = new char[s.Length];
        int top = 0;
        foreach (var ch in s) {
            switch (ch) {
                case '(':
                    buffer[top++] = ')';
                    break;
                case '[':
                    buffer[top++] = ']';
                    break;
                case '{':
                    buffer[top++] = '}';
                    break;
                default:
                    if (top == 0 || buffer[--top] != ch) return false;
                    break;
            }
        }
        return top == 0;
    }
}