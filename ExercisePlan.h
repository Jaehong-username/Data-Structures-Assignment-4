/******************************************************************************************************************
* Programmer: Jaehong Lee
* Class: CptS 122, Fall 2023; Lab Section 3 (Tuesday 1:30PM - 4:20PM)
* Programming Assignment: PA4
* Date: October 17, 2023
* Description: This PA assignment is creating a Fitness Application program using C++, an object-oriented language.
*              This program makes use of three different classes called ExercisePlan, DietPlan, and FitnessAppWrapper.
*              ExercisePlan class deals with data from exercisePlans.txt, and DietPlan deals with data from
*              dietPlans.txt. Lastly, FitnessAppWrapper has all methods needed for the correct implementation of the
*              Fitness Application program.
******************************************************************************************************************/

#pragma once

#include <iostream>

#include <string>

#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

//description of a class: what is this exercisplan being used for?? 
//

/********************************************************************************************************************
* Class name: ExercisePlan
* Description: This class stores an overall blueprit of methods and variables needed for either extraction of data 
*              from exercisePlans.txt file or output of data into console, or exercisePlans.txt file. 
*********************************************************************************************************************/
class ExercisePlan //used to represent a daily exercise plan
{
public:

	ExercisePlan(); //default constructor
	ExercisePlan(int new_goal_steps, string plan_name, string date);
	ExercisePlan(const ExercisePlan& copy); //copy constructror


	//destructor
	~ExercisePlan();


	//getter and setter function
	int get_goal_steps();
	void set_goal_steps(const int new_goal_steps);

	string get_plan_name();
	void set_plan_name(const string new_plan_name);

	string get_date();
	void set_date(const string new_date);

	//Search plan function before implementing the edit function
	//int search_plan_for_edit(std::ifstream& fileStream, std::ostream& screen, ExercisePlan exercise_plan[]);

	//Edit goal function
	static void editGoal(ExercisePlan exercise_plan[]);

private:
	
	//just simple datatypes like int is not allocating memorty.
	// //but ptr is allocating memory that should be allocated in desconstructor func using delete keyword.
	// here in our case if its int* goal_steps needs to be manually deallocated using delete keyword.
	//ANYTHING ALLOCATED SHOULD BE DEALLOCATED IN DECONSTRUCTOR 
	//data types like int pointer will n ot get deallocated
	int goal_steps; //the number of desired steps for a day.
	string plan_name; 
	string date;
	//string is an object in c++ objects will get auto deallocated.
};





/********************************************************************************************************************
* Function: operator >>()  (Overloading)
* Date Created: 10/11/2023
* Date Last Modified: 10/14/2023
* Description: This exrtraction operator >> can now extract data from exercisePlans.txt and update an exercise_plan
*              object.
* Input parameters: fileStream: an input file stream, exercise_plan: an object from ExercisePlan class passed by reference.
* Returns: fileStream to chain >> multiple times together. 
*********************************************************************************************************************/
//let's overload the extraction operator from an input file non member function << >>
//overload the stream insertion operator to read a file from an input stream non member func
std::ifstream& operator >>(std::ifstream& fileStream, ExercisePlan& exercise_plan);


/********************************************************************************************************************
* Function: operator <<()  (Overloading)
* Date Created: 10/11/2023
* Date Last Modified: 10/14/2023
* Description: This insertion operator << can now display data from exercise_plan object to the console screen.
* Input parameters: screen: an output stream, exercise_plan: an object from ExercisePlan class passed by reference.
* Returns: screen to chain << multiple times together.
*********************************************************************************************************************/
// Overload the stream insertion operator to print a exerciseplan to the console. non member func
std::ostream& operator <<(std::ostream& screen, ExercisePlan& exercise_plan);
//not usibng cout because cout I guess is already pre built? so I used screen for outputting this overloaded func is for
//outputting an exerciseplan object to the console!!


/********************************************************************************************************************
* Function: operator <<() (Overloading)
* Date Created: 10/11/2023
* Date Last Modified: 10/14/2023
* Description: This insertion operator << can now display data from exercise_plan object to an output file.
* Input parameters: screen: an output file stream, exercise_plan: an object from ExercisePlan class passed by reference.
* Returns: fileStream to chain << multiple times together.
*********************************************************************************************************************/
// Overload the stream insertion operator to print a exerciseplan to an output stream. non member func
std::ofstream& operator <<(std::ofstream& fileStream, ExercisePlan& exercise_plan);


//int search_plan_for_edit(std::ifstream& fileStream, std::ostream& screen, ExercisePlan exercise_plan[]);
//