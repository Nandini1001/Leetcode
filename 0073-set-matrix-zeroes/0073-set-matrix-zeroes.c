void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
        int col0=1;
        for(int i=0;i<matrixSize;i++)
        {
            for(int j=0;j<*matrixColSize;j++)
            {
                if(matrix[i][j]==0)
                {
                    if(j!=0)
                        matrix[0][j]=0;
                    else
                        col0=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=1;i<matrixSize;i++)
        {
            for(int j=1;j<*matrixColSize;j++)
            {   
                if(matrix[i][j]!=0){ 
                    if(matrix[0][j]==0 || matrix[i][0]==0)
                        matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0)
        {
            for(int i=0;i<*matrixColSize;i++ )
             matrix[0][i]=0;
        }
        if(col0==0)
        {
            for(int i=0;i<matrixSize;i++ )
             matrix[i][0]=0;
        }
}