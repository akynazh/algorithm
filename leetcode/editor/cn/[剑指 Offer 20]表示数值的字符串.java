class Solution {
    public boolean isNumber(String s) {
        if (s == null || s.length() == 0) return false;
        s = s.trim();
        boolean numFlag = false, dotFlag = false, eFlag = false;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch >= '0' && ch <= '9') {
                numFlag = true;
            } else if (ch == '.' && !dotFlag && !eFlag) {
                dotFlag = true;
            } else if ((ch == 'e' || ch == 'E') && numFlag && !eFlag) {
                eFlag = true;
                numFlag = false;
            } else if ((ch == '+' || ch == '-') && (i == 0 || s.charAt(i - 1) == 'e' || s.charAt(i - 1) == 'E')) {

            } else {
                return false;
            }
        }
        return numFlag;
    }
}

//runtime:1 ms
//memory:41.6 MB
