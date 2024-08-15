#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "functions.h"

int main(void)
{
	struct Map baseMap = populateMap();
	struct Route blueRoute = getBlueRoute();
	struct Route greenRoute = getGreenRoute();
	struct Route yellowRoute = getYellowRoute();

	const struct Map routeMap = addRoute(&baseMap, &blueRoute);
	const struct Map routeMap2 = addRoute(&routeMap, &greenRoute);
	const struct Map routeMap3 = addRoute(&routeMap2, &yellowRoute);

	struct Shipment shipment;

	struct Truck trucks[3] = {
		{0, 0, &blueRoute},
		{0, 0, &greenRoute},
		{0, 0, &yellowRoute}
	};

	printTitle();
	getUserInput(&shipment, &trucks);
	printMap(&routeMap3, 1, 1);

	return 0;
}