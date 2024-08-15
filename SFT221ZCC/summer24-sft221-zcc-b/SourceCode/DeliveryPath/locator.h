#ifndef LOCATOR_H
#define LOCATOR_H

// Author: Abdullah Al Mahfuz
struct Truck {
	int weight; // Weight in truck
	double volume; // Volume in truck
	struct Route* path; // The route of the truck (by Isabela)
};

struct Shipment {
	int s_weight; // Shipment weight, from: 1 - 2500kg
	int s_boxSize;  // Valid box sizes: 1, 3, 5 cubic meters
	// Type changed by Isabela for better convenience
	struct Point destination; // Shipment destination
};

#endif 