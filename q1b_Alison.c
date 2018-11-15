#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//This method prints out the space at the beginning and end of the triangle
int printSpace(int y, int height, int level){

    //get the height of the triangle
    double tri_height = ceil(height/2.0);

    //use a for loop to print out spaces
    for(int x = 0; x < tri_height/2; x++){
        printf(" ");
    }
    return 1;

}

//this method draws out the triangles
int printTriangle(int y, int height, int level){

    //get the height of the triangle
    double tri_height = ceil(height/2.0);

    //draw the triangle out if the level is 1
    if(level == 1){
        for(int x = 0; x < height; x++){
            if(x >= tri_height-y-1 && x <= tri_height+y-1){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        return 1;
    }

    //if we are in the top half of the triangle, one triangle and space on either side of it
    else if(y < tri_height/2){
        printSpace(y, height, level);
        printTriangle(y, height/2, level-1);
        printSpace(y, height, level);
    }
    //otherwise, print 2 triangles with a space between them
    else{
        printTriangle(y-tri_height/2, height/2, level- 1);
        printf(" ");
        printTriangle(y-tri_height/2, height/2, level - 1);
    }
    return 1;

}

int main(int argc, char* argv[]){

    //print out an error statement if there is more than one argument.
    if(argc != 3){
        printf("ERROR: Wrong number of arguments. 2 required.\n");
        return -1;
    }

    //Convert the first argument from a string into an integer.
    //This is the height of the diamond.
    int height = atoi(argv[1]);

    //Convert the second argument from a string into an integer.
    //This is the fractal level of the diamond
    int level = atoi(argv[2]);

    //Get the height of the triangle. Put 2.0 to avoid integar division.
    double tri_height = ceil(height/2.0);

    //print out an error statement if the first argument is even or negative.
    if (height%2 == 0 || height <= 0){
        printf("ERROR: Bad argument. Height must be positive odd integer.\n");
        return -1;
    }

   //print out an error statement if the height isn't a power of 2 or if it isn't greater that 2^(level -1)
    if ((int)log2(tri_height) < log2(tri_height) || tri_height < pow(2,level - 1)){
        printf("ERROR: Height does not allow evenly dividing requested number of levels.\n");
        return -1;
    }
    //print the rightsideup triangle
    for(int y = 0; y < tri_height; y++){
        printTriangle(y, height, level);
        printf("\n");
    }

    //print the upsidedown triangle
    for(int y = tri_height-2; y >= 0; y--){
        printTriangle(y, height, level);
        printf("\n");
    }

}
