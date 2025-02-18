#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


float getGradePoint(char grade) {
    switch (toupper(grade)) {
        case 'A': return 4.0;
        case 'B': return 3.0;
        case 'C': return 2.0;
        case 'D': return 1.0;
        case 'F': return 0.0;
        default: return -1; 
    }
}

int main() {
    int numSemesters;
    cout << "Enter number of semesters: ";
    cin >> numSemesters;

    float totalGradePoints = 0, totalCredits = 0;

    for (int sem = 1; sem <= numSemesters; sem++) {
        int numCourses;
        cout << "\nEnter number of courses for semester " << sem << ": ";
        cin >> numCourses;

        float semesterGradePoints = 0, semesterCredits = 0;

        for (int i = 1; i <= numCourses; i++) {
            float credits;
            char grade;
            
            cout << "Enter credit hours for course " << i << ": ";
            cin >> credits;
            
            cout << "Enter grade (A, B, C, D, F) for course " << i << ": ";
            cin >> grade;

            float gradePoint = getGradePoint(grade);
            if (gradePoint == -1) {
                cout << "Invalid grade entered! Please enter a valid grade.\n";
                i--;  // Retry the same course input
                continue;
            }

            semesterGradePoints += (gradePoint * credits);
            semesterCredits += credits;
        }

        float semesterGPA = semesterGradePoints / semesterCredits;
        cout << fixed << setprecision(2);
        cout << "GPA for Semester " << sem << ": " << semesterGPA << "\n";

        totalGradePoints += semesterGradePoints;
        totalCredits += semesterCredits;
    }

    float CGPA = totalGradePoints / totalCredits;
    cout << "\nFinal CGPA: " << fixed << setprecision(2) << CGPA << "\n";

    return 0;
}