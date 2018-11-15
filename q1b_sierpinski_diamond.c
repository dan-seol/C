#include <stdio.h>
#include <stdlib.h> // Used for atoi() function
#include <string.h> // Used for strlen() function
#include <math.h>
int power2(int m){
  if(m==0){
    return 1;
  } else if (m < 0) { // positive integer assumes
    printf("This function is defined for nonnegative integers only");
    return -1;
  } else {
    return 2*power2(m-1);
  }

}
double t_h(int height){
  return ceil(height/2.0);
}
//method attempted but failed
//*void line(int n, int m){
//  for(int i=0; i<n; i++){
//    if((n/2)-(m) < i && i <= n/2){
//      printf("*");
//    } else if(n/2< i && i  < (n/2 +m) ){
//      printf("*");
//    } else {
//      printf(" ");
//    }
//  }

//}

//Watched the hint video & Changed the approach: Print Sierpinski's triangle first, and then build upon it.
void whiteSp(int m, int h, int l){
  double th = t_h(h);
  for(int i=0; i< th/2; i++){
    printf(" ");
}
}
void Tr(int m, int h, int l){
  double th = t_h(h);
  if(l == 1){
    for(int i =0; i<=h-1; i++){
        int b1 = i > th-m-2;
        int b2 = i < th+m;

      if(b1 && b2){

        printf("*");

      } else {

        printf(" ");
      }
    }
  } else if(m < th/2){
    //On top of the triangle
    whiteSp(m, h, l);
    Tr(m, h/2, l-1);
    whiteSp(m, h, l);
  } else {
    //At the bottom of the triangle!
    Tr(m-th/2, h/2, l-1);
    printf(" ");
    Tr(m-th/2, h/2, l-1);
  }
}

void TrFlipped(int h, int l){
  double th = t_h(h);
  for(int j = th-2; j >= 0; j--){
      Tr(j, h, l);
      printf("\n");
}
}




void sierpinski(int h, int l){
    double th = t_h(h);
    int powerof2 = log2(th) - (int)log2(th) == 0;
    int heightref = power2(l-1);


    if(!powerof2 || th < heightref){
      printf("ERROR: Height does not allow evenly dividing requested number of levels.");

    } else {
      for(int i = 0; i < th; i++){
          Tr(i, h, l);
          printf("\n");
      }
      TrFlipped(h, l);

  }
}

int main(int argc, char *argv[])
{

    //case separated when there are zero arguments
    if( argc > 3 ) {
         printf("ERROR: Wrong number of arguments. One required\n");
         return 1;
       }
       else if (argc < 3){
         printf("ERROR: Wrong number of arguments. One required\n");
         return 1;
       } else {

         int n = (int) atoi(argv[1]);
         int m = (int) atoi(argv[2]);
         if(n % 2 == 0  ){
           printf("ERROR: Bad argument. Height must be positive odd integer \n");
           return 1;
         }

         printf("%d\n", n);
         sierpinski(n, m);
         return 0;


    }

}
