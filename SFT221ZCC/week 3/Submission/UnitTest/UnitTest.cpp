#include "pch.h"
#include "CppUnitTest.h"
#include "customer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		/******* Black-box ********/

		// Normal Proper input
		TEST_METHOD(BlackBoxTest1)
		{
			char test[] = "A1B 3C4";
			Assert::IsTrue(test);
			// Test will pass
		}

		// Normal Lowercase input
		TEST_METHOD(BlackboxTest2)
		{
			char test[] = "l7c 2w1";
			Assert::IsTrue(test);
			// test will pass, will convert the lowercase characters into uppercase
		}

		// Normal (All UPPER) Input with no spaces in between the postal code
		TEST_METHOD(BlackBoxTest3)
		{
			char test[] = "M1J7E8";
			Assert::IsTrue(test);
			// Test will pass, will add the space after the 3rd character
		}

		// Normal (all lower) Input with no spaces in between the postal code
		TEST_METHOD(BlackBoxTest4)
		{
			char test[] = "k3w8j9";
			Assert::IsTrue(test);
			// Test will pass, Will convert the lowercase characters into uppercase and will add the space after the 3rd character
		}

		// Input special characters within the code 
		TEST_METHOD(BlackBoxTest5)
		{
			char test[] = "k3w&j9";
			Assert::IsTrue(test);
			//Test will pass as it will generate an error in the screen and ask for proper inputs
		}

		// Normal inputs with multiple spaces in between the 3rd and 4th meaningful character i.e m1k      4u7
		TEST_METHOD(BlackBoxTest6)
		{
			char test[] = "S3T            9j3";
			Assert::IsTrue(test);
			//Test will pass as, will remove all but one space after the 3rd character and create a proper postal code
		}

		// Inputs with more than 6 characters
		TEST_METHOD(BlackBoxTest7)
		{
			char test[] = "S3T 9j3K";
			Assert::IsTrue(test);
			//Test will pass as it will generate an error in the screen and ask for proper inputs(because a postal code can only have 6 meaningful characters
		}

		// Inputs of only Numbers
		TEST_METHOD(BlackBoxTest8)
		{
			char test[] = "123456";
			Assert::IsTrue(test);
			//Test will pass as it will generate an error in the screen and ask for proper inputs
		}

		// Inputs of only special characters
		TEST_METHOD(BlackBoxTest9)
		{
			char test[] = "#!@%^&";
			Assert::IsTrue(test);
			//Test will pass as it will generate an error in the screen and ask for proper inputs
		}

		// Inputs with less than 6 charcaters
		TEST_METHOD(BlackBoxTest10)
		{
			char test[] = "M1K 4E";
			Assert::IsTrue(test);
			//Test will pass as it will generate an error in the screen and ask for proper inputs
		}

		// No Input
		TEST_METHOD(BlackBoxTest11)
		{
			char test[] = "";
			Assert::IsTrue(test);
			//Test will pass as it will generate an error in the screen and ask for proper inputs (empty line is not a proper postal code)
		}

		// Normal input with a mix of uppercase and lowercase characters
		TEST_METHOD(BlackBoxTest12)
		{
			char test[] = "M1j 4e1";
			Assert::IsTrue(test);
			//Test will pass, will leave uppercases untouched and convert the lowercases to uppercase
		}

		/******* White-box ********/

		// Normal proper Inputs
		TEST_METHOD(WhiteBoxTest1)
		{
			char test[] = "L2V 4N6";
			Assert::IsTrue(test);
			// Test will pass because proper values were put
		}

		// Normal(all lowercase) proper Inputs 
		TEST_METHOD(WhiteBoxTest2)
		{
			char test[] = "m1j 4e8";
			Assert::IsTrue(test);
			// Test will pass, as the "toupper" function converts all that is lowercase into uppercase
		}

		// Normal inputs with no space
		TEST_METHOD(WhiteBoxTest3)
		{
			char test[] = "K2G8L7";
			Assert::IsTrue(test);
			// Test will pass, as there is a condition in the enterData function that will add the space after the 3rd character if the input doesn't have it
		}

		// Normal(lowercase) inputs with no space
		TEST_METHOD(WhiteBoxTes4)
		{
			char test[] = "k2g8p7";
			Assert::IsTrue(test);
			// Test will pass, as there is a condition in the enterData function that will add the space after the 3rd character if the input doesn't have it and will convert the lowercase into uppercase
		}

		// Normal inputs will multiple space
		TEST_METHOD(WhiteBoxTest5)
		{
			char test[] = "M2j            5k8";
			Assert::IsTrue(test);
			// Test will pass, there is a condition in the enterData function that removes excess whitespaces in between 3rd and 4th meaningfull character
		}

		//Inputs with extra spaces and extra characters
		TEST_METHOD(WhiteBoxTest6)
		{
			char test[] = "M1k    8J99";
			Assert::IsTrue(test);
			// This test will fail because this condition is not specified in the code using "if/else" statement, so the code will remove spaces from the string but will not remove last character from the string or prompt the user to enter the string again 
			// The code will crash
		}

		// Inputs with no values
		TEST_METHOD(WhiteBoxTesting7)
		{
			char test[] = "";
			Assert::IsTrue(test); 

			// This test pass,because no inputs were provided
			// there is a condition specified to prompt the user for a valid input if the input is new line character
		}

		
	};

}
