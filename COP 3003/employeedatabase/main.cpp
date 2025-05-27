#include <iostream>
#include <string>

class Employee {
protected:

    char name[20];
    int id;

public:

    void setDetails() {

        std::cout << "\nEnter name:";
        std::cin >> name;

        // cin.ignore clears the previous input, so it is possible to use the other input prompts
        std::cin.ignore(20, '\n');

        std::cout << "Enter ID:";
        std::cin >> id;

    }
    void getDetails() {

        std::cout << "Name: " << name << std::endl;
        std::cout << "ID: " << id << std::endl;

    }

};

class Account : virtual public Employee {
protected:

    float pay;

public:

    void setPay() {

        std::cout << "Enter the pay amount:";
        std::cin >> pay;

    }
    void getPay() {

        std::cout << "Pay amount: $" << pay << std::endl;

    }

};

class Admin : virtual public Employee {
protected:

    int exp;

public:

    void setExp() {

        std::cout << "Enter amount of experience (in years):";
        std::cin >> exp;

    }

    void getExp() {

        std::cout << "Experience (in years): " << exp << std::endl;

    }

};

class Master : public Account, public Admin {
private:
    int choice;
public:

    // Function that updates the employee's info in one go
    void addInfo() {

        std::cout << "\n\n//////////INSERT DETAILS///////////\n" << std::endl;
        setDetails();
        setPay();
        setExp();

    }

    // shows the employee's details
    void displayInfo() {

        std::cout << "\n\n//////////DISPLAY DETAILS//////////\n" << std::endl;
        getDetails();
        getPay();
        getExp();

    }

    // Dedicated function to edit one of the details at a time
    void updateInfo() {

        std::cout << "\n\n/////////UPDATE DETAILS/////////\n" << std::endl;
        std::cout << "\n\nChoose the detail you want to change\n";
        std::cout << "(1) NAME\n";
        std::cout << "(2) ID\n";
        std::cout << "(3) PAY\n";
        std::cout << "(4) EXPERIENCE\n";

        std::cout << "Enter your choice:";

        std::cin >> choice;
        std::cin.ignore(20, '\n');

        switch (choice) {

            case 1:

                std::cout << "Enter name: ";
                std::cin >> name;
                break;

            case 2:

                std::cout << "Enter ID: ";
                std::cin >> id;
                break;

            case 3:

                std::cout << "Enter the pay amount: ";
                std::cin >> pay;
                break;

            case 4:

                std::cout << "Enter experience (in years): ";
                std::cin >> exp;
                break;

            default:

                std::cout << "\n\nInvalid choice.\n\n";

        }
        

    }

    //The main menu that loops after putting in all the users input
    void mainScreen() {

        while (true) {

            std::cout << "\n\n/////////EMPLOYEE DATABASE/////////\n" << std::endl;
            std::cout << "\nChoose the action you want to take\n";
            std::cout << "(1) Create Record\n";
            std::cout << "(2) Display Record\n";
            std::cout << "(3) Update Record\n";
            std::cout << "(4) Exit\n";
            std::cout << "\nEnter your choice:";
            std::cin >> choice;
            std::cin.ignore(20, '\n');

            switch (choice) {

                case 1:

                    addInfo();
                    break;

                case 2:

                    displayInfo();
                    break;

                case 3:

                    updateInfo();
                    break;

                case 4:

                    // Exits out of the program
                    exit(true);

                default:

                    std::cout << "\n\nInvalid choice.\nPlease try again.\n\n";

            }

        }

    }

};

int main() {

    Master employee1;
    employee1.mainScreen();

    return 0;
}
