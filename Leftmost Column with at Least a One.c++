// A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.
// 
// Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. If such index doesn't exist, return -1. 
//  
// You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:
// 
//     BinaryMatrix.get(row, col) returns the element of the matrix at index (row, col) (0-indexed).
//     BinaryMatrix.dimensions() returns a list of 2 elements [rows, cols], which means the matrix is rows * cols.



/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */
// BinaryMatrix.dimensions() 
// BinaryMatrix.get(row, col)
class Solution {
public:
    
    int Helper(BinaryMatrix &binaryMatrix,int row,int start,int end,int index) {
        while(start<=end) {
            int mid=(start+end)/2;
            int val=binaryMatrix.get(row,mid);
            if(val==1 && (mid==0 || binaryMatrix.get(row,mid-1)==0)) {
                return mid;
            }
            else if(val==1)
                end=mid-1;
            else {
                if(mid>index) return INT_MAX;
                start=mid+1;
            }
        }
        return -1;
    }
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> v=binaryMatrix.dimensions();
        int rows=v[0];
        int cols=v[1];
        int index=cols+1;
        for(int row=0;row<rows;row++) {
            if(binaryMatrix.get(row,cols-1)==0)
                continue;
            else {
                int Help_index=Helper(binaryMatrix,row,0,cols-1,index);
                // cout<<Help_index<<" ";
                if(Help_index<index)
                    index=Help_index;
                if(index==0) return 0;
            }
        }
        if(index==cols+1) return -1;
        return index;
        
    }
};
