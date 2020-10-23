#include <stdio.h>
#include <stdlib.h>
#define FAIL 1
//Free Allocated memory
void freeAllocatedMemory(int **arr, int nRow)
{
    int iRow = 0;
    for (iRow =0; iRow < nRow; iRow++)
    {
        free(arr[iRow]); // free allocated memory of each row
    }
    free(arr);  // free allocate the array
}
int main(int argc, char *argv[])
{
    int **arr = NULL; //pointer to pointer
    int nRow = 0; //variable store number of Row
    int nColumn = 0; //variable store number of Row
    int iRow = 0; //Variable for looping Row
    int iCol = 0; //Variable for looping column
    printf("\nEnter the number of Row = ");
    scanf("%d",&nRow); //Get input for number of Row
    printf("\nEnter the number of Column = ");
    scanf("%d",&nColumn); //Get input for number of Column
    
arr = (int **)malloc(nRow * sizeof(int*));
    //Check memory validity
    if(arr == NULL)
    {
        return FAIL;
    }
    //Allocate memory for column
    for (iRow =0 ; iRow < nRow ; iRow++)
    {
        arr[iRow] = (int *)malloc(nColumn * sizeof(int));
        //Check memory validity
        if(arr[iRow] == NULL)
        {
            freeAllocatedMemory(arr,iRow);
            return FAIL;
        }
    }
    //Get input data in 2d Array
    for (iRow =0 ; iRow < nRow ; iRow++)
    {
        for (iCol =0 ; iCol < nColumn ; iCol++)
        {
	    printf("\nEnter the value for [%d][%d] : ",iRow,iCol);
	    scanf("%d",&arr[iRow][iCol]);
         }
    }
    //Print the content of 2D array
    for (iRow =0 ; iRow < nRow ; iRow++)
    {
	for (iCol =0 ; iCol < nColumn ; iCol++)
	{
	    printf("\narr[%d][%d] = %d\n",iRow, iCol,arr[iRow][iCol]);
	}
    }
    freeAllocatedMemory(arr,nRow);
    return 0;
}
