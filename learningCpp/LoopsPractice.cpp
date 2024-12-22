#include <iomanip>
#include <iostream>
#include <cmath>



double interest_rate(double balance) {
    while (balance < 0) {
        return balance = 3.213;
    }
    while (balance >= 0 && balance < 1000) {
        return balance = 0.5;
    }
    while (balance >= 1000 && balance < 5000) {
        return balance = 1.621;
    }
    while (balance >= 5000) {
        return balance = 2.475;
    }
    return balance;
}

double yearly_interest(double balance) {
    //return 1.00375;
    return balance * interest_rate(balance)/100;
}

double annual_balance_update(double balance) {
    //return 201.75375;
    return balance + yearly_interest(balance);
}

int years_until_desired_balance(double balance, double target_balance) {
    double num = 0;
    while (target_balance > balance) {
        balance = annual_balance_update(balance);
        num++;
    }
    return num;
}

int main() 
{   
    double balance = 200.75;
    double target_balance = 214.88;

    std::cout << interest_rate(balance);
	std::cout << "\n";
    std::cout << yearly_interest(balance);
    std::cout << "\n";
    std::cout << std::setprecision(15) << annual_balance_update(balance);
    std::cout << "\n";
    std::cout << years_until_desired_balance(balance, target_balance);
    
}