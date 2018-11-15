/* FILE: sorting_excersize_starter_dave.c
 *
 * Please fill this in with some code to sort. You can use the
 * linear sort algorithm suggested on the Lecture 6 slides
 * or something you learned in a previous course.
 * Good luck!
 *
 * Author: David Meger
 * Date:   Sept 19, 2018
 */

#include <stdio.h>

int main(){

	int array[4] =  {3,1,4,2};


	// Write your code here, try to sort the array
for(int pos=0; pos<3; pos++){
		int val_here = array[pos];
		int min_over_rest = 9999999;
		int min_pos = -1;
		for(int next_pos = pos+1; next_pos <4; next_pos++){
			if(array[next_pos] < min_over_rest){
				min_over_rest = array[next_pos];
				min_pos = next_pos;
			}
		}
		if(min_over_rest < val_here){
			array[min_pos] = val_here;
			array[pos] = min_over_rest;
		}
}
	printf( "The array holds: " );
	for( int i=0; i<4; i++ )
		printf( "%d ", array[i] );

	printf("\n");

	printf( "If you coded it correctly, you should see 1 2 3 4\n");

	return 0;
}
