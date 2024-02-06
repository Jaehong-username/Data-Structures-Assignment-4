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

#include "DietPlan.h"

#include "ExercisePlan.h"


/********************************************************************************************************************
* Class name: FitnessAppWrapper
* Description: This class stores an overall blueprint for methods and variables needed for the proper implementation
*              of the Fitness Application program.
*********************************************************************************************************************/
class FitnessAppWrapper
{
public:

	FitnessAppWrapper();

	~FitnessAppWrapper();

	void runApp(void);

	void loadDailyPlan(std::ifstream& fileStream, DietPlan& plan);
	void loadWeeklyPlan(std::ifstream& fileStream, DietPlan weeklyPlan[]); //array of reference is not allowed!!

	void loadDailyPlan(std::ifstream& fileStream, ExercisePlan& plan);
	void loadWeeklyPlan(std::ifstream& fileStream, ExercisePlan weeklyPlan[]);


	static std::ostream& displayDailyExercisePlan(std::ostream& screen, ExercisePlan& exercise_plan);
	static std::ostream& displayWeeklyExercisePlan(std::ostream& screen, ExercisePlan exercise_plan[]);

	std::ofstream& storeDailyExercisePlan(std::ofstream& fileStream, ExercisePlan& exercise_plan);
	std::ofstream& storeWeeklyExercisePlan(std::ofstream& fileStream, ExercisePlan exercise_plan[]);


	static std::ostream& displayDailyDietPlan(std::ostream& screen, DietPlan& diet_plan);
	static std::ostream& displayWeeklyDietPlan(std::ostream& screen, DietPlan diet_plan[]);

	std::ofstream& storeDailyDietPlan(std::ofstream& fileStream, DietPlan& diet_plan);
	std::ofstream& storeWeeklyDietPlan(std::ofstream& fileStream, DietPlan diet_plan[]);


	void displayMenu();

	//extra function
	static bool isExercisePlanEmpty(ExercisePlan exercise_plan[]);

	static bool isDietPlanEmpty(DietPlan diet_plan[]);

	int exit();

private:
	
	//ExercisePlan* exercise_plan_array; //need for destructor
	//int* ptr; 
	ExercisePlan exercise_plan_array[7]; //default constructor is invoked 7 times here!
	//decalring a fized size array as a variable no allocation
	DietPlan diet_plan_array[7];

	std::ifstream inputfileStream;
	std::ofstream outputfileStream;
	
	//bool exercise_plan_array_empty;
	//bool diet_plan_array_empty;

};
