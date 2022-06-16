class Solution {
public:
    bool linearSearch(vector<int> arr,int &idx) //to search whether 0 is present or not
    {
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i] == 0)
            {
                idx = i; // to store the index of first 0 in row matrix
                return true;
            }
        }
        return false;
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        int idx = -1; 
        for(int i=0;i<matrix.size();i++)
        {
            if(linearSearch(matrix[i],idx) == true) // if 0 is present 
            {
                int j = 0;
                while(j < matrix[0].size())
                {
                    if(matrix[i][j] == 0) //after first 0, if any other 0 is present in row matrix, then we will update the idx.
                    {
                        idx = j;
                    }
                    if(j == idx)
                    {
                        int k = i;
                        while(k > 0) // here, we are updating previous rows element to 0 when current row element is 0.
                        {
						    // for example: if matrix is 2 3 4
							//                           1 0 5 then after this while loop our matrix will look like 
							// 2 0 4
							// 1 0 5
                            k--;                              
                            matrix[k][j] = 0;
                        }
                        k = i;
                        while(k < matrix.size()) // now, we will change the values of those elements which comes in the next row
                        {
						// eg:
						// 2 3 4
						// 1 0 5
						// 7 8 6
						
						// after this loop
						
						// 2 3 4
						// 1 0 5
						// 7 -1 6
                            if(matrix[k][j] != 0)
                            {
                                matrix[k][j] = -1;  // here we are just mapping those elements which are below 0 and changing them to -1.
                            }
                            k++;
                        }
                    }
                    matrix[i][j] = 0; // changing whole row to 0
                    j++;
                }
            }
            else if(idx != -1) // if there exist no element which is equal to 0
            {
                int j = 0;
                while(j < matrix[0].size())
                {
                    if(matrix[i][j] == -1) // all those elements which are below 0, we will change them to 0 also
                    {
                        matrix[i][j] = 0;
                    }
                    j++;
                }
            }
        }
    }
};









class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        bool rowFlag= false;
        for(int i=0; i< matrix.size(); i++)
        {
            if(matrix[i][0]== 0)
            {
                rowFlag= true;
            }
        }
        bool colFlag= false;
        for(int j=0; j< matrix[0].size(); j++)
        {
            if(matrix[0][j]== 0)
            {
                colFlag= true;
            }
        }
        for(int i=1; i< matrix.size(); i++)
        {
            for(int j=1; j< matrix[i].size(); j++)
            {
                if(matrix[i][j]== 0)
                {
                    matrix[0][j]= 0;
                    matrix[i][0]= 0;
                }
            }
        }
        for(int i=1; i< matrix.size(); i++)
        {
            for(int j=1; j< matrix[i].size(); j++)
            {
                if(matrix[0][j]== 0 || matrix[i][0]== 0)
                {
                    matrix[i][j]= 0;
                }
            }
        }
        if(rowFlag)
        {
            for(int i=0; i< matrix.size(); i++)
            {
                matrix[i][0]= 0;
            }
        }
        if(colFlag)
        {
            for(int j=0; j< matrix[0].size(); j++)
            {
                matrix[0][j]= 0;
            }
        }
        return;
    }
};
