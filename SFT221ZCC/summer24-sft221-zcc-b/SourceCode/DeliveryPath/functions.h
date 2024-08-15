#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "mapping.h"
#include "locator.h"

#define MIN_WEIGHT 1
#define MAX_WEIGHT 2500
#define MAX_VOLUME 100

// Author: Isabela Bulla

/*
NAME: printTitle
Description: Prints the title of the application
Parameters: None
Returns: Void 
*/
void printTitle();

/*
NAME: getUserInput
Description: Gets the user input for the weight, box size and destination of
the shipment. Parses the input to the according variables and calls the validation
functions to validate the input. If the input is valid, it calls the functions to
 choose truck line and determine diversion.
Parameters: shipment – a data structure containing the size, weight and destination of the
shipment.
Returns: Void 
*/
void getUserInput(struct Shipment* shipment, struct Truck trucks[]);

/*
NAME: validVolume
Description: Validates the volume entered by the user. Makes sure it is either 1,
3 or 5. Returns 1 if the input was valid and 0 if it was not valid.
Parameters:
• shipment – a data structure containing the size, weight and destination of the
shipment.
• boxVolume – a variable storing the user input for the volume.
Returns: An integer representing a flag variable that indicates if the input was valid.
*/
int validVolume(struct Shipment* shipment, int boxVolume);

/*
NAME: validWeight
Description: Validates the weight entered by the user. It guarantees that it is between
1kg and 2500kg. Returns 1 if the input was valid and 0 if it was not valid.
Parameters:
• shipment – a data structure containing the size, weight and destination of the
shipment.
• weight – a variable storing the user input for the weight.
Returns: An integer representing a flag variable that indicates if the input was valid.
*/
int validWeight(struct Shipment* shipment, int weight);

/*
NAME: validDestination
Description: Determines if the destination selected by the user is valid. Meaning it
is within the map boundaries, it is a building and it is accessible. An accessible point
in the map is identified by a point that has an empty space either above it, below it,
to it's left or to it's right.
Parameters:
• Map – the map of the delivery area with buildings on it.
• shipment – a data structure containing the size, weight and destination of the
shipment.
• row – a variable storing the user input for the row of the destination.
• col – a variable storing the user input for the column of the destination.
Returns: An integer representing a flag variable that indicates if the input was valid.
*/
int validDestination(struct Map map, struct Shipment* shipment, int row, char col);

/*
NAME: chooseTruckLine
Description: Finds the best truck for a shipment. It considers both the load on the truck,
the size and weight of the shipment, and the route of the truck to try to place it on a
truck which goes closest to the destination. It prints the name of the route that the truck
will follow to deliver the shipment. If there is no truck that can deliver the
shipment, it returns -1. Also determines the diversion needed to properly deliver the shipment.
Parameters:
• Map – the map of the delivery area with buildings on it.
• shipment – a data structure containing the size, weight and destination of the shipment.
• trucks – an array of trucks including the route for each of the trucks.
• numTrucks – the number of trucks in the array of trucks.
Returns: An integer that indicates if a truck was found. It returns 0 if the truck
was found and -1 if it wasn't.
*/
int chooseTruckLine(const struct Map* map, struct Shipment* shipment, struct Truck trucks[], int numTrucks);

/*
NAME: compareTrucks
Description: Determines the difference between two trucks based on the percentage of space left in 
each truck. Returns 1 if the left truck has more space, -1 if the right truck has more space 
and 0 if they have the same space left.;
Parameters:
• leftTruck – a data structure containing the weight, volume and route of the truck.
• rightTruck – a data structure containing the weight, volume and route of the truck.
Returns: An integer that indicates the difference between the trucks.
*/
int compareTrucks(struct Truck* leftTruck, struct Truck* rightTruck);

/*
NAME: canCarry
Description: Determines if the truck can carry the shipment. It makes the analyzes based on the
weight and volume being carried by the truck. It returns 0 if the shipment can't be carried and
1 if the shipment can be carried.;
Parameters:
• shipment – a data structure containing the size, weight and destination of the shipment.
• truck – a data structure containing the weight, volume and route of the truck.
Returns: An integer that indicates if the truck can carry the shipment or not.
*/
int canCarry(const struct Truck* truck, const struct Shipment* shipment);

/*
NAME: convertPoint
Description: Converts a point into printable values.;
Parameters:
• Point – a structure containing a point.
• col - a char array that is going to store the column.
Returns: An integer cointaining the row.
*/
int convertPoint(struct Point* point, char* col);

/*
NAME: printDiversion
Description: It prints the diversion point by point, including the beginning point and the destination point.
In case of no diversion it prints no diversion. If it couldn't determine a diversion,
it returns -1;
Parameters:
• Route – the route incluiding the diversion to be printed.
Returns: An integer that indicates if the function executed with no errors.
*/
int printDiversion(struct Route* diversion);

#endif // !FUNCTIONS_H
