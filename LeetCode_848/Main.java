

// class Solution {
//     public String shiftingLetters(String s, int[] shifts) {
//         long op = 0;
//         char[] chars = s.toCharArray();
//         for (int i = shifts.length - 1; i >= 0; i--) {
//             op += shifts[i];
//             int d = chars[i] - 'a';
//             d = (int)((d + op) % 26);
//             chars[i] = (char)(d + 'a');
//         }
//         return new String(chars);
//     }
// }




public class Main {

    public static void main(String[] args) {
        
    }
}


