class Solution {
    public boolean ok(char ch) {
        return (ch >= '0' && ch <= '9') ||
               (ch >= 'a' && ch <= 'z') ||
               (ch >= 'A' && ch <= 'Z');
    }

    public boolean isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }

    public boolean isValid(String word) {
        if (word.length() < 3) return false;

        boolean vowel = false, consonant = false;

        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);

            if (!ok(ch)) return false;

            if (isVowel(ch)) {
                vowel = true;
            } else if (!(ch >= '0' && ch <= '9')) {
                consonant = true;
            }
        }

        return vowel && consonant;
    }
}


public class Main {
    public static void main(String[] args) {
        
    }
}
