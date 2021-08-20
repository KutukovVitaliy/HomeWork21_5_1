#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::string Command;
    struct Human {
        std::string FirstName;
        std::string LastName;
        std::string DateOfPayment;
        int Payment;
    } ;
    bool ValueTrue;
    std::vector<Human> Record;
    Human TmpValue;

    do{
        ValueTrue = false;
        std::cout << "Enter the command ('list' or 'add'): ";
        std::cin >> Command;
        if(Command == "list" || Command == "add") ValueTrue = true;
        if(!ValueTrue){
            std::cout << "Bad input. Try again!" << std::endl;
        }
    } while (!ValueTrue);
    if(Command == "list"){
        Record.clear();
        std::ifstream PaymentFile("../PaymentFile.txt");
        if(!PaymentFile.is_open()){
            std::cout << "Can't find PaymentFile.txt!" << std::endl;
            return 0;
        }
        do{
            PaymentFile >> TmpValue.FirstName;
            if(TmpValue.FirstName.empty()) break;
            PaymentFile >> TmpValue.LastName;
            PaymentFile >> TmpValue.DateOfPayment;
            PaymentFile >> TmpValue.Payment;
            Record.push_back(TmpValue);
            TmpValue.FirstName.clear();
        } while (!PaymentFile.eof());
        for(auto el : Record){
            std::cout << el.FirstName << " " << el.LastName << " " << el.DateOfPayment << " " <<
             el.Payment << std::endl;
        }
    }
    else if(Command == "add"){
        std::cout << "Enter the first name: ";
        std::cin >> TmpValue.FirstName;
        std::cout << "Enter the last name: ";
        std::cin >> TmpValue.LastName;
        do{
            ValueTrue = true;
            std::cout << "Enter the date of payment (dd-mm-yy): ";
            std::cin >> TmpValue.DateOfPayment;
            int dd = std::stoi(TmpValue.DateOfPayment.substr(0,2));
            int mm = std::stoi(TmpValue.DateOfPayment.substr(3,2));
            int yy = std::stoi(TmpValue.DateOfPayment.substr(6,2));
            if(dd < 1 || dd > 31 || mm < 1 || mm > 12 || yy < 0 || yy > 21){
                std::cout << " Bad input. Try again!" << std::endl;
                ValueTrue = false;
            }
        } while (!ValueTrue);
        do{
            ValueTrue = true;
            std::cout << "Enter the value of payment: ";
            std::cin >> TmpValue.Payment;
            if(TmpValue.Payment <= 0){
                std::cout << " Bad input. Try again!" << std::endl;
                ValueTrue = false;
            }
        }while (!ValueTrue);
        std::ofstream PaymentFile("../PaymentFile.txt",std::ios::app);
        PaymentFile << TmpValue.FirstName << " " << TmpValue.LastName << " " << TmpValue.DateOfPayment
        << " " << TmpValue.Payment << std::endl;
        PaymentFile.close();
    }
    return 0;
}
