package interview.dji;

import java.util.Scanner;

class Solution {

    /* Write Code Here */
    public int calculateMaxTotalYie1(int[][] cropField) {
        int total = 0;
        for (int[] vals : cropField) {
            for (int val : vals) {
                total += val;
            }
        }
        int mmax = total;
        int row = cropField.length, col = cropField[0].length;
        for (int i = 0; i < row; i++) {
            int cur = total;
            for (int j = 0; j < col; j++) {
                cur += cropField[i][j];
            }
            for (int j = 0; j < col; j++) {
                int tmpCur = cur;
                for (int k = 0; k < row; k++) {
                    if (k != i) {
                        tmpCur += cropField[k][j];
                    }
                }
                if (tmpCur > mmax) mmax = tmpCur;
            }
        }
        return mmax;
    }

    public int calculateMaxTotalYie(int[][] cropField) {
        int total = 0;
        int row = cropField.length, col = cropField[0].length;
        int[] rowVal = new int[row];
        int[] colVal = new int[col];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                total += cropField[i][j];
                rowVal[i] += cropField[i][j];
            }
        }
        int mmax = total;

        for (int j = 0; j < col; j++) {
            for (int i = 0; i < row; i++) {
                colVal[j] += cropField[i][j];
            }
            for (int i = 0; i < row; i++) {
                mmax = Math.max(mmax, total + rowVal[i] + colVal[j] - cropField[i][j]);
            }
        }
        return mmax;
    }
}

public class Main {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int res;

        int cropField_rows = 0;
        int cropField_cols = 0;
        cropField_rows = in.nextInt();
        cropField_cols = in.nextInt();

        int[][] cropField = new int[cropField_rows][cropField_cols];
        for(int cropField_i=0; cropField_i<cropField_rows; cropField_i++) {
            for(int cropField_j=0; cropField_j<cropField_cols; cropField_j++) {
                cropField[cropField_i][cropField_j] = in.nextInt();
            }
        }

        if(in.hasNextLine()) {
            in.nextLine();
        }


        res = new Solution().calculateMaxTotalYie(cropField);
        System.out.println(String.valueOf(res));

    }
}
