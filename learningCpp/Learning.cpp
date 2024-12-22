#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>



// Pac-man practice
namespace pacman {
	bool can_eat_ghost(bool power_pellet_active, bool touching_ghost) {
    // TODO: Please implement the can_eat_ghost function
    power_pellet_active, touching_ghost = true;
    power_pellet_active && touching_ghost;
    return can_eat_ghost(true, true);
	}
	
	bool lost(bool power_pellet_active, bool touching_ghost) {
    // TODO: Please implement the lost function
    power_pellet_active = false;
    touching_ghost = true;
    return power_pellet_active && touching_ghost;
	}

}



// Last Will practice
namespace zhang {
    int bank_number_part(int secret_modifier) {
        int zhang_part{8'541};
        return (zhang_part*secret_modifier) % 10000;
    }
    namespace red {
        int code_fragment() {return 512;}
    }
    namespace blue {
        int code_fragment() {return 677;}
    }
}

// Secret knowledge of the Khan family:
namespace khan {
    int bank_number_part(int secret_modifier) {
        int khan_part{4'142};
        return (khan_part*secret_modifier) % 10000;
    }
    namespace red {
        int code_fragment() {return 148;}
    }
    namespace blue {
        int code_fragment() {return 875;}
    }
}

// Secret knowledge of the Garcia family:
namespace garcia {
    int bank_number_part(int secret_modifier) {
        int garcia_part{4'023};
        return (garcia_part*secret_modifier) % 10000;
    }
    namespace red {
        int code_fragment() {return 118;}
    }
    namespace blue {
        int code_fragment() {return 923;}
    }
}

namespace estate_executor {
    int assemble_account_number(int secret_modifier) {
        int assembled_account_number{zhang::bank_number_part(secret_modifier) + khan::bank_number_part(secret_modifier) + garcia::bank_number_part(secret_modifier)}; 
        return assembled_account_number;
    }
    int assemble_code() {
        int redCodes = zhang::red::code_fragment() + khan::red::code_fragment() + garcia::red::code_fragment();
        int blueCodes = zhang::blue::code_fragment() + khan::blue::code_fragment() + garcia::blue::code_fragment();;
       	return redCodes * blueCodes;
    }
}



// vehicle purchase practice
bool needs_license(std::string kind){
    // TODO: Return true if you need a license for that kind of vehicle.
    if (kind == "car" || kind == "truck") {
    return true;
    } else {
    return false;
    }
}

std::string choose_vehicle(std::string option1, std::string option2) {
    // TODO: Return the final decision in a sentence.
    if (option1 < option2) {
    return option1 + " is clearly the better choice.";
    } else {
    return option1 + " is clearly the better choice.";
    }
}

double calculate_resell_price(double original_price, double age) {
    // TODO: Return the age-corrected resell price.
    if (age < 3) {
    	return original_price * 0.8;
    } else if (age > 3, age < 10) {
    	return original_price * 0.7;
    } else if (age >= 10) {
    	return original_price * 0.5;
    } else {
    	return 010101;
    }
}





int main() 
{
	// Pac-man Practice
    bool power_pellet_active = true; 
    bool touching_ghost = true;
    power_pellet_active && touching_ghost;
	
	std::cout << pacman::lost(0,1) << " \n\n";



	// Last Will Practice
	std::cout << estate_executor::assemble_account_number(1) << "\n";
	std::cout << estate_executor::assemble_code() << "\n\n";



	// Vehicle-purchase Practice
	std::string car = "car";
	std::string bike = "bike";
	std::string truck = "truck\n";

	bool license = needs_license(car);
	if (license == true) {
		std::cout << "true\n";
	} else {
		std::cout << "false\n";
	}

	std::string vehicleNames[] = {"Volkswagen Beetle", "Wuling", "Toyota", "Volkswagen Golf", "Bugatti Veyron", "Ford Pinto", "Chery EQ", "Kia Nero Elektro", "Ford Focus", "2020 Gazelle Medeo", "2018 Bergamont City", "ford"};
	srand(time(NULL));
	std::string vehicle1 = vehicleNames[rand() % 12];
	std::string vehicle2 = vehicleNames[rand() % 12];
	std::string carChoice = choose_vehicle(vehicle1, vehicle2);
	std::cout << "Between " << vehicle1 << " and " << vehicle2 << ", " << carChoice << "\n";

	std::cout << calculate_resell_price(1000, 15);
	std::cout << "\n\n";



};