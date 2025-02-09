#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

void printVector(vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}

vector<string> split(string text) {
    string word;
    vector<string> vec;
    istringstream stream(text);

    while (stream >> word) {
        vec.push_back(word);
    }

    return vec;
}

void saveData(string name, string password, double balance, double credit, double loan, double creditLimit) {
    cout << "Entering saveData function" << endl;

    ifstream bankDB("bankDB.txt");
    if (!bankDB.is_open()) {
        cout << "Failed to open file for reading." << endl;
        return;
    }

    string balanceStr = to_string(balance);
    string creditStr = to_string(credit);
    string loanStr = to_string(loan);
    string creditLimitStr = to_string(creditLimit);
    vector<string> fileContent;
    string line;

    while (getline(bankDB, line)) {
        fileContent.push_back(line);
    }

    bankDB.close();

    bool userFound = false;
    for (int i = 0; i < fileContent.size(); i++) {
        vector<string> lineSplit = split(fileContent[i]);
        if (lineSplit.size() >= 3 && lineSplit[0] == name && lineSplit[1] == password) {
            fileContent[i] = name + ' ' + password + ' ' + balanceStr + ' ' + creditStr + ' ' + loanStr + ' ' + creditLimitStr;
            cout << "FOUND NAME" << endl;
            cout << fileContent[i] << endl;
            userFound = true;
            break;
        }
    }

    if (!userFound) {
        cout << "User not found while saving data." << endl;
    }

    ofstream bankDBOf("bankDB.txt");
    if (bankDBOf.is_open()) {
        for (int i = 0; i < fileContent.size(); i++) {
            bankDBOf << fileContent[i] << endl;
        }
        bankDBOf.close();
    } else {
        cout << "Failed to open file for writing." << endl;
    }

    cout << "Exiting saveData function" << endl;
}

bool findUser(string name) {
    cout << "Entering findUser function" << endl;

    ifstream bankDB("bankDB.txt");
    if (!bankDB.is_open()) {
        cout << "Failed to open file for reading." << endl;
        return false;
    }

    string line;
    while (getline(bankDB, line)) {
        vector<string> lineVector = split(line);
        if (lineVector.size() >= 1 && lineVector[0] == name) {
            cout << "Exiting findUser function" << endl;
            return true;
        }
    }

    cout << "Exiting findUser function" << endl;
    return false;
}

vector<string> findUserInfo(string name) {
    cout << "Entering findUserInfo function" << endl;

    vector<string> v;

    ifstream bankDB("bankDB.txt");
    if (!bankDB.is_open()) {
        cout << "Failed to open file for reading." << endl;
        return v;
    }

    string line;
    while (getline(bankDB, line)) {
        vector<string> lineVector = split(line);
        if (lineVector.size() >= 1 && lineVector[0] == name) {
            return lineVector;
        }
    }

    cout << "Exiting findUserInfo function" << endl;
    return v;
}

void createAccount(string name, string password) {
    cout << "Entering createAccount function" << endl;

    double initDeposit = 500;
    double initCredit = 0;
    double initLoan = 0;
    double initCreditLimit = 1000; // Default creditLimit
    ofstream bankDB("bankDB.txt", ios::app);
    if (bankDB.is_open()) {
        bankDB << name << ' ' << password << ' ' << initDeposit << ' ' << initCredit << ' ' << initLoan << ' ' << initCreditLimit << endl;
        bankDB.close();
    } else {
        cout << "Failed to open file for writing." << endl;
    }

    cout << "Exiting createAccount function" << endl;
}

vector<string> login(string name, string password) {
    cout << "Entering login function" << endl;

    vector<string> v;
    ifstream bankDB("bankDB.txt");

    if (!bankDB.is_open()) {
        cout << "Failed to open file for reading." << endl;
        return v;
    }

    string line;
    while (getline(bankDB, line)) {
        vector<string> lineVector = split(line);
        if (lineVector.size() >= 6 && lineVector[0] == name && lineVector[1] == password) {
            bankDB.close();
            return lineVector;
        }
    }

    bankDB.close();
    cout << "Exiting login function" << endl;
    return v;
}

class Account {
    public:
        string name = "";
        string password = "";
        double balance = 500;
        double credit = 0; // Initial credit available
        double loan = 0;   // Outstanding loan
        double creditLimit = 1000; // Initial credit limit

        void deposit(double amount) {
            this->balance += amount;
        }

        void withdraw(double amount) {
            if (amount > this->balance) {
                cout << "Insufficient funds. Using credit..." << endl;
                double creditNeeded = amount - this->balance;
                if (creditNeeded <= this->credit) {
                    this->credit -= creditNeeded;
                    this->balance = 0;
                } else {
                    cout << "Not enough credit available." << endl;
                    return;
                }
            } else {
                this->balance -= amount;
            }
        }

        void displayBalance() {
            cout << "Balance: " << this->balance << " dollars" << endl;
        }

        void displayName() {
            cout << "Account Name: " << this->name << endl;
        }

        void useCreditCard(double amount) {
            // Check if the creditLimit is reached
            if ((this->credit + amount) > creditLimit) {
                cout << "Transaction declined. Exceeds available credit limit." << endl;
                return;
            }

            this->credit += amount;
            this->balance -= amount;

            cout << "Credit used: " << amount << " dollars" << endl;
            cout << "New credit available: " << this->credit << " dollars" << endl;
            cout << "New balance: " << this->balance << " dollars" << endl;
        }

        void applyLoan(double amount) {
            double maxLoanAmount = this->balance * 2; // Only allow 2 times the balance
            if (amount > maxLoanAmount) {
                cout << "Loan request denied as it was unreasonable" << endl;
                return;
            }

            this->loan += amount; // Increase the loan amount
            this->balance += amount; // Add loan amount to balance

            // Apply immediate interest charge
            double interest = amount * 0.05; // 5% interest
            this->balance -= interest; // Deduct interest from the balance

            cout << "Loan of " << amount << " dollars has been applied." << endl;
            cout << "Interest of " << interest << " dollars has been deducted." << endl;
        }

        void payOffCreditCard(double amount) {
            if (amount > this->balance) {
                cout << "Insufficient funds to pay off credit card balance." << endl;
                return;
            }

            if (amount > this->credit) {
                cout << "Payment amount exceeds credit card balance." << endl;
                return;
            }

            this->balance -= amount;
            this->credit -= amount;

            cout << "Paid off " << amount << " dollars from credit card balance." << endl;
            cout << "New credit available: " << this->credit << " dollars" << endl;

            // Increase credit limit based on payment
            increaseCreditLimit(amount);
        }

        void payOffLoan(double amount) {
            if (amount > this->balance) {
                cout << "Insufficient funds to pay off loan" << endl;
                return;
            }

            if (amount > this->loan) {
                cout << "Amount exceeds outstanding loan balance." << endl;
                return;
            }

            this->balance -= amount;
            this->loan -= amount;

            double gainedCredit = amount * 0.05; // 5% of loaned amount will be gained as credit
            this->credit += gainedCredit;

            cout << "Paid off: " << amount << " dollars" << endl;
            cout << "Credit gained: " << gainedCredit << " dollars" << endl;
            cout << "Loan left: " << loan << " dollars" << endl;
            cout << "Balance left: " << balance << " dollars" << endl;
        }

        void save() {
            saveData(this->name, this->password, this->balance, this->credit, this->loan, this->creditLimit);
        }

    private:
        void increaseCreditLimit(double paymentAmount) {
            // Increase limit by a percentage of the payment amount
            double increaseAmount = paymentAmount * 0.1; // 10% of the payment amount
            this->creditLimit += increaseAmount;
        }
};

int menu() {
    string message = "\nOptions\n1. Create an account\n2. Login\n3. Exit";
    int option;

    cout << message << endl;
    cout << "\nOption: ";
    cin >> option;
    cout << endl;

    return option;
}

int menuLoggedIn() {
    string message = "\nOptions\n1. Deposit\n2. Withdraw\n3. Transfer\n4. Use Credit Card\n5. Apply for Loan\n6. Pay Off Credit Card\n7. Pay Off Loans\n\n8. Display account info\n\n9. Exit";
    int option;

    cout << message << endl;
    cout << "\nOption: ";
    cin >> option;
    cout << endl;

    return option;
}

int main() {
    bool loggedIn = false;
    bool logInEndProgram = false;
    vector<string> userInfo;

    while (!loggedIn) {
        int option = menu();

        if (option == 1) { // Create an account
            string name = "";
            string password = "";

            cout << "\nEnter your name: ";
            cin >> name;

            if (findUser(name)) {
                cout << "\nUsername already taken, please try again later" << endl;
                continue;
            }

            cout << "\nEnter your desired password: ";
            cin >> password;

            createAccount(name, password);
            userInfo.push_back(name);
            userInfo.push_back(password);
            userInfo.push_back("500"); // initial balance
            userInfo.push_back("0"); // initial credit
            userInfo.push_back("0"); // initial loan
            userInfo.push_back("1000"); // initial credit limit
            loggedIn = true;

        // Login
        } else if (option == 2) {
            string name = "";
            string password = "";

            cout << "\nEnter your name: ";
            cin >> name;

            cout << "\nEnter your password: ";
            cin >> password;

            vector<string> loginResult = login(name, password);

            if (loginResult.size() >= 6) {
                userInfo = loginResult;
                loggedIn = true;

            } else {
                cout << "\nAccount not found" << endl;
            }

        // Exit
        } else if (option == 3) {
            logInEndProgram = true;
            break;
        } else {
            cout << "Unhandled case in LoggedIn Loop" << endl;
        }
    }

    if (loggedIn) {
        cout << "Successfully logged in. Initializing user account." << endl;
        Account user;
        user.name = userInfo[0];
        user.password = userInfo[1];
        user.balance = stod(userInfo[2]);
        user.credit = stod(userInfo[3]);
        user.loan = stod(userInfo[4]);
        user.creditLimit = stod(userInfo[5]);

        cout << "User name: " << user.name << endl;
        cout << "User password: " << user.password << endl;
        cout << "User balance: " << user.balance << endl;

        bool finished = false;

        while (!logInEndProgram && !finished) {
            int option = menuLoggedIn();

            // Deposit
            if (option == 1) {
                double amount;
                cout << "\nEnter the amount you want to deposit: ";
                cin >> amount;
                cout << endl;

                user.deposit(amount);
                cout << "\nYou now have " << user.balance << " dollars" << endl;
                user.save();

            // Withdraw
            } else if (option == 2) {
                double amount;
                cout << "\nEnter the amount you want to withdraw: ";
                cin >> amount;
                cout << endl;

                user.withdraw(amount);
                cout << "\nYou now have " << user.balance << " dollars left" << endl;
                user.save();

            // Transfer
            } else if (option == 3) {
                string transfereeName = "";
                cout << "\nEnter the account name to transfer to: ";
                cin >> transfereeName;
                cout << endl;

                if (transfereeName == user.name) {
                    cout << "\nYou cannot transfer to yourself" << endl;
                    continue;
                }

                if (findUser(transfereeName)) {
                    vector<string> transfereeInfo = findUserInfo(transfereeName);
                    if (transfereeInfo.size() >= 6) {
                        Account transferee;

                        transferee.name = transfereeInfo[0];
                        transferee.password = transfereeInfo[1];
                        transferee.balance = stod(transfereeInfo[2]);
                        transferee.credit = stod(transfereeInfo[3]);
                        transferee.loan = stod(transfereeInfo[4]);
                        transferee.creditLimit = stod(transfereeInfo[5]);

                        double amount;
                        cout << "\nEnter the amount you want to transfer: ";
                        cin >> amount;
                        cout << endl;

                        if (amount > user.balance) {
                            cout << "Insufficient funds for transfer." << endl;
                            continue;
                        }

                        transferee.deposit(amount);
                        user.withdraw(amount);

                        cout << "\n" << amount << " has been transferred!" << endl;
                        cout << "\nYou now have " << user.balance << " dollars left" << endl;

                        user.save();
                        transferee.save();
                    } else {
                        cout << "\nUsername not found" << endl;
                    }
                } else {
                    cout << "\nUsername not found" << endl;
                }

            // Use Credit Card
            } else if (option == 4) {
                double amount;
                cout << "\nEnter the amount of credit to use: ";
                cin >> amount;
                cout << endl;

                user.useCreditCard(amount);
                cout << "\nYou now have " << user.credit << " dollars of credit available" << endl;
                user.save();

            // Apply for Loan
            } else if (option == 5) {
                double amount;
                cout << "\nEnter the amount of loan to apply for: ";
                cin >> amount;
                cout << endl;

                user.applyLoan(amount);
                cout << "\nYour new balance is " << user.balance << " dollars" << endl;
                cout << "\nYour outstanding loan is " << user.loan << " dollars" << endl;
                user.save(); // Save user data after applying for loan

            // Pay Off Credit Card
            } else if (option == 6) {
                double amount;
                cout << "\nEnter the amount to pay off the credit card: ";
                cin >> amount;
                cout << endl;

                user.payOffCreditCard(amount);
                user.save();

            // Pay Off Loans
            } else if (option == 7) {
                double amount;
                cout << "\nEnter the amount to pay off the loans: ";
                cin >> amount;
                cout << endl;

                user.payOffLoan(amount);
                user.save();

            // Display account info
            } else if (option == 8) {
                cout << "\n\tName: " << user.name << endl;
                cout << "\n\tBalance: " << user.balance << endl;
                cout << "\n\tCredit: " << user.credit << endl;
                cout << "\n\tOutstanding loan: " << user.loan << endl;
                cout << "\n\tCredit Limit: " << user.creditLimit << endl;

            // Exit
            } else if (option == 9) {
                finished = true;

            } else {
                cout << "Invalid option, please try again." << endl;
            }
        }
    }

    return 0;
}
