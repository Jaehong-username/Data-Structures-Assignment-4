#include "DietPlan.h"

#include "FitnessAppWrapper.h"

/********************************************************************************************************************
* Function: DietPlan()
* Description: a default constructor from DietPlan class: initializes member variables of an object by default
*              if no arguments are passed in.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
DietPlan::DietPlan() //default constructor for DietPlan class
{
	goal_calories = 0;
	plan_name = "";
	date = "";
}


/********************************************************************************************************************
* Function: DietPlan()
* Description: a constructor from DietPlan class: initializes member variables of an object when matching arguments are passed in.
* Input parameters: new_goal_calories, new_plan_name, new_date
* Returns: Nothing
*********************************************************************************************************************/
DietPlan::DietPlan(int new_goal_calories, string new_plan_name, string new_date) //constructor for DierPlan class
{
	//question!! what are some other ways to represent other than using this keyword????
	/*this->set_goal_calories(new_goal_calories);
	this->set_plan_name(new_plan_name);
	this->set_date(new_date);*/

	//since it is a member func of the class I can directly access so no need for set func
	goal_calories = new_goal_calories;
	plan_name = new_plan_name;
	date = new_date;
}



/********************************************************************************************************************
* Function: DietPlan()
* Description: a copy constructor from DietPlan class: makes a copy of an object from DietPlan class.
* Input parameters: copy: passed by a reference to an object from DietPlan class.
* Returns: Nothing
*********************************************************************************************************************/
//pass by reference
DietPlan::DietPlan(const DietPlan& copy) //copy constructor!
{//this is a shallow copy
	goal_calories = copy.goal_calories;
	plan_name = copy.goal_calories;
	date = copy.date;
}


/********************************************************************************************************************
* Function: ~DietPlan()
* Description: a destructor: deallocates an object, implictly invoked when the object goes out of scope.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
//destructor!!! it is called when an object goes out of scope vairables defined inside of the scope going away
//terminating
DietPlan::~DietPlan() //in our class case technically no need for writing any codes.
{
}




/********************************************************************************************************************
* Function: get_goal_calories()
* Description: a getter function. Gets goal_calories int variable value.
* Input parameters: Nothing
* Returns: goal_calories
*********************************************************************************************************************/
int DietPlan::get_goal_calories()
{
	return goal_calories;
}


/********************************************************************************************************************
* Function: set_goal_calories()
* Description: a setter function. Updates goal_calories int to new_goal_calories.
* Input parameters: new_goal_calories
* Returns: Nothing
*********************************************************************************************************************/
void DietPlan:: set_goal_calories(const int new_goal_calories)
{
	goal_calories = new_goal_calories;
}



/********************************************************************************************************************
* Function: get_plan_name()
* Description: a getter function. Gets a plan_name string from a private member of an object.
* Input parameters: Nothing
* Returns: plan_name
*********************************************************************************************************************/
string DietPlan::get_plan_name()
{
	return plan_name;
}

/********************************************************************************************************************
* Function: set_plan_name()
* Description: a setter function. Updates plan_name string from a private member of an object to a new_plan_name
* Input parameters: new_plan_name
* Returns: Nothing
*********************************************************************************************************************/
void DietPlan::set_plan_name(const string new_plan_name)
{
	plan_name = new_plan_name;
}


/********************************************************************************************************************
* Function: get_date()
* Description: a getter function. Gets a date string from a private member of an object.
* Input parameters: Nothing
* Returns: date
*********************************************************************************************************************/
string DietPlan::get_date()
{
	return date;
}


/********************************************************************************************************************
* Function: set_date()
* Description: a setter function. Updates date string from a private member of an object to a new_date
* Input parameters: new_date
* Returns: Nothing
*********************************************************************************************************************/
void DietPlan::set_date(const string new_date)
{
	date = new_date;
}


/********************************************************************************************************************
* Function: editGoal()
* Description: Chooses one daily diet plan and edits the current goal_calories stored with an updated value.
* Input parameters: diet_plan: It is an array of diet_plan objects belong to DietPlan class.
* Returns: Nothing
*********************************************************************************************************************/
void DietPlan::editGoal(DietPlan diet_plan[])
{

	if (FitnessAppWrapper::isDietPlanEmpty(diet_plan))
	{
		cout << "\nEditing cannot be implemented!\n" << endl;
		//cout << "Make sure to load the weekly plan from the txt file beforehand from menu 1\n" << endl;
		return;
	}

	int which_day_program = -1;

	cout << "Here is the curent weekly exercise plan!\n" << endl;
	
	FitnessAppWrapper::displayWeeklyDietPlan(cout, diet_plan);

	do
	{
		cout << "Please enter which diet plan you would like to edit from day 1 to 7.\n" << endl;
		cout << "Make sure to only enter through 1 to 7" << endl;
		cin >> which_day_program;

		if (which_day_program < 1 || which_day_program > 7)
		{
			cout << "Please enter number only 1 to 7!\n" << endl;
			putchar('\n');
			putchar('\n');
			system("pause");
			system("cls");
		}

	} while (which_day_program < 1 || which_day_program > 7);


	int edited_goal_calories = 0;
	cout << "Current Calorie: " << diet_plan[which_day_program - 1].goal_calories << endl;

	cout << "Please Enter a new goal you wanna set up for maximum calorie intake per day: " << endl;
	cin >> edited_goal_calories;

	//cout << "Edited Calorie Goal: " << edited_goal_calories << endl;
	//we dont need getter and a setter.

	//update the new value by accessing the private members of the class using set func
	//this->set_goal_calories(edited_goal_calories);
	
	//goal_calories = edited_goal_calories;

	if (diet_plan[which_day_program - 1].goal_calories == edited_goal_calories)
	{
		cout << "Your edited goal calorie is the same as the previous one\n" << endl;
		return;
	}

	else
	{
		diet_plan[which_day_program - 1].goal_calories = edited_goal_calories;

		cout << "Edited Desired steps for a day goal:\n" << diet_plan[which_day_program - 1].goal_calories << endl;

		//is this a way to call a member function from another class?????
		cout << "Alright! The weekly exercise plan is now changed! Here is the recent update!\n" << endl;
		FitnessAppWrapper::displayWeeklyDietPlan(cout, diet_plan);
		return;
	}

	//updating the updated goal to the output file.
	//fileStream << this->get_goal_calories();

}



/********************************************************************************************************************
* Function: operator >>()
* Description: This function makes the extraction operator >> able to extract data from input txt file and store the data into
*              an DietPlan class object.
* Input parameters: fileStream: input file Stream, diet_plan: a passed by referance object taht belongs to DietPlan class
* Returns: fileStream: input file stream which enables chain >> multiple times at once.
*********************************************************************************************************************/
//since these three are non member functions of the class we need to use getter and setter function to get access to private members of the diet plan class
//also when dealing with different object we need to use getter and seter func as well.
std::ifstream& operator >>(std::ifstream& fileStream, DietPlan& diet_plan)
{
	string plan_name_extracted;
	int goal_calories_extracted;
	string date_extracted;

	//since I sat it int data type after exrtracted string wil be auto converted into int thats why I dont need stoi!
	fileStream >> plan_name_extracted >> goal_calories_extracted >> date_extracted;

	diet_plan.set_plan_name(plan_name_extracted);
	diet_plan.set_goal_calories(goal_calories_extracted);
	diet_plan.set_date(date_extracted);

	return fileStream;
}



/********************************************************************************************************************
* Function: operator <<()
* Description: This function makes the insertion operator << able to output the data stored in the object array to an output file
*              using fileStream.
* Input parameters: fileStream: output file Stream, diet_plan: a passed by referance object that belongs to DietPlan class
* Returns: fileStream: output filestream which enables chain << multiple times at once.
*********************************************************************************************************************/
std::ofstream& operator <<(std::ofstream& fileStream, DietPlan& diet_plan) //updated output to an file.
{
	fileStream << diet_plan.get_plan_name() << endl;
	fileStream << diet_plan.get_goal_calories() << endl;
	fileStream << diet_plan.get_date() << endl << endl;

	return fileStream;
}



/********************************************************************************************************************
* Function: operator <<()
* Description: This function makes the insertion operator << able to output the print result to the console screen.
* Input parameters: fileStream: output file Stream, diet_plan: a passed by referance object that belongs to DietPlan class
* Returns: fileStream: output filestream which enables chain << multiple times at once.
*********************************************************************************************************************/
//cout string literal is predefined! but here I am trying bring object ouputs to the console which is not defined
//that is the reason why I need to make overloaded functions.
std::ostream& operator <<(std::ostream& screen, DietPlan& diet_plan) //updated output to a screen.
{
	screen << diet_plan.get_plan_name() << endl;
	screen << diet_plan.get_goal_calories() << endl;
	screen << diet_plan.get_date() << endl << endl;

	return screen;
}