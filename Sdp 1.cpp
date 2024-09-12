#include <stdlib.h>
#include <iostream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <mysql_error.h>
#include<iomanip>


using namespace std;

const string server = "tcp://127.0.0.1:3306";
const string username = "root";
const string password = "root->246624";
const string green = "\033[1;32m";
void show();
void finishingShow();

//for demonstration only never save your password in the code!
sql::Driver* driver;
sql::Connection* con;
sql::Statement* stmt;
sql::PreparedStatement* pstmt;
sql::ResultSet* res;



class University {
public:
    
    float SscGrade, HscGrade;
    int HscPassedYear;
    void GradeInitial(float a, float b, int c) {
        SscGrade = a;
        HscGrade = b;
        HscPassedYear = c;
        int SumOfGrade = SscGrade + HscGrade;
        if (SumOfGrade <= 0 && SumOfGrade > 10) {
            cout << "Invalid GPA \n";
        }

        else if ((SumOfGrade >= 7.5 && SumOfGrade <=10) && (HscPassedYear == 2022 || HscPassedYear == 2021 || HscPassedYear == 2020)) {

            //for retrieving data
            stmt = con->createStatement();
            res = stmt->executeQuery("SELECT* FROM Uni_list");

            //instruction for columns name and design
            cout << left << setw(65) << "University Name"
                << left << setw(45) << "Departments"
                << right << setw(10) << "Tuition Fees" << endl;

            for (int i = 1; i <= 120; i++) {
                cout << "-";
            }
            cout << "\n";

            
            while (res->next()) {
                cout << left <<setw(65) << res->getString(1)<< left << setw(45) << res->getString(2)
                    << left << setw(10) << res->getInt(3) << endl;
            }
            delete res;
           
            cout << endl;
            cout << "You are eligible for admission tests in all of these Universities\n\n";
            system("pause");
        }
        else {
            cout << "*There is no University for this academic result*\n";
            system("pause");
        }
    }

    int budget;
    //Member function for showing budget base information
    void BudgetBaseInfo(int y) {
        budget = y;
        stmt = con->createStatement();


        for (int i = 1; i < 2; i++) {

            if (budget > 500000 && budget <= 600000) {
                res = stmt->executeQuery("SELECT* FROM Uni_list WHERE Tuition_fees <600000");

                while (res->next()) {
                    cout << left << setw(65) << res->getString(1)
                        << left << setw(45) << res->getString(2)
                        << left << setw(10) << res->getInt(3) << endl;
                }
                delete stmt;
            }
            else if (budget > 600000 && budget <= 700000) {
                res = stmt->executeQuery("SELECT* FROM Uni_list WHERE Tuition_fees <700000");

                while (res->next()) {
                    cout << left << setw(65) << res->getString(1)
                        << left << setw(45) << res->getString(2)
                        << right << setw(10) << res->getInt(3) << endl;
                }
                delete stmt;
            }
            else if (budget > 700000 && budget <= 800000) {
                res = stmt->executeQuery("SELECT* FROM Uni_list WHERE Tuition_fees <800000");

                while (res->next()) {
                    cout << left << setw(65) << res->getString(1)
                        << left << setw(45) << res->getString(2) << endl;
                }
                delete stmt;
            }
            else if (budget > 800000 && budget <= 900000) {
                res = stmt->executeQuery("SELECT* FROM Uni_list WHERE Tuition_fees <900000");

                while (res->next()) {
                    cout << left << setw(65) << res->getString(1)
                        << left << setw(45) << res->getString(2) << endl;
                }
                delete stmt;
            }
            else if (budget > 900000 && budget <= 1000000) {
                res = stmt->executeQuery("SELECT* FROM Uni_list WHERE Tuition_fees <1000000");

                while (res->next()) {
                    cout << left << setw(65) << res->getString(1)
                        << left << setw(45) << res->getString(2) << endl;
                }
                delete stmt;
            }
            else if (budget > 1000000 && budget <= 1100000) {
                res = stmt->executeQuery("SELECT* FROM Uni_list WHERE Tuition_fees <1100000");

                while (res->next()) {
                    cout << left << setw(65) << res->getString(1)
                        << left << setw(45) << res->getString(2) << endl;
                }
                delete stmt;
            }
            else if (budget > 1100000 && budget <= 1200000) {
                res = stmt->executeQuery("SELECT* FROM Uni_list WHERE Tuition_fees <1200000");

                while (res->next()) {
                    cout << left << setw(65) << res->getString(1)
                        << left << setw(45) << res->getString(2) << endl;
                }
                delete stmt;
            }
            else if (budget > 1200000 && budget <= 1300000) {
                res = stmt->executeQuery("SELECT* FROM Uni_list WHERE Tuition_fees <1300000");

                while (res->next()) {
                    cout << left << setw(65) << res->getString(1)
                        << left << setw(45) << res->getString(2) << endl;
                }
                delete stmt;
            }
            else {
                cout << "*There is no available University for this Budget*\n";
                system("pause");
            }
        }

    }

    //Another Member function for showing department base information
    void DepartmentBaseInfo() {

        stmt = con->createStatement();

        int department;
        cout << "\n\n";
        cout << "You want to see Spacific Department-\n";
        cout << "\t\t\t" << "1. Computer Science and Engineering\n"
            << "\t\t\t" << "2. Electrical Electronic and Engineering\n"
            << "\t\t\t" << "3. Civil Engineering\n"
            << "\t\t\t" << "4. Electronic & Telecommunication Engineering\n"
            << "\t\t\t" << "5. Electronic & Communication Engineering\n"
            << "\t\t\t" << "6. Industrial & Production Engineering\n"
            << "\t\t\t" << "7. Software Engineering\n"
            << "\t\t\t" << "8. Genetic Engineering & Biotechnology\n"
            << "\t\t\t" << "9. Textile Engineering\n"
            << "\t\t\t" << "10. Information & Communications Engineering\n" << endl;


        cout << "Choose your Department-\n";
        cin >> department;

        //another loop for Specific Department-
        for (int i = 1; i < 2; i++) {

            cout << left << setw(65) << "University Name"
                << left << setw(45) << "Departments"
                << left << setw(10) << "Credit" << endl;

            for (int i = 1; i <= 117; i++) {
                cout << "-";
            }
            cout << "\n";

            switch (department) {
            case 1:
                res = stmt->executeQuery("SELECT * FROM Department_single WHERE Department='Computer Science & Engineering'");

                while (res->next()) {
                    cout << left << setw(65) << res->getString(1)
                        << left << setw(45) << res->getString(2)
                        << right << setw(10) << res->getInt(3) << endl;
                }
                delete stmt;
                break;

            case 2:
                res = stmt->executeQuery("SELECT * FROM Department_single WHERE Department='Electrical Electronic and Engineering'");

                while (res->next()) {
                    cout << left << setw(65) << res->getString(1)
                        << left << setw(45) << res->getString(2)
                        << left << setw(10) << res->getInt(3) << endl;
                }
                delete stmt;
                break;
            case 3:
                res = stmt->executeQuery("SELECT * FROM Department_single WHERE Department='Civil Engineering'");

                while (res->next()) {
                    cout << left << setw(65) << res->getString(1)
                        << left << setw(45) << res->getString(2)
                        << left << setw(10) << res->getInt(3) << endl;
                }
                delete stmt;
                break;
            case 4:
                res = stmt->executeQuery("SELECT * FROM Department_single WHERE Department='Electronic & Telecommunication Engineering'");

                while (res->next()) {
                    cout << left << setw(65) << res->getString(1)
                        << left << setw(45) << res->getString(2)
                        << left << setw(10) << res->getInt(3) << endl;
                }
                delete stmt;
                break;
            case 5:
                res = stmt->executeQuery("SELECT * FROM Department_single WHERE Department='Elctronic & Communication Engineering'");

                while (res->next()) {
                    cout << left << setw(65) << res->getString(1)
                        << left << setw(45) << res->getString(2)
                        << left << setw(10) << res->getInt(3) << endl;
                }
                delete stmt;
                break;
            case 6:
                res = stmt->executeQuery("SELECT * FROM Department_single WHERE Department='Industrial & Production Engineering'");

                while (res->next()) {
                    cout << left << setw(65) << res->getString(1)
                        << left << setw(45) << res->getString(2)
                        << left << setw(10) << res->getInt(3) << endl;
                }
                delete stmt;
                break;
            case 7:
                res = stmt->executeQuery("SELECT * FROM Department_single WHERE Department='Software Engineering'");

                while (res->next()) {
                    cout << left << setw(65) << res->getString(1)
                        << left << setw(45) << res->getString(2)
                        << left << setw(10) << res->getInt(3) << endl;
                }
                delete stmt;
                break;
            case 8:
                res = stmt->executeQuery("SELECT * FROM Department_single WHERE Department='Genetic Engineering & Biotechnology'");

                while (res->next()) {
                    cout << left << setw(65) << res->getString(1)
                        << left << setw(45) << res->getString(2)
                        << left << setw(10) << res->getInt(3) << endl;
                }
                delete stmt;
                break;
            case 9:
                res = stmt->executeQuery("SELECT * FROM Department_single WHERE Department='Textile Engineering'");

                while (res->next()) {
                    cout << left << setw(65) << res->getString(1)
                        << left << setw(45) << res->getString(2)
                        << left << setw(10) << res->getInt(3) << endl;
                }
                delete stmt;
                break;
            case 10:
                res = stmt->executeQuery("SELECT * FROM Department_single WHERE Department='Information & Communications Engineering'");

                while (res->next()) {
                    cout << left << setw(65) << res->getString(1)
                        << left << setw(45) << res->getString(2)
                        << left << setw(10) << res->getInt(3) << endl;
                }
                delete stmt;
                break;
            default:
                cout << "*Choose does not match or this Department is not availabe in any University*\n\n" << endl;
                system("pause");
            }
        }
    }

};

//another class 
class University_indivisual {

public:
    // 1st Function for showing Fee Structure
    void FeeStructure(string x) {
        stmt = con->createStatement();
        string press = x;
        if (press == "Yes" || press == "yes") {
            //cout << "Fee Structure of Universities-\n";
            cout << left << std::setw(65) << "University Name"
                << std::left << std::setw(15) << "Installment"
                << std::right << std::setw(10) << "Scholarship" << std::endl;

            for (int i = 1; i <= 90; i++) {
                cout << "-";
            }
            cout << "\n";

            res = stmt->executeQuery("SELECT * FROM Indivisual_uni1");
            while (res->next()) {
                cout << left << setw(65) << res->getString(1)
                    << left << setw(15) << res->getString(2)
                    << left << setw(12) << res->getString(3) << endl << endl;;
            }
            delete stmt;
        }
    }

    //2nd function for showing admission criteria
    void AdmissionCriteria(string x) {
        stmt = con->createStatement();
        
        string press = x;
        cout << "\t\t\tCriteria of a admission test-\n";
        if (press == "Yes" || press == "yes") {
            cout << left << setw(65) << "University Name"
                << left << setw(8) << "GPA"
                << left << setw(15) << "Mathmatics"
                << left << setw(10) << "Physics" << endl;

            for (int i = 1; i <= 98; i++) {
                cout << "-";
            }
            cout << "\n";

            res = stmt->executeQuery("SELECT * FROM Indivisual_uni2");
            while (res->next()) {
                cout << left << setw(65) << res->getString(1)
                    << left << setw(8) << res->getInt(2)
                    << left << setw(15) << res->getString(3)
                    << left << setw(10) << res->getString(4) <<endl<< endl;
            }
            delete stmt;
        }
    }

};

    int main() {
        cout<<"\033[1;32m";
        show();
        system("pause");

        //Connecting database using c++ Exception
        try
        {
            driver = get_driver_instance();
            con = driver->connect(server, username, password);
            con->setSchema("University_Info");
        }
        catch (sql::SQLException e)
        {
            cout << "Could not connect to server. Error message: " << e.what() << endl;
            system("pause");
            exit(1);
        }
        cout << endl << endl;

        float SscGrade, HscGrade;
        int HscPassedYear;

        cout << green << "\t\t\t Give your Secondary School Certificate (SSC) Grade: ";
        cin >> SscGrade;

        cout << green << "\t\t\tGive your Higher Secondary School Certificate (HSC) Grade: ";
        cin >> HscGrade;

        cout << green << "\t\t\tPassed Year of HSC: ";
        cin >> HscPassedYear;

        system("cls");
        University Level1;
        Level1.GradeInitial(SscGrade, HscGrade, HscPassedYear);
        

        int Budget;
        cout << "\t\t\tTell me your Budget for matching you with a Spacific University\n\n";
        cout << "\t\t\tYour Budget - ";
        cin >> Budget;

        //calling two member function of 'University' class
        Level1.BudgetBaseInfo(Budget);
        Level1.DepartmentBaseInfo();

        string press, press2;
        cout << "\t\t\tDo you want to know Fee Structure of Universities- Press 'Yes'\n";
        cout << "\t\t\tPress - ";
        cin >> press;

        //calling a member function of 'University_indivisual' class
        University_indivisual Level3;
        Level3.FeeStructure(press);
        //system("cls");
        
        cout << "\t\t\tDo you want to know Admission Criteria of Universities- Press 'Yes'\n";
        cout << "\t\t\tPress - ";
        cin >> press2;
        Level3.AdmissionCriteria(press2);
        finishingShow();
        return 0;
    }
    void show() {

        std::cout << "\t\t\t\t\t+-----------------------+" << std::endl;
        std::cout << "\t\t\t\t\t|  Welcome to Unifind   |" << std::endl;
        std::cout << "\t\t\t\t\t+-----------------------+" << std::endl;
        cout << "\t\t\t\tI'm your assistant to help you get Information\n \t\t\t\tabout all the University of Bangladesh--\n";
    }
    void finishingShow() {
        cout << "\n\n";
        cout << "\t\t\t\t+--------------------------------+" << endl;
        cout << "\t\t\t\t| Thank you for your Exploration |" << endl;
        cout << "\t\t\t\t+--------------------------------+" << endl;
        
    }