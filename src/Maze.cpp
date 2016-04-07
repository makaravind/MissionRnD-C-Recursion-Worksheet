/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>
#include<malloc.h>
void path(int **maze, int **visited, int rows, int cols, int present_row, int present_col, int prev_row, int prev_col, int x1, int y1, int x2, int y2, int *result);
int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	if (maze == NULL || rows <= 0 || columns <= 0 || x1<0 || x2<0 || y1<0 || y2<0)
		return 0;

	int result = 0;
	int k = 0;// pointer to maze

	// creating visited array for 
	int **visited = (int**)calloc(rows, sizeof(int)*rows);
	for (int j = 0; j < rows; j++){
		visited[j] = (int*)calloc(columns, sizeof(int));
	}
	int **myMaze = (int**)calloc(rows, sizeof(int)*rows);
	for (int j = 0; j < rows; j++){
		myMaze[j] = (int*)calloc(columns, sizeof(int));
	}

	// giving vals to myMaze
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++){
			myMaze[i][j] = maze[k++];
		}
	visited[x1][y1] = 1;
	path(myMaze, visited, rows - 1, columns - 1, x1, y1, -1, -1, x1, y1, x2, y2, &result);
	return result;
}
void path(int **maze, int **visited, int rows, int cols, int present_row, int present_col, int prev_row, int prev_col, int x1, int y1, int x2, int y2, int *result){

	int check_row;
	int check_col;
	char go = '\0';
	int prevr = -1;
	int prevc = -1;
	//east
	check_col = present_col + 1;
	check_row = present_row;
	if (check_col < cols + 1){
		if (!visited[check_row][check_col] && maze[check_row][check_col]){
			visited[check_row][check_col] = 1;
			prevr = check_row;
			prevc = check_col;
			if (check_row == x2 && check_col == y2){
				*result = 1;
				return;
			}
			go = 'e';
		}

	}

	if (go == '\0'){
		// go west
		check_col = present_col - 1;
		check_row = present_row;
		if (check_col > -1 && check_col <= cols){

			if (present_row == -1 && present_col == -1 || !visited[check_row][check_col] && maze[check_row][check_col]){
				visited[check_row][check_col] = 1;
				if (check_row == x2 && check_col == y2){
					*result = 1;
					return;
				}
				go = 'w';
			}
		}

	}
	if (go == '\0'){
		// go north
		check_col = present_col;
		check_row = present_row - 1;
		if (check_row > -1 && check_row <= rows){

			if (present_row == -1 && present_col == -1 || !visited[check_row][check_col] && maze[check_row][check_col]){
				visited[check_row][check_col] = 1;
				if (check_row == x2 && check_col == y2){
					*result = 1;
					return;
				}
				go = 'n';
			}
		}

	}
	if (go == '\0'){
		// go south
		check_col = present_col;
		check_row = present_row + 1;
		if (check_row > -1 && check_row <= rows){

			if (!visited[check_row][check_col] && maze[check_row][check_col]){
				visited[check_row][check_col] = 1;
				if (check_row == x2 && check_col == y2){
					*result = 1;
					return;
				}
				go = 's';
			}
		}

	}
	if (go != '\0'){
		path(maze, visited, rows, cols, check_row, check_col, prevr, prevc, x1, y1, x2, y2, result);
	}
}