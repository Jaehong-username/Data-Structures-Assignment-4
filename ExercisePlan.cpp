#include "ExercisePlan.h"
#include "FitnessAppWrapper.h"


/********************************************************************************************************************
* Function: ExercisePlan()
* Description: a default constructor from ExercisePlan class: initializes member variables of an object by default 
*              if no arguments are passed in.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
ExercisePlan::ExercisePlan() //default constructor
{
	goal_steps = 0; //the number of desired steps for a day.
	plan_name = "";
	date = "";
}



/********************************************************************************************************************
* Function: ExercisePlan()
* Description: a constructor from ExercisePlan class: initializes member variables of an object when matching arguments are passed in.
* Input parameters: new_goal_steps, new_plan_name, new_date
* Returns: Nothing
*********************************************************************************************************************/
//we dont waana access member function until they are initialized
ExercisePlan::ExercisePlan(int new_goal_steps, string new_plan_name, string new_date)
{
	//this->set_goal_steps(new_goal_steps); //not preferred we dont know the current state of the object)
	//this->set_plan_name(new_plan_name);
	//this->set_date(new_date);

	goal_steps = new_goal_steps; //directly accessing to the private member so we dont need this keyword.
	plan_name = new_plan_name;
	date = new_date;
}



/********************************************************************************************************************
* Function: ExercisePlan()
* Description: a copy constructor from ExercisePlan class: makes a copy of an object from ExercisePlan class.
* Input parameters: copy: passed by a reference to an object from ExercisePlan class.
* Returns: Nothing
*********************************************************************************************************************/
//pass by reference
ExercisePlan::ExercisePlan(const ExercisePlan& copy) // it is a copy constructor
{
	goal_steps = copy.goal_steps;
	plan_name = copy.plan_name;
	date = copy.date;
}


/********************************************************************************************************************
* Function: ~ExercisePlan()
* Date Created: 10/11/2023
* Date Last Modified: 10/11/2023
* Description: a destructor: deallocates an object, implictly invoked when the object goes out of scope. 
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
//destructor
ExercisePlan::~ExercisePlan()
{
}



/********************************************************************************************************************
* Function: get_goal_steps()
* Date Created: 10/11/2023
* Date Last Modified: 10/11/2023
* Description: a getter function. Gets goal_steps int variable value.
* Input parameters: Nothing
* Returns: goal_steps
*********************************************************************************************************************/
int ExercisePlan::get_goal_steps()
{
	return goal_steps;
}

/********************************************************************************************************************
* Function: set_goal_steps()
* Date Created: 10/11/2023
* Date Last Modified: 10/11/2023
* Description: a setter function. Updates goal_steps int to new_goal_steps.
* Input parameters: new_goal_steps
* Returns: Nothing
*********************************************************************************************************************/
void ExercisePlan::set_goal_steps(const int new_goal_steps)
{
	goal_steps = new_goal_steps;
}



/********************************************************************************************************************
* Function: get_plan_name()
* Description: a getter function. Gets a plan_name string from a private member of an object.
* Input parameters: Nothing
* Returns: plan_name
*********************************************************************************************************************/
string ExercisePlan::get_plan_name()
{
	return plan_name;
}

/********************************************************************************************************************
* Function: set_plan_name()
* Description: a setter function. Updates plan_name string from a private member of an object to a new_plan_name
* Input parameters: new_plan_name
* Returns: Nothing
*********************************************************************************************************************/
void ExercisePlan::set_plan_name(const string new_plan_name)
{
	plan_name = new_plan_name;
}


/********************************************************************************************************************
* Function: get_date()
* Description: a getter function. Gets a date string from a private member of an object.
* Input parameters: Nothing
* Returns: date
*********************************************************************************************************************/
string ExercisePlan::get_date()
{
	return date;
}

/********************************************************************************************************************
* Function: set_date()
* Description: a setter function. Updates date string from a private member of an object to a new_date
* Input parameters: new_date
* Returns: Nothing
*********************************************************************************************************************/
void ExercisePlan::set_date(const string new_date)
{
	date = new_date;
}






/********************************************************************************************************************
* Function: editGoal()
* Description: Chooses one daily exerice plan and edits the current goal_steps stored with an updated value.
* Input parameters: exercise_plan: It is an array of exercise_plan objects that belong to ExercisePlan class.
* Returns: Nothing
*********************************************************************************************************************/
void ExercisePlan::editGoal(ExercisePlan exercise_plan[])
{
	//FitnessAppWrapper instance1; //instantiation of an object with a different class
	//creating a whole another object for the sake of getting access to its member function is a bad practice of coding.
	//because, it creates an object that you dont really need to. Instead you can just pass the class as a parameter.
	//which was the reason why created a bunch of destructor invoked lines of code on the console, after the implementation of this local function.
	//FitnessAppWrapper instance;

	if (FitnessAppWrapper::isExercisePlanEmpty(exercise_plan))
	{
		cout << "\nEditing cannot be implemented!\n" << endl;
		//cout << "Make sure to load the weekly plan from the txt file beforehand from menu 2\n" << endl;
		return;
	}

	int which_day_program = - 1; //since data type is int, an user input will be converted from string to int.

	cout << "Here is the curent weekly exercise plan!\n" << endl;
	
	FitnessAppWrapper::displayWeeklyExercisePlan(cout, exercise_plan);

	do
	{
		cout << "Please enter which exercise plan you would like to edit from day 1 to 7.\n" << endl;
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


	int edited_goal_steps = 0;

	cout << "Current Desired Steps for a day:\n" << exercise_plan[which_day_program - 1].goal_steps << endl;

	cout << "Please Enter a new goal you wanna set up for current desired steps for a day:\n" << endl;
	cin >> edited_goal_steps;

	//update the new value by accessing the private members of the class using set func
	//this->set_goal_steps(edited_goal_steps);

	if (exercise_plan[which_day_program - 1].goal_steps == edited_goal_steps)
	{
		cout << "Your edited goal is the same as the previous one\n" << endl;
		//return fileStream; not really need it.
		return;
	}

	else
	{
		exercise_plan[which_day_program - 1].goal_steps = edited_goal_steps;

		cout << "Edited Desired steps for a day goal:\n" << exercise_plan[which_day_program - 1].goal_steps << endl;

		//is this a way to call a member function from another class?????
		cout << "Alright! The weekly exercise plan is now changed! Here is the recent update!\n" << endl;
		FitnessAppWrapper::displayWeeklyExercisePlan(cout, exercise_plan); //this func from FitnessAppWrapper class
		return;
	}

	//fileStream << this->get_goal_steps(); //updating it to the output file as well not necessary
	//return fileStream; not really need it!
}





/********************************************************************************************************************
* Function: operator >>()
* Description: This function makes the extraction operator >> able to extract data from input txt file and store the data into
*              an ExercisePlan class object.
* Input parameters: fileStream: input file Stream, exercise_plan: a passed by referance object that belongs to ExercisePlan class
* Returns: fileStream: input file stream which enables chain >> multiple times at once.
*********************************************************************************************************************/
//return type void like  void operator >>(std::istream& fileStream, ExercisePlan& exercise_plan) cannot use function chain
//overload the stream insertion operator to read a file from an input stream
std::ifstream& operator >>(std::ifstream& fileStream, ExercisePlan& exercise_plan)
{
	//streams naturally sat up to skip white space tabs \n 
	//int i = 0;

	string plan_name_extracted, date_extracted;
	int goal_steps_extracted;
	//char slash;
	
	//while (!fileStream.eof()) //while loop should be in the main
	//{
		fileStream >> plan_name_extracted >> goal_steps_extracted >> date_extracted;
		//fscanf(stream name, "%s %d %s,) we can also use in c when extracting from an input file. in different format specifiers

		exercise_plan.set_plan_name(plan_name_extracted);
		exercise_plan.set_goal_steps(goal_steps_extracted);
		exercise_plan.set_date(date_extracted);

		return fileStream;
	//}
}


/********************************************************************************************************************
* Function: operator <<()
* Description: This function makes the insertion operator << able to output the data stored in the object array to an output file
*              using fileStream.
* Input parameters: fileStream: output file Stream, exercise_plan: a passed by referance object that belongs to ExercisePlan class
* Returns: fileStream: output filestream which enables chain << multiple times at once.
*********************************************************************************************************************/
                                                 //vs  const ExercisePlan& exercise_plan Question!!!!!!!
// Overload the stream insertion operator to print a exerciseplan to an output stream. non member func
std::ofstream& operator <<(std::ofstream& fileStream, ExercisePlan& exercise_plan)
{
	//the output could be console or any other output files depending on how I defined to be in main.
	fileStream << exercise_plan.get_plan_name() << endl;
	fileStream << exercise_plan.get_goal_steps() << endl;
	fileStream << exercise_plan.get_date() << endl << endl;

	return fileStream; //return type ofstream& passed by reference.
}




/********************************************************************************************************************
* Function: operator <<()
* Description: This function makes the insertion operator << able to output the print result to the console screen.
* Input parameters: fileStream: output file Stream, exercise_plan: a passed by referance object that belongs to ExercisePlan class
* Returns: fileStream: output filestream which enables chain << multiple times at once.
*********************************************************************************************************************/
std::ostream& operator <<(std::ostream& screen, ExercisePlan& exercise_plan)
{
	screen << exercise_plan.get_plan_name() << endl;
	screen << exercise_plan.get_goal_steps() << endl;
	screen << exercise_plan.get_date() << endl << endl;

	return screen;

}


//int search_plan_for_edit(std::ifstream& fileStream, std::ostream& screen, ExercisePlan exercise_plan[])
//{
//	//Question!!!!!!!!!! Is there anyway I can bring a function defined from other class which FitnessAppWrapper. here???
//	//displayWeeklyExercisePlan(fileStream, screen, exercise_plan[]);
//
//
//	int i;
//
//	string plan_name_extracted;
//	int goal_steps_extracted;
//	string date_extracted;
//
//	string date_input;
//
//	cout << "\nTHis is a one week plan up to date!" << endl << endl;
//
//	while (!fileStream.eof())
//	{
//		fileStream >> plan_name_extracted >> goal_steps_extracted >> date_extracted;
//		exercise_plan[i].set_plan_name(plan_name_extracted);
//		exercise_plan[i].set_goal_steps(goal_steps_extracted);
//		exercise_plan[i].set_date(date_extracted);
//		screen << plan_name_extracted << goal_steps_extracted << date_extracted << endl << endl;
//
//		i++;
//	}
//
//	int again = 0;
//
//	do
//	{
//		again = 0;
//
//		cout << "\nPlease choose the date for which you would like to change your goal steps!: " << endl;
//		cout << "\nMake sure to type the date in the exactly same format!!!" << endl;
//		cin >> date_input;
//
//		for (int j = 0; j < i ; j++)
//		{
//			if (date_input == exercise_plan[j].get_date())
//			{
//				cout << "\nFound the matching date for the plan!" << endl;
//				again = 0;
//				i = j;
//				break;
//			}
//
//			if (j == i - 1) //in the last object but still couldn't find one!!!
//			{
//				cout << "\nThere is not matching date! Please type your date again!" << endl;
//				again = 1;
//			}
//		}
//
//	} while (again == 1);
//
//
//	return i;
//}