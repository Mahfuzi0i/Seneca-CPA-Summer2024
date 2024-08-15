#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"

// Author: Isabela Bulla

void printTitle() {
	printf("=================\n");
	printf("Seneca Polytechnic Deliveries\n");
	printf("=================\n");
}

void getUserInput(struct Shipment* shipment, struct Truck trucks[]) {

	int done = 0; // Flag variable to detect: 0 0 x
	int valid = 0; // Assume input is not valid!
	char input[50]; // Buffer to store the user input

	struct Map map = populateMap();

	while (!done) {

		// Request user input:
		printf("Enter shipment weight, box size and destination (0 0 x to stop): ");
		fgets(input, sizeof(input), stdin); // Read the entire line

		// Check if user entered 'x' for destination:
		if (strcmp(input, "0 0 x\n") == 0) {
			printf("Thanks for shiping with Seneca Polytechnic!\n");
			putchar('\n');
			done = 1;
		}
		else {
			// Parse the input and validate:
			int weight, boxVolume, destRow;
			char destCol;
			if (sscanf(input, "%d %d %d%c", &weight, &boxVolume, &destRow, &destCol) != 4) {
				printf("Invalid input format. Please enter three values separated by spaces.\n");
			}
			else if (!validWeight(shipment, weight)) {
				printf("Invalid weight (must be %d-%d Kg.)\n", MIN_WEIGHT, MAX_WEIGHT);
			}
			else if (!validVolume(shipment, boxVolume)) {
				printf("Invalid size\n");
			}
			else if (!validDestination(map, shipment, destRow, destCol)) {
				printf("Invalid destination\n");
			}
			else {

				chooseTruckLine(&map, shipment, trucks, 3);
			}
		}
	}
}

int validVolume(struct Shipment* shipment, int boxVolume) {

	int result = 0; // Assume weight is invalid!

	if (boxVolume == 1 || boxVolume == 3 || boxVolume == 5) {

		// Store valid volume:
		shipment->s_boxSize = boxVolume;

		result = 1;
	}

	return result;
}

int validWeight(struct Shipment* shipment, int weight) {

	int result = 0; // Assume weight is invalid!

	if (weight <= MAX_WEIGHT && weight >= MIN_WEIGHT) {

		// Store valid weight:
		shipment->s_weight = weight;

		result = 1;
	}

	return result;
}

int validDestination(struct Map map, struct Shipment* shipment, int row, char col) {

	int valid = 0; // Assume destination is invalid!

	// Convert row to 0 - 24 based index:
	int rowIndex = row - 1;
	// Convert col to 0-24 based index:
	int colIndex = tolower(col) - 'a';

	// Check if destination is within the map:
	if (rowIndex >= 0 && rowIndex < MAP_ROWS
		&& colIndex >= 0 && colIndex < MAP_COLS) {

		// Check if it is a building:
		if (map.squares[rowIndex][colIndex] == 1) {

			// Check if there is an empty space above, below, to the right
			// or to the left:
			if ((map.squares[rowIndex - 1][colIndex] != 1) && (rowIndex - 1) >= 0) {
				valid = 1;
			}
			else if ((map.squares[rowIndex + 1][colIndex] != 1) && (rowIndex + 1) >= 0 && (rowIndex + 1) < MAP_ROWS) {
				valid = 1;
			}
			else if ((map.squares[rowIndex][colIndex - 1] != 1) && (colIndex - 1) >= 0) {
				valid = 1;
			}
			else if ((map.squares[rowIndex][colIndex + 1] != 1) && (colIndex + 1) >= 0 && (colIndex + 1) < MAP_COLS) {
				valid = 1;
			}

			if (valid == 1) {

				//Store valid destination:
				shipment->destination.row = rowIndex;
				shipment->destination.col = colIndex;
			}
		}
	}

	return valid;
}

int chooseTruckLine(const struct Map* map, struct Shipment* shipment, struct Truck trucks[], int numTrucks) {

	int i, j; // Variables for FOR iteration
	int closestTruckIndex = -1; // Set to an index that doesn't exist!
	int shortestRoute = -1;
	struct Route tempRoute = { {0,0}, 0,0 };
	struct Route diversion = { {0,0}, 0,0 };
	

	// Loop thorugh all the trucks:
	for (i = 0; i < numTrucks; i++) {

		// Check if the truck can carry this shipment:
		if (canCarry(&trucks[i], shipment)) {

			// Loop thorugh all the points in the truck's route and
			// find the one closest to the destination:
			for (j = 0; j < trucks[i].path->numPoints; j++) {

				tempRoute = shortestPath(map, trucks[i].path->points[j], shipment->destination);

				// Find the truck with the shortest diversion:
				if (shortestRoute < 0 || tempRoute.numPoints > 0 && (tempRoute.numPoints < shortestRoute)) {

					shortestRoute = tempRoute.numPoints;
					closestTruckIndex = i;
					diversion = tempRoute;
				} 
				// If both trucks have the same route length:
				else if (tempRoute.numPoints > 0 && tempRoute.numPoints == shortestRoute) {
					if (closestTruckIndex != i && compareTrucks(&trucks[i], &trucks[closestTruckIndex]) < 0) {

						shortestRoute = tempRoute.numPoints;
						closestTruckIndex = i;
						diversion = tempRoute;
					}
				}
			}
		}
	}

	if (closestTruckIndex != -1) {

		switch (closestTruckIndex) {
		case 0:
			printf("Ship on BLUE LINE, ");
			break;
		case 1:
			printf("Ship on GREEN LINE, ");
			break;
		case 2:
			printf("Ship on YELLOW LINE, ");
			break;
		}
	}

	if (closestTruckIndex >= 0 && closestTruckIndex < numTrucks) {
		
		trucks[closestTruckIndex].weight += shipment->s_weight;
		trucks[closestTruckIndex].volume += shipment->s_boxSize;

		printDiversion(&diversion);
	}
	else {
		printf("Ships tomorrow.\n");
	}

	return closestTruckIndex;
}

int compareTrucks(struct Truck* leftTruck, struct Truck* rightTruck) {
	int result = 0; // Assume trucks are equal!
	double leftSpace, rightSpace;

	leftSpace = (leftTruck->weight / leftTruck->volume) * 100;
	rightSpace = (rightTruck->weight / rightTruck->volume) * 100;

	// result is 1 if the left truck is greater than right truck (i.e. 1st truck > 2nd truck)
	if (leftSpace > rightSpace) {
		result = 1;	
	}
	// result is -1 if the right truck is greater than left truck (i.e. 1st truck < 2nd truck)
	else if(rightSpace > leftSpace) {
		result = -1;
	}
	else
	{
		result = 0;
	}

	return result;
}

int canCarry(const struct Truck* truck, const struct Shipment* shipment) {

	int result = 0; // Assume truck cannot carry the shipment!

	if ((truck->weight + shipment->s_weight <= MAX_WEIGHT) &&
		(truck->volume + shipment->s_boxSize <= MAX_VOLUME)) {

		result = 1; // Truck can carry the shipment!
	}

	return result;
}

int convertPoint(struct Point* point, char* col) {

	int tempRow = -1; // return the row

	col[0] = 0; // Reset column

	tempRow = point->row + 1;

	col[0] = 'A' + point->col; // return the column using the array

	return tempRow;
}

int printDiversion(struct Route* diversion) {

	int i;
	int row = -1;
	char col[1];

	if (diversion->numPoints > 2) {

		printf("divert: ");

		for (i = 0; i < diversion->numPoints; i++) {

			row = convertPoint(&diversion->points[i], col);
			printf("%d%c", row, col[0]);

			if (i == (diversion->numPoints - 1)) {
				printf("\n");
			}
			else {
				printf(", ");
			}
		}
	}
	else
	{
		printf("no diversion\n");
	}

	return 0;
}