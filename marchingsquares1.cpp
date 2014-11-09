#define N_X 512      // size of the array i.e the pixels of the image     
#define N_Y 512
#include <stdio.h>

double data[N_X][N_Y];                             // Array to hold function values (a,b,c,d) at corners of each cell 
int cell(double a, double b, double c, double d);  //the function to determine the type of the cell
double bitmesh(double x, double y);                //function to generate the bit map.
void lines(int , int, int, double, double, double, double); //function to draw lines
void mainLoop();

void mainLoop(){
          
        for(int i = 0; i < N_X; i++)
	 for(int j = 0; j < N_Y; j++)
	   data[i][j] = bitmesh(i, j);//getting the data at the paricular co-ordinate using the bitmesh() and storing it in a different array
         for(int i = 0; i < N_X - 1; i++){
		for(int j = 0; j < N_Y - 1; j++){
			int c = cell(data[i][j], data[i+1][j], data[i][j+1], data[i+1][j+1]);  // returns the cell type
			lines(c,i,j, data[i][j], data[i+1][j], data[i][j+1], data[i+1][j+1]);  // draw correct line
                   }}//this loop finds out the type of the cell and calls a function to draw the required type of line
               }

int cell(double a, double b, double c, double d)  // returns the cell type taking the cell values as inputs
{
	int n,h=0; 
	if (a > h) n+=1;  
	if (b > h) n+=8;
	if (c > h) n+=4;
	if (d > h) n+=2;
	return n;
}

double bitmesh(double i, double j){
//need to threshold the image and genrate the binary values using this



}


void lines_adjacent(int n, int i, int j, double a, double b, double c, double d){
	double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	switch(n){
		case 1:
		case 14:	        x1 = i;
					y1 = j + 0.5;
					x2 = i + 0.5;
					y2 = j + 1;
					break;
		case 4:
		case 11: 	        x1 = i + 0.5;
					y1 = j + 1;
					x2 = i + 1;
					y2 = j + 0.5;
					break;
		case 2:
		case 13: 	        x1 =  i + 0.5;
					y1 = j ;
					x2 = i ;
					y2 = j + 0.5;
					break;
		case 7:
		case 8: 	        x1 = i + 1;
					y1 = j + 0.5;
					x2 = i + 0.5;
					y2 = j + 1;
					break;
	      }
            }                    // function which handles the lines which are coming from the vertices of the adjacent sides of square


void lines_opposite(int n, int i, int j, double a, double b, double c, double d){
	double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	switch(n){
		case 3:
		case 12:	        y1 = j + 0.5;
					x1 = i;
					y2 = j + 0.5;
					x2 = i + 1;
					break;
		case 6:
		case 9:		
					y1 = j + 0.5;
					x1 = i;
                                        x2 = i + 1;
					y2 = j + 0.5;
					break;
	}
	}  

void lines(int n, int i, int j, double a, double b, double c, double d) // Draw the correct line
{
   // n is cell type (0-15)
   // i,j specifes which cell
   // a,b,c,d are function values at cell corners (from data array)
	switch(n){
		case 1:
		case 2:
		case 4:
		case 7:
		case 8:
		case 11:
		case 13:
		case 14:	
					lines_adjacent(n, i, j, a, b, c, d);
					break;
		case 3:
		case 6:
		case 9:
		case 12:	        
                                        lines_opposite(n, i, j, a, b, c, d);
					break;
		case 0:
		case 15:	break; // ambiguity cases
		default:
		break; 
	}
}



int main( int argc , char **argv)
{
//mainLoop();




}
