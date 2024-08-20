//CS300 Project 2
//Josh Lyons
// 08/19/2024

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;




// Global definitions


struct Course {
    string CourseId; // unique identifier
    string title;
    vector<string> prereq;
    
};





// print menu function
// prints menu
void printMenu() {

    cout << "Menu:" << endl;
    cout << "  1. Load Courses" << endl;
    cout << "  2. Display All Courses" << endl;
    cout << "  3. Search By Course ID" << endl;
    cout << "  9. Exit" << endl;


}



// prints course info from a list
vector<Course> displayCourses(vector <Course> course) {
    cout << endl << endl;
    for (int i = 0; i < course.size(); i++) {
        cout << "Course ID: " << course[i].CourseId << endl << "Title: " << course[i].title << endl;
        cout << "Prerequisites: ";
        for (int v = 0; v < course[i].prereq.size(); v++) {
            cout << course[i].prereq[v] << ", ";
        }
        cout << endl << endl << endl;
    }

    return course;
}
// prints course info from a single course structure
void displayCourses(Course course) {
    cout << endl << endl;
    cout << "Course ID: " << course.CourseId << endl << "Title: " << course.title << endl;
    cout << "Prerequisites: ";
    for (int v = 0; v < course.prereq.size(); v++) {
        cout << course.prereq[v] << ", ";
    }
    
}

// compares courseID for basic sort function
bool compareCourses(const Course& course1, const Course& course2) {
    return course1.CourseId < course2.CourseId;
};

// sorts data alphanumerically
void sortCourses(vector<Course> courses) {
    sort(courses.begin(), courses.end(), compareCourses);
    displayCourses(courses);
}

// loading the CSV data
vector<Course> loadCourses() {
    string csvPath;
    vector<string> row;
    string line, word;
    cout << "Enter the filepath for your file, or type 'default'" << endl;
    cin >> csvPath;
    if (csvPath == "default" || "'default'") {
        csvPath = "CS 300 ABCU_Advising_Program_Input.csv";
    };

    vector<Course> courses;
    cout << "Loading file..." << endl;
    fstream fin;
    fin.open(csvPath, ios::in); // opens file


    while (!fin.eof()) {
        while (getline(fin, line)) {
            stringstream ss(line);
            string token;
            Course course;
            getline(ss, course.CourseId, ',');
            getline(ss, course.title, ',');
            while (getline(ss, token, ',')) {
                
                    course.prereq.push_back(token);
                
                // parsing through lines
            }
            if (course.prereq.empty()) {
                course.prereq.push_back("None");
            }
            courses.push_back(course);
            
        }
        

       
        




     }
        
    cout << "File loaded successfully." << endl;
        return courses;

   
}










// find course by id
void findCourse(const vector<Course>& courses, const string& courseId) {
    for (int i = 0; i < courses.size(); i++) {
        if (courses[i].CourseId == courseId) {
            cout << endl << endl;
            displayCourses(courses[i]);
            cout << endl << endl;
            return;
        }

    }
    cout << "Course not found." << endl;

}




// main function
int main()
{
    vector<Course> allcourses;
    int choice = 0;
    string courseID;
    while (choice != 9) {


        printMenu();
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            allcourses = loadCourses();
            break;
        case 2:
            sortCourses(allcourses);
            break;

        case 3:
            cout << "Enter course ID: ";
            cin >> courseID;
            findCourse(allcourses, courseID);
            break;

        case 9:
            exit;
            break;

        default:
            cout << "Invalid menu option." << endl;
            main();

        };
        


    }



    

}