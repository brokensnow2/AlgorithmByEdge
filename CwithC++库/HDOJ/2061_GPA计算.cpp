#include <iostream> // Include the iostream library to allow for input/output operations
#include <iomanip>  // Include the iomanip library to manipulate the output of the program

using namespace std; // Use the standard namespace

int main() { // Start of the main function
    int N; // Declare an integer N to store the number of test cases
    cin >> N; // Input the number of test cases

    while(N--) { // Loop through each test case
        int K; // Declare an integer K to store the total number of courses
        cin >> K; // Input the total number of courses

        double totalScore = 0, totalCredit = 0; // Declare and initialize totalScore and totalCredit to store the total score and total credit respectively

        bool isFailed = false; // Declare and initialize a boolean isFailed to check if the student has failed any course

        while(K--) { // Loop through each course
            string courseName; // Declare a string courseName to store the name of the course
            double credit, score; // Declare credit and score to store the credit and score of the course respectively

            cin >> courseName >> credit >> score; // Input the course name, credit, and score

            if(score < 60) { // If the score is less than 60
                isFailed = true; // Set isFailed to true
            }

            totalScore += credit * score; // Add the product of credit and score to totalScore
            totalCredit += credit; // Add the credit to totalCredit
        }

        if(isFailed) { // If the student has failed any course
            cout << "Sorry!" << endl; // Output "Sorry!"
        } else { // If the student has not failed any course
            cout << fixed << setprecision(2) << totalScore / totalCredit << endl; // Output the GPA rounded to 2 decimal places
        }

        if(N) { // If there are more test cases
            cout << endl; // Output a blank line
        }
    }

    return 0; // End of the main function
}
