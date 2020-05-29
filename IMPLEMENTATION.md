# Sudoku Implementation.md
## May 2020

### Detailed Psuedocode

isValid:
Notes: The indices are indexed 0-80, the columns and rows 0-8, and the boxes rows/columns 0-2. 

1. divide the index by 9 (integer division) and then multiply it by 9 to get the first index in the given number's row
    * start at that index, and keep adding 1 each time
        * if any of the numbers are the same as the given number, return false
2. take the index modulo 9 to get the first index in the given number's column 
    * start at that index, adding 9 each time
        * if the number at that index matches the given number, return false
3. get the row number (index/9) and column number (index % 9)
4. get the box row + column number by dividing each of the above by 3
5. the top left index in each box is (box_row * 27) + (box_col * 3)
6. starting at the top left index in each box, loop over each number in the box
    * if any are the same as the given number, return false
7. return true


### Data Structures

### Error Handling
