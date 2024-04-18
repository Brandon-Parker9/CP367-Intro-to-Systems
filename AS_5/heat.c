/*
 * heat.c
 *
 *  Created on: 2011-01-08
 */
#include <stdio.h>

int main() {
  int height = 0; // height of a tree in feet
  int radius = 0; // radius of a tree in feet
  int requirement = 0; //cubic fee of wood to heat house for one day
  int volume = 0; // volume of the tree in cubic feet
  int days = 0; // number of days tree will heat house
  double PI = 3.1416; // value of pi
  // Input.
  printf("How tall is the tree (ft): ");
  scanf(" %d", &height);
  printf("Radius of the tree (ft): ");
  scanf(" %d", &radius);
  printf("Wood to heat house for one day (ft^3): ");
  scanf(" %d", &requirement);
  // Computations.
  volume = height * radius * radius * PI;
  days = volume / requirement;
  printf("Volume: %d ft^3\n", volume);
  printf("Days: %d\n", days);
  return 0;
}