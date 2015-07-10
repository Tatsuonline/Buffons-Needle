#include <stdio.h> //Standard input, output header
#include <stdlib.h> //Standard library header
#include <math.h> //Math header (remember to include -lm for gcc!)
#include <time.h> //Time header (random number generator is based on time)
#define PI 3.14159265 //Required length of Pi for random angle generator in radians
#define NEEDLE_LENGTH 1 //Length of needle set arbitrarily as one unit

int main()
{
  float closestLineDistance; //Distance between center of needle and vertical line (provided by file)
  float crossingAngle; //The angle at which the needle crosses the vertical line
  float verticalLineSpacing; //The spacing in between the vertical lines
  int linesCrossed = 0; //A counter to determine the number of lines crossed
  int needlesDropped = 0; //A counter to determine the number of needles dropped
  float approximatePiValue; //The calculated approximate value of Pi
  float crossChecker; //A variable used to determine if the needle crosses a vertical line
  int needleDropSample = 0; //The (user determined) number of needles to be dropped

  FILE * filepointer; //A pointer to the file
  srand (time(NULL)); //Initializes the random number generator
  verticalLineSpacing = (2 * NEEDLE_LENGTH); //Sets the vertical line spacing as twice the length of the needles
  
  printf("\n\nEnter the number of needles you wish to drop: "); //The (user determined) number of needles to be dropped
  scanf("%d", &needleDropSample);
  filepointer = fopen("rn_GNUC.txt", "r"); //Opens the file in "r" <- read mode
  
  while(needlesDropped < needleDropSample) //While not at the end of the file
  {
    fscanf(filepointer, "%e", &closestLineDistance); //Reads the data in scientific notation format
    needlesDropped++; //Essentially counts the data input
    crossingAngle = (PI/2.0) * ((float)rand() / (float)RAND_MAX); //Chooses a random angle between 0 and 90 degrees
    crossChecker = (NEEDLE_LENGTH / 2.0)*sinf(crossingAngle); //A variable used to determine if the needle crosses a vertical line
    
    if(closestLineDistance <= crossChecker) //Determines if the vertical line is crossed
    {
      linesCrossed++; //Increments the number of lines crossed
    }
  }
  
  fclose(filepointer); //Closes the pointer to the file
  approximatePiValue = (2 * NEEDLE_LENGTH * needlesDropped)/(verticalLineSpacing * linesCrossed); //Formula to determine Pi
  
  printf("\n\nThe number of needles dropped were: %d", needlesDropped); //Try to pick a large values
  printf("\n\nThe number of lines crossed were: %d", linesCrossed); //Not necessary, but interesting to know
  printf("\n\nThe approximate value of Pi based on the above data is: %f\n\n", approximatePiValue); //The value obviously tends to vary, but is fairy accurate
  return 0;
}
