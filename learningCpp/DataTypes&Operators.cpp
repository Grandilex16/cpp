#include <iostream>


// Working with Integers

int main() {


	// Variables


	int yAge = 16;
	int oAge = 21;


	
	std::cout << yAge + oAge << "\n";


	// Working with User Input

	int tip = 0;
	std::cout << "Enter tip amount: ";
	std::cin >> tip;
	std::cout << "Tip amount is " << tip << "\n\n";


	// Converting Temperatures

	double tempf;
	
	std::cout << "Please type the current temperature.\n";
	std::cin >> tempf;

	double tempc = (tempf - 32) / 1.8;
	
	std::cout << "The temperature in the room is " << tempc << " degrees Celsius\n\n" ;


	// Challenges

	// Create a program that takes in the weight of an item and then calculates how much that item would weigh on Mars.

	double userWeight;
	std::cout << "I will convert weight in lbs to weight on mars. Please type the weight you wish to convert.\n";
	
	std::cin >> userWeight;

	// or divide by 2.643 for inaccuracy yet still close.
	double convertedWeight = (userWeight / 9.81) * 3.711;

	std::cout << "The Weight on mars in lbs is " << convertedWeight << ".\n\n";


	// Create a program that asks for a distance in miles as input. The program will then output how much that distance is in kilometers.

	double milesSpeed;
	double kiloSpeed;

	std::cout << "Type the speed in miles per hour: \n";
	std::cin >> milesSpeed;

	kiloSpeed = milesSpeed * 1.60934;

	std::cout << "That speed in Kilometers is " << kiloSpeed << ".\n";
}