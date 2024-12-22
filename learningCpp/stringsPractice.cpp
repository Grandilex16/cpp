#include <iostream>
#include <algorithm>
#include "/home/jayce/Documents/Programming/cpp/protein-translation/protein_translation.cpp"

// Log_level practice
namespace log_line {
	std::string message(std::string line) {
		return line.substr(line.find(":") + 2);
	}

    std::string log_level(std::string line) {
        // return the log level
        return line.substr(1, line.find("]") - 1);
    }

    std::string reformat(std::string line) {
        // return the reformatted message
    	return log_line::message(line) + " (" + log_line::log_level(line) + ")";
    }
}


// Raindrops
namespace raindrops {
	std::string convert(int num) {
		std::string out;
		if (num % 3 == 0) {
			out += "Pling";
		} if (num % 5 == 0) {
			out += "Plang";
		} if (num % 7 == 0) {
			out += "Plong";
		} if (out == "") {
			out += std::to_string(num);
		}
		return out;
	}
}

std::string StringReverse(std::string word) {
	reverse(word.begin(), word.end());
	return word;
}


int main()
{
	// Log_levels Practice
	std::string words = "[ERROR]: Invalid Operation";

	std::cout << log_line::message(words) << + "\n";
	std::cout << log_line::log_level(words) << + "\n";
	std::cout << log_line::reformat(words) << + "\n\n";

	// Randrops practice
	std::cout << raindrops::convert(30) << "\n";

	// reverse string
	std::cout << StringReverse("racecar") << "\n\n";


	// protien_translation practice
	std::cout << "Protien Translation practice" << "\n";
	for (std::string i : protein_translation::proteins("AUGUUUUCUUAAAUG")) {
		std::cout << i << " ";
	}

	return 0;
}