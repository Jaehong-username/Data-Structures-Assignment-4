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


/********************************************************************************************************************
* Class name: DietPlan
* Description: This class stores an overall blueprit of methods and variables needed for either extraction of data
*              from dietPlans.txt file or output of data into console, or dietPlans.txt file.
*********************************************************************************************************************/
class DietPlan
{
public:
	DietPlan(); //default constructor
	DietPlan(int new_goal_calories, string new_plan_name, string new_date);

	//copy constructor
	DietPlan(const DietPlan& copy);

	//Destructor
	~DietPlan();

	//getter and setter function
	int get_goal_calories();
	void set_goal_calories(const int new_goal_calories);

	string get_plan_name();
	void set_plan_name(const string new_plan_name);

	string get_date();
	void set_date(const string new_date);

	//Search plan function before implementing the edit function
	//int search_plan_for_edit(std::ifstream& fileStream, std::ostream& screen, DietPlan diet_plan[]);

	//Edit goal function
	//std::ofstream& editGoal(std::ofstream& fileStream, DietPlan diet_plan[]); can just set the return to NULL
	static void editGoal(DietPlan diet_plan[]);

private:

	int goal_calories; //the maximum intake of calories for a day is stored in goal calories.
	string plan_name;
	string date;

};



//let's overload the extraction operator non member function << >>
//overload the stream insertion operator to read a file from an input stream
std::ifstream& operator >>(std::ifstream& fileStream, DietPlan& diet_plan);

// Overload the stream insertion operator to print a exerciseplan to an output stream. non member func
std::ostream& operator <<(std::ostream& screen, DietPlan& diet_plan);

// Overload the stream insertion operator to print a exerciseplan to an output stream. non member func
std::ofstream& operator <<(std::ofstream& fileStream, DietPlan& diet_plan);


//int search_plan_for_edit(std::ifstream& fileStream, std::ostream& screen, DietPlan diet_plan[]);
//