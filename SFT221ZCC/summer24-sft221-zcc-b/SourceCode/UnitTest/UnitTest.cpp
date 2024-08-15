#include "pch.h"
#include "CppUnitTest.h"
#include "Test_r.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>

// Author Abdullah Al Mahfuz
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(BlackBox_Testing)
	{
	public:
		
        // TestValidVolume function (R001) business requirement 1
        TEST_METHOD(T001)
        {
            struct Shipment shipment;

            // Test valid volumes ( 1 )
            Assert::AreEqual(1, validVolume(&shipment, 1));
            Assert::AreEqual(1, shipment.s_boxSize);
            // Test valid volumes ( 3 )
            Assert::AreEqual(1, validVolume(&shipment, 3));
            Assert::AreEqual(3, shipment.s_boxSize);
            // Test valid volumes ( 5 )
            Assert::AreEqual(1, validVolume(&shipment, 5));
            Assert::AreEqual(5, shipment.s_boxSize);
            // Test invalid volumes
            Assert::AreEqual(0, validVolume(&shipment, 2));
            Assert::AreEqual(0, validVolume(&shipment, 4));
            Assert::AreEqual(0, validVolume(&shipment, 6));
        }

        // TestValidWeight function (R002)- business requirement 2
        TEST_METHOD(T002)
        {
            struct Shipment shipment;

            // Test valid weights ( minimum weight )
            Assert::AreEqual(1, validWeight(&shipment, 1));
            Assert::AreEqual(1, shipment.s_weight);
            // Test valid weights ( maximum weight )
            Assert::AreEqual(1, validWeight(&shipment, 2500));
            Assert::AreEqual(2500, shipment.s_weight);
            // Test valid weights ( normal input )
            Assert::AreEqual(1, validWeight(&shipment, 1250));
            Assert::AreEqual(1250, shipment.s_weight);
            // Test invalid weights
            Assert::AreEqual(0, validWeight(&shipment, 0));
            Assert::AreEqual(0, validWeight(&shipment, 2501));
            Assert::AreEqual(0, validWeight(&shipment, -5));
        }

        // The add Route function test to see if the Blue route matches with the actual block- function getBlueRoute(), (R003)- business requirement 3
        TEST_METHOD(T003)
        {
            // Initialize a simple map
            struct Map baseMap = { 0 };
            baseMap.numRows = MAP_ROWS;
            baseMap.numCols = MAP_COLS;

            // Get the blue route
            struct Route blueRoute = getBlueRoute();
            struct Map routeMap = addRoute(&baseMap, &blueRoute);

            // Simple check to verify if the Blue route is added correctly
            Assert::AreEqual(BLUE, routeMap.squares[0][0]);
            Assert::AreEqual(BLUE, routeMap.squares[1][0]);
            Assert::AreEqual(BLUE, routeMap.squares[2][0]);
            Assert::AreEqual(BLUE, routeMap.squares[3][0]);
            Assert::AreEqual(BLUE, routeMap.squares[4][0]);
            Assert::AreEqual(BLUE, routeMap.squares[4][1]);
            Assert::AreEqual(BLUE, routeMap.squares[4][2]);
            Assert::AreEqual(BLUE, routeMap.squares[4][3]);
            Assert::AreEqual(BLUE, routeMap.squares[4][4]);
            Assert::AreEqual(BLUE, routeMap.squares[4][5]);
            Assert::AreEqual(BLUE, routeMap.squares[4][6]);
            Assert::AreEqual(BLUE, routeMap.squares[4][7]);
            Assert::AreEqual(BLUE, routeMap.squares[4][8]);
            Assert::AreEqual(BLUE, routeMap.squares[4][9]);
            Assert::AreEqual(BLUE, routeMap.squares[5][9]);
            Assert::AreEqual(BLUE, routeMap.squares[6][9]);
            Assert::AreEqual(BLUE, routeMap.squares[7][9]);
            Assert::AreEqual(BLUE, routeMap.squares[8][9]);
            Assert::AreEqual(BLUE, routeMap.squares[9][9]);
            Assert::AreEqual(BLUE, routeMap.squares[10][9]);
            Assert::AreEqual(BLUE, routeMap.squares[10][10]);
            Assert::AreEqual(BLUE, routeMap.squares[11][10]);
            Assert::AreEqual(BLUE, routeMap.squares[12][10]);
            Assert::AreEqual(BLUE, routeMap.squares[13][10]);
            Assert::AreEqual(BLUE, routeMap.squares[14][10]);
            Assert::AreEqual(BLUE, routeMap.squares[15][10]);
            Assert::AreEqual(BLUE, routeMap.squares[16][10]);
            Assert::AreEqual(BLUE, routeMap.squares[17][10]);
            Assert::AreEqual(BLUE, routeMap.squares[17][11]);
            Assert::AreEqual(BLUE, routeMap.squares[17][12]);
            Assert::AreEqual(BLUE, routeMap.squares[17][13]);
            Assert::AreEqual(BLUE, routeMap.squares[17][14]);
            Assert::AreEqual(BLUE, routeMap.squares[17][15]);
            Assert::AreEqual(BLUE, routeMap.squares[17][16]);
            Assert::AreEqual(BLUE, routeMap.squares[17][17]);
            Assert::AreEqual(BLUE, routeMap.squares[17][18]);
            Assert::AreEqual(BLUE, routeMap.squares[17][19]);
            Assert::AreEqual(BLUE, routeMap.squares[17][20]);
            Assert::AreEqual(BLUE, routeMap.squares[17][21]);
            Assert::AreEqual(BLUE, routeMap.squares[17][22]);
            Assert::AreEqual(BLUE, routeMap.squares[17][23]);
            Assert::AreEqual(BLUE, routeMap.squares[17][24]);
        }

        // The addtest function test to see if the Green route matches with the actual block- function getGreenRoute()
        TEST_METHOD(T004)
        {
            // Initialize a simple map
            struct Map baseMap = { 0 };
            baseMap.numRows = MAP_ROWS;
            baseMap.numCols = MAP_COLS;

            // Get the Green route
            struct Route greenRoute = getGreenRoute();
            struct Map routeMap = addRoute(&baseMap, &greenRoute);

            Assert::AreEqual(GREEN, routeMap.squares[0][0]);
            Assert::AreEqual(GREEN, routeMap.squares[1][0]);
            Assert::AreEqual(GREEN, routeMap.squares[2][0]);
            Assert::AreEqual(GREEN, routeMap.squares[3][0]);
            Assert::AreEqual(GREEN, routeMap.squares[4][0]);
            Assert::AreEqual(GREEN, routeMap.squares[4][1]);
            Assert::AreEqual(GREEN, routeMap.squares[4][2]);
            Assert::AreEqual(GREEN, routeMap.squares[4][3]);
            Assert::AreEqual(GREEN, routeMap.squares[4][4]);
            Assert::AreEqual(GREEN, routeMap.squares[4][5]);
            Assert::AreEqual(GREEN, routeMap.squares[4][6]);
            Assert::AreEqual(GREEN, routeMap.squares[4][7]);
            Assert::AreEqual(GREEN, routeMap.squares[4][8]);
            Assert::AreEqual(GREEN, routeMap.squares[4][9]);
            Assert::AreEqual(GREEN, routeMap.squares[4][10]);
            Assert::AreEqual(GREEN, routeMap.squares[4][11]);
            Assert::AreEqual(GREEN, routeMap.squares[3][11]);
            Assert::AreEqual(GREEN, routeMap.squares[2][11]);
            Assert::AreEqual(GREEN, routeMap.squares[1][11]);
            Assert::AreEqual(GREEN, routeMap.squares[0][11]);
            Assert::AreEqual(GREEN, routeMap.squares[0][12]);
            Assert::AreEqual(GREEN, routeMap.squares[0][13]);
            Assert::AreEqual(GREEN, routeMap.squares[0][14]);
            Assert::AreEqual(GREEN, routeMap.squares[0][15]);
            Assert::AreEqual(GREEN, routeMap.squares[0][16]);
            Assert::AreEqual(GREEN, routeMap.squares[0][17]);
            Assert::AreEqual(GREEN, routeMap.squares[0][18]);
            Assert::AreEqual(GREEN, routeMap.squares[0][19]);
            Assert::AreEqual(GREEN, routeMap.squares[1][19]);
            Assert::AreEqual(GREEN, routeMap.squares[2][19]);
            Assert::AreEqual(GREEN, routeMap.squares[3][19]);
            Assert::AreEqual(GREEN, routeMap.squares[4][19]);
            Assert::AreEqual(GREEN, routeMap.squares[5][19]);
            Assert::AreEqual(GREEN, routeMap.squares[6][19]);
            Assert::AreEqual(GREEN, routeMap.squares[7][19]);
            Assert::AreEqual(GREEN, routeMap.squares[8][19]);
            Assert::AreEqual(GREEN, routeMap.squares[9][19]);
            Assert::AreEqual(GREEN, routeMap.squares[9][20]);
            Assert::AreEqual(GREEN, routeMap.squares[9][21]);
            Assert::AreEqual(GREEN, routeMap.squares[9][22]);
            Assert::AreEqual(GREEN, routeMap.squares[9][24]);
        }

        // The addroute function test to see if the Yellow route matches with the actual block- function getYellowRoute()
        TEST_METHOD(T005)
        {
            // Initialize a simple map
            struct Map baseMap = { 0 };
            baseMap.numRows = MAP_ROWS;
            baseMap.numCols = MAP_COLS;

            // Get the Yellow route
            struct Route yellowRoute = getYellowRoute();
            struct Map routeMap = addRoute(&baseMap, &yellowRoute);
            
            Assert::AreEqual(YELLOW, routeMap.squares[0][0]);
            Assert::AreEqual(YELLOW, routeMap.squares[1][0]);
            Assert::AreEqual(YELLOW, routeMap.squares[2][0]);
            Assert::AreEqual(YELLOW, routeMap.squares[3][0]);
            Assert::AreEqual(YELLOW, routeMap.squares[4][0]);
            Assert::AreEqual(YELLOW, routeMap.squares[4][1]);
            Assert::AreEqual(YELLOW, routeMap.squares[4][3]);
            Assert::AreEqual(YELLOW, routeMap.squares[5][3]);
            Assert::AreEqual(YELLOW, routeMap.squares[6][3]);
            Assert::AreEqual(YELLOW, routeMap.squares[7][3]);
            Assert::AreEqual(YELLOW, routeMap.squares[8][3]);
            Assert::AreEqual(YELLOW, routeMap.squares[9][3]);
            Assert::AreEqual(YELLOW, routeMap.squares[9][2]);
            Assert::AreEqual(YELLOW, routeMap.squares[9][1]);
            Assert::AreEqual(YELLOW, routeMap.squares[10][1]);
            Assert::AreEqual(YELLOW, routeMap.squares[11][1]);
            Assert::AreEqual(YELLOW, routeMap.squares[12][1]);
            Assert::AreEqual(YELLOW, routeMap.squares[13][1]);
            Assert::AreEqual(YELLOW, routeMap.squares[14][1]);
            Assert::AreEqual(YELLOW, routeMap.squares[15][1]);
            Assert::AreEqual(YELLOW, routeMap.squares[16][1]);
            Assert::AreEqual(YELLOW, routeMap.squares[17][1]);
            Assert::AreEqual(YELLOW, routeMap.squares[18][1]);
            Assert::AreEqual(YELLOW, routeMap.squares[19][1]);
            Assert::AreEqual(YELLOW, routeMap.squares[19][2]);
            Assert::AreEqual(YELLOW, routeMap.squares[19][3]);
            Assert::AreEqual(YELLOW, routeMap.squares[19][4]);
            Assert::AreEqual(YELLOW, routeMap.squares[19][5]);
            Assert::AreEqual(YELLOW, routeMap.squares[19][6]);
            Assert::AreEqual(YELLOW, routeMap.squares[19][7]);
            Assert::AreEqual(YELLOW, routeMap.squares[19][8]);
            Assert::AreEqual(YELLOW, routeMap.squares[19][9]);
            Assert::AreEqual(YELLOW, routeMap.squares[19][10]);
            Assert::AreEqual(YELLOW, routeMap.squares[19][11]);
            Assert::AreEqual(YELLOW, routeMap.squares[19][12]);
            Assert::AreEqual(YELLOW, routeMap.squares[19][13]);
            Assert::AreEqual(YELLOW, routeMap.squares[19][14]);
            Assert::AreEqual(YELLOW, routeMap.squares[19][15]);
            Assert::AreEqual(YELLOW, routeMap.squares[19][16]);
            Assert::AreEqual(YELLOW, routeMap.squares[19][17]);
            Assert::AreEqual(YELLOW, routeMap.squares[19][18]);
            Assert::AreEqual(YELLOW, routeMap.squares[19][19]);
            Assert::AreEqual(YELLOW, routeMap.squares[19][20]);
            Assert::AreEqual(YELLOW, routeMap.squares[19][21]);
            Assert::AreEqual(YELLOW, routeMap.squares[19][22]);
            Assert::AreEqual(YELLOW, routeMap.squares[19][23]);
            Assert::AreEqual(YELLOW, routeMap.squares[19][24]);
        }

	};

    TEST_CLASS(WhiteBox_Testing) {

    public:

        // Test validDestination function- (R004)- business requirement 4
        TEST_METHOD(T006) {

            // Initialize a simple map
            struct Map baseMap = { 0 };
            baseMap.numRows = MAP_ROWS;
            baseMap.numCols = MAP_COLS;

            // Set up a simple map with buildings and empty spaces
            // Let's assume '1' represents a building and '0' represents an empty space
            // Example map setup
            for (int i = 0; i < MAP_ROWS; ++i) {
                for (int j = 0; j < MAP_COLS; ++j) {
                    baseMap.squares[i][j] = 0; // Initialize all to empty space
                }
            }
            // Add some buildings
            baseMap.squares[1][1] = 1;
            baseMap.squares[1][2] = 1;
            baseMap.squares[2][2] = 1;
            baseMap.squares[3][3] = 1;
            baseMap.squares[4][4] = 1;

            struct Shipment shipment;

            // Test valid destinations
            Assert::AreEqual(1, validDestination(baseMap, &shipment, 2, 'B'));
            Assert::AreEqual(1, validDestination(baseMap, &shipment, 2, 'C'));
            Assert::AreEqual(1, validDestination(baseMap, &shipment, 4, 'D'));

            // Test invalid destinations (out of range)
            Assert::AreEqual(0, validDestination(baseMap, &shipment, 0, 'A'));
            Assert::AreEqual(0, validDestination(baseMap, &shipment, 26, 'A'));
            Assert::AreEqual(0, validDestination(baseMap, &shipment, 1, 'Z'));
            Assert::AreEqual(0, validDestination(baseMap, &shipment, 1, '['));

            // Test invalid destinations (not a building or no adjacent empty space)
            Assert::AreEqual(0, validDestination(baseMap, &shipment, 3, 'A')); // Not a building
            Assert::AreEqual(0, validDestination(baseMap, &shipment, 4, 'C')); // No adjacent empty space
        }

        // Test canCarry function- (R005)- business requirement 5
        TEST_METHOD(T007)
        {
            struct Shipment shipment = { 1000, 5, {0, 0} };
            struct Truck truck = { 1000, 90, NULL };

            // Test that the truck can carry the shipment
            Assert::AreEqual(1, canCarry(&truck, &shipment));

            // Test that the truck cannot carry the shipment (exceeds weight)
            shipment.s_weight = 1501; // this makes the total weight 2501 (1 above limit)
            Assert::AreEqual(0, canCarry(&truck, &shipment));

            // Test that the truck cannot carry the shipment (exceeds volume)
            shipment.s_weight = 1000;
            shipment.s_boxSize = 20; // this makes the box size 110 ( 10 above the limit )
            Assert::AreEqual(0, canCarry(&truck, &shipment));
        }

        // Test compareTrucks function- (R006)- Business requirement 6
        TEST_METHOD(T008) {

            struct Truck truck1 = { 1000, 10, NULL };
            struct Truck truck2 = { 1000, 20, NULL };

            // Test that truck1 is less than truck2
            Assert::AreEqual(1, compareTrucks(&truck1, &truck2));

            // Test that truck2 is greater than truck1
            Assert::AreEqual(-1, compareTrucks(&truck2, &truck1));

            // Test that trucks are equal
            truck2.volume = 10; // This makes truck1 volume 20
            Assert::AreEqual(0, compareTrucks(&truck1, &truck2));
        }

        // Test convertPoint function- (R007)- Business requirement 7
        TEST_METHOD(T009) {

            struct Point point;
            char col[1];
            int row;

            // Test conversion - should return 3 for row and C for column
            point = { 2, 2 };
            row = convertPoint(&point, col);
            Assert::AreEqual(3, row); // In accordance with the function implementation- row is calculated as point->row + 1, which means 2 + 1 = 3.
            Assert::AreEqual('C', col[0]); // In accordance with the function implementation- A+2 = ASCII value of 'A' is 65. Adding 2 gives us 67, which corresponds to 'C' 

            //  Point at (0, 0)- should return 1 for row and A for column
            point = { 0, 0 };
            row = convertPoint(&point, col);
            Assert::AreEqual(1, row);
            Assert::AreEqual('A', col[0]);

            // Test Case 3: Point at (24, 24)
            point = { 24, 24 };
            row = convertPoint(&point, col);
            Assert::AreEqual(25, row);
            Assert::AreEqual('Y', col[0]);

            // Test Case 4: Point at (10, 5)
            point = { 10, 5 };
            row = convertPoint(&point, col);
            Assert::AreEqual(11, row);
            Assert::AreEqual('F', col[0]);

            // Test Case 5: Point at (14, 18)
            point = { 14, 18 };
            row = convertPoint(&point, col);
            Assert::AreEqual(15, row);
            Assert::AreEqual('S', col[0]);

            // Test Case 6: Point at (8, 15)
            point = { 8, 15 };
            row = convertPoint(&point, col);
            Assert::AreEqual(9, row);
            Assert::AreEqual('P', col[0]);

            // Test Case 7: Point at (19, 4)
            point = { 19, 4 };
            row = convertPoint(&point, col);
            Assert::AreEqual(20, row);
            Assert::AreEqual('E', col[0]);

            // Test Case 8: Point at (23, 10)
            point = { 23, 10 };
            row = convertPoint(&point, col);
            Assert::AreEqual(24, row);
            Assert::AreEqual('K', col[0]);

            // Test Case 9: Point at (6, 22)
            point = { 6, 22 };
            row = convertPoint(&point, col);
            Assert::AreEqual(7, row);
            Assert::AreEqual('W', col[0]);

            // Test Case 10: Point at (4, 8)
            point = { 4, 8 };
            row = convertPoint(&point, col);
            Assert::AreEqual(5, row);
            Assert::AreEqual('I', col[0]);

        }  
        // just a simple test 
        TEST_METHOD(T010)
        {
            // Initialize map and trucks
            struct Map map = populateMap();
            struct Truck trucks[3] = {
                {0, 0, NULL}, // Initialize trucks with default values or valid paths
                {0, 0, NULL},
                {0, 0, NULL}
            };

            // Simulate a shipment
            struct Shipment shipment = { 0, 0, {0, 0} };

            // Define invalid input
            int invalidWeight = 3000; // Exceeds maximum weight
            int invalidBoxVolume = 2; // Invalid volume
            int destRow = 30; // Out of map range
            char destCol = 'z'; // Out of map range

            // Test invalid weight
            Assert::IsFalse(validWeight(&shipment, invalidWeight) == 1);

            // Test invalid box volume
            Assert::IsFalse(validVolume(&shipment, invalidBoxVolume) == 1);

            // Test invalid destination
            Assert::IsFalse(validDestination(map, &shipment, destRow, destCol) == 1);
        }
    };

    // Integration testing goes here
    TEST_CLASS(Integration_Testing) {

    public:
        // the chooseTruckLine function integration test. (R008)- Business requirement 8
        // This function has canCarry(), shortestPath(), and compareTrucks() inside it.
        TEST_METHOD(T011)
        {
            struct Map baseMap = populateMap();

            struct Route blueRoute = getBlueRoute();
            struct Route greenRoute = getGreenRoute();
            struct Route yellowRoute = getYellowRoute();

            struct Truck trucks[3] = {
                {1000, 50, &blueRoute},
                {1500, 60, &greenRoute},
                {2000, 70, &yellowRoute}
            };

            struct Shipment shipment = { 500, 5, { 10, 10 } }; // is a Blue route Destination

            int chosenTruck = chooseTruckLine(&baseMap, &shipment, trucks, 3);

            // Validate the chosen truck and update in terms of weight and volume
            Assert::AreEqual(0, chosenTruck);
            Assert::AreEqual(1500, trucks[chosenTruck].weight); // Added 500 from shipment to the existing weight
            Assert::AreEqual(55.00, trucks[chosenTruck].volume); // added 5 from shipment to the existing volume
        }

        // R008 - with Green route
        TEST_METHOD(T012)
        {
            struct Map baseMap = populateMap();

            struct Route blueRoute = getBlueRoute();
            struct Route greenRoute = getGreenRoute();
            struct Route yellowRoute = getYellowRoute();

            struct Truck trucks[3] = {
                {1000, 50, &blueRoute},
                {1500, 60, &greenRoute},
                {2000, 70, &yellowRoute}
            };

            struct Shipment shipment = { 500, 5, { 2, 19 } }; // is a Green Route destination

            int chosenTruck = chooseTruckLine(&baseMap, &shipment, trucks, 3);

            // Validate the chosen truck and update in terms of weight and volume
            Assert::AreEqual(1, chosenTruck); // The Green route
            Assert::AreEqual(2000, trucks[chosenTruck].weight); // Added 500 from shipment to the existing weight
            Assert::AreEqual(65.00, trucks[chosenTruck].volume); // added 5 from shipment to the existing volume
        }

        // R008- with Yellow route
        TEST_METHOD(T013)
        {
            struct Map baseMap = populateMap();

            struct Route blueRoute = getBlueRoute();
            struct Route greenRoute = getGreenRoute();
            struct Route yellowRoute = getYellowRoute();

            struct Truck trucks[3] = {
                {1000, 50, &blueRoute},
                {1500, 60, &greenRoute},
                {2000, 70, &yellowRoute}
            };

            struct Shipment shipment = { 500, 10, { 19, 1 } }; // is a Yellow route destination

            int chosenTruck = chooseTruckLine(&baseMap, &shipment, trucks, 3);

            // Validate the chosen truck and update in terms of weight and volume
            Assert::AreEqual(2, chosenTruck); // The Yellow route
            Assert::AreEqual(2500, trucks[chosenTruck].weight); // Added 500 from shipment to the existing weight
            Assert::AreEqual(80.00, trucks[chosenTruck].volume); // added 10 from shipment to the existing volume
        }

        // Test printDiversion function- R009- Business Requirement 9
        // this function calls convertPoint function for its operations
        
        // Helper function to capture the output of printDiversion
        std::string CapturePrintDiversionOutput(struct Route* diversion)
        {
            // Redirect stdout to a file
            FILE* fp;
            if (freopen_s(&fp, "output.txt", "w", stdout) != 0) {
                perror("freopen_s failed");
                exit(1);
            }

            printDiversion(diversion);

            // Restore stdout
            if (freopen_s(&fp, "CON", "w", stdout) != 0) {
                perror("freopen_s failed");
                exit(1);
            }

            // Read the file content
            std::ifstream file("output.txt");
            std::stringstream buffer;
            buffer << file.rdbuf();
            file.close();

            return buffer.str();
        }

        // Test with no points in the diversion
        TEST_METHOD(T014)
        {
            struct Route diversion;
            diversion.numPoints = 0;

            std::string output = CapturePrintDiversionOutput(&diversion);
            std::string expectedOutput = "no diversion\n";
            Assert::AreEqual(expectedOutput, output);
        }

        // Test with fewer than 3 points
        TEST_METHOD(T015)
        {
            struct Route diversion;
            diversion.numPoints = 2;
            diversion.points[0] = { 0, 0 };
            diversion.points[1] = { 1, 1 };

            std::string output = CapturePrintDiversionOutput(&diversion);
            std::string expectedOutput = "no diversion\n";
            Assert::AreEqual(expectedOutput, output);
        }

        // Test with exactly 3 points
        TEST_METHOD(T016)
        {
            struct Route diversion;
            diversion.numPoints = 3;
            diversion.points[0] = { 0, 0 };
            diversion.points[1] = { 1, 1 };
            diversion.points[2] = { 2, 2 };

            std::string output = CapturePrintDiversionOutput(&diversion);
            std::string expectedOutput = "divert: 1A, 2B, 3C\n";
            Assert::AreEqual(expectedOutput, output);
        }

        // Test with more than 3 points
        TEST_METHOD(T017)
        {
            struct Route diversion;
            diversion.numPoints = 4;
            diversion.points[0] = { 0, 0 };
            diversion.points[1] = { 1, 1 };
            diversion.points[2] = { 2, 2 };
            diversion.points[3] = { 3, 3 };

            std::string output = CapturePrintDiversionOutput(&diversion);
            std::string expectedOutput = "divert: 1A, 2B, 3C, 4D\n";
            Assert::AreEqual(expectedOutput, output);
        }
    };
}
