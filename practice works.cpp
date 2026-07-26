// practice works.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include<iostream>
// Represents a single car in the warehouse
// All data is private — only accessible through public methods
class Car
{
private:
	std::string name{};         // Car model name
	std::string type{};         // Category: Supercar, Sports, Muscle
	double price{};             // Price in USD
	int quantity{};             // How many of this car are in stock


public:
	// Default constructor — needed so Warehouse can create an empty array of Cars
	Car() = default;
	// Custom constructor — sets all car details when a Car object is created
	// Uses member initializer list for efficiency
	Car(std::string name,
		std::string type,
		double price,
		int quantity)
		: name{ name },
		type{ type },
		price{ price },
		quantity{ quantity }
	{
	}
	// Prints all information about this car to the console
	void displayInfo()
	{
		std::cout << "======================\n";
		std::cout << "    CAR INFORMATION   \n";
		std::cout << "======================\n";
		std::cout << "Name         : " << name << std::endl;
		std::cout << "Type         : " << type << std::endl;
		std::cout << "Price        : " << price << std::endl;
		std::cout << "Quantity     : " << quantity << std::endl;
		std::cout << "======================\n";
	}
	// Reduces stock by 1 when a car is purchased
   // Prevents purchase if quantity is already 0
	void reduceQuantity()
	{
		if (quantity > 0)
		{
			quantity -=1;
			std::cout << "Purchase successful!\n";
		}
		else 
		{
			std::cout << "We do not have that car in stock \n";
		}

	}
	// Getter functions — allow read-only access to private data
	int getQuantity()
	{
		return quantity;
		
	}

	  std::string getName()
	  {
		  return name;
	  }

	  std::string getType()
	  {
		  return type;
	  }

	  double getPrice()
	  {
		  return price;
	  }


};
// Manages a collection of up to 10 cars
// Controls how cars are added, displayed, and purchased
class Warehouse
{
private:
	static constexpr int MAX_CARS{ 10 };           // Maximum capacity — fixed at compile time
	Car cars[MAX_CARS];                            // Array storing all cars in the warehouse
	int carCount{};                                // Tracks how many cars are currently stored

public:
	// Constructor — starts with an empty warehouse
	Warehouse()
		: carCount{ 0 }
	{
	}
	// Adds a car to the warehouse if space is available
	void addCar(const Car& car)
	{
		if (carCount <MAX_CARS )
		{
			cars[carCount] = car;
			carCount++;
		}
		else 
		{
			std::cout<<"There is no space left in the warehouse\n";
		}
	}
	// Displays information for every car currently in the warehouse
	void displayAll()
	{
		if (carCount == 0)
		{
			std::cout << "Warehouse is empty.\n";
			return;
		}

		for (int i{ 0 }; i < carCount; ++i)
		{
			cars[i].displayInfo();
		}
	}
	// Processes a purchase — reduces stock of the selected car
	void buyCar(int index)
	{
		if (index >= 0 && index < carCount)
		{
			cars[index].reduceQuantity();
		}
		else
		{
			std::cout << "Invalid car selection.\n";
		}
	}
};

int main()
{
	// Create warehouse and stock it with 10 cars across different categories
	Warehouse warehouse;
	Car ferrari488("Ferrari 488 GTB", "Supercar", 280000.00, 1);

	Car mclaren720S("McLaren 720S", "Supercar", 320000.00, 1);

	Car nissan350z("Nissan 350Z", "Sports", 35000.00, 5);

	Car fordMustangGT("Ford Mustang GT", "Muscle", 55000.00, 3);

	Car chevroletCamaroSS("Chevrolet Camaro SS", "Muscle", 52000.00, 3);

	Car subaruWRX("Subaru WRX STI", "Sports", 45000.00, 4);

	Car hondaCivicTypeR("Honda Civic Type R", "Sports", 47000.00, 4);

	Car toyotaGR86("Toyota GR86", "Sports", 33000.00, 6);

	Car mazdaMX5("Mazda MX-5 Miata", "Sports", 31000.00, 5);

	Car volkswagenGolfR("Volkswagen Golf R", "Hatchback", 46000.00, 4);

	warehouse.addCar(ferrari488);
	warehouse.addCar(mclaren720S);

	warehouse.addCar(nissan350z);
	warehouse.addCar(fordMustangGT);
	warehouse.addCar(chevroletCamaroSS);

	warehouse.addCar(subaruWRX);
	warehouse.addCar(hondaCivicTypeR);
	warehouse.addCar(toyotaGR86);
	warehouse.addCar(mazdaMX5);
	warehouse.addCar(volkswagenGolfR);

	int choice{};
	// Main menu loop — keeps running until user chooses to exit
	do
	{
		std::cout << "\n==============================\n";
		std::cout << "     CAR WAREHOUSE SYSTEM\n";
		std::cout << "==============================\n";
		std::cout << "1. Display all cars\n";
		std::cout << "2. Buy a car\n";
		std::cout << "3. Exit\n";
		std::cout << "Enter choice: ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			warehouse.displayAll();
			break;

		case 2:
		{
			// Show all cars first so user can see the index numbers
			int index;

			warehouse.displayAll();

			std::cout << "\nEnter the car number (0-9): ";
			std::cin >> index;

			warehouse.buyCar(index);

			break;
		}

		case 3:
			std::cout << "\nThank you for visiting our warehouse!\n";
			break;

		default:
			std::cout << "\nInvalid option.\n";
		}

	} while (choice != 3);

	return 0;

}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
