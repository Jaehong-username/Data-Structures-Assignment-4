#include "FitnessAppWrapper.h";

/********************************************************************************************************************
* Function: FitnessAppWrapper()
* Description: a default constructor from FitnessAppWrapper class: initializes member variables of an object by default
*              if no arguments are passed in.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
FitnessAppWrapper::FitnessAppWrapper() 
{
}


/********************************************************************************************************************
* Function: ~FitnessAppWrapper()
* Description: a destructor: deallocates an object, implictly invoked when the object goes out of scope.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
FitnessAppWrapper::~FitnessAppWrapper() //technically I can Leave it blank, because none of my variables from private allocate memory
{
}



/********************************************************************************************************************
* Function: isExercisePlanEmpty()
* Description: checks for whether or not exericse_plan is empty (fai
led to load the data from txt file)                
* Input parameters: exercise_plan: an array of objects that belong to ExercisePlan class.
* Returns: boolean value
*********************************************************************************************************************/
bool FitnessAppWrapper::isExercisePlanEmpty(ExercisePlan exercise_plan[])
{
	

	if (exercise_plan[0].get_plan_name() == "" && exercise_plan[0].get_goal_steps() == 0 && exercise_plan[0].get_date() == "")
	{
		cout << "\nThe exercise weekly plan is currently empty! \n\nMake sure to load the exercise plan from the file first!" << endl;
		return true;
	}

	else return false;
	
}


/********************************************************************************************************************
* Function: isDietPlanEmpty()
* Description: checks for whether or not diet_plan is empty (failed to load the data from txt file)
* Input parameters: diet_plan: an array of objects that belong to DietPlan class.
* Returns: boolean value
*********************************************************************************************************************/
bool FitnessAppWrapper::isDietPlanEmpty(DietPlan diet_plan[])
{
	if (diet_plan[0].get_plan_name() == "" && diet_plan[0].get_goal_calories() == 0 && diet_plan[0].get_date() == "")
	{
		cout << "\nThe diet weekly plan is currently empty! \n\nMake sure to load the diet plan from the file first!" << endl;
		return true;
	}

	else return false;
}



/********************************************************************************************************************
* Function: loadDailyPlan()
* Description: Loads data from txt file into with input file stream variable called fileStream, it is a function
*              overloading.
* Input parameters: fileStream: input file stream, plan: an array of objects that belong to DietPlan class.
* Returns: boolean value
*********************************************************************************************************************/
void FitnessAppWrapper::loadDailyPlan(std::ifstream& fileStream, DietPlan& plan)
{
	fileStream >> plan;
}


/********************************************************************************************************************
* Function: loadWeeklyPlan()
* Description: Loads data from txt file into with input file stream variable called fileStream, it is a function
*              overloading.
* Input parameters: fileStream: input file stream, weeklyPlan: an array of objects that belong to DietPlan class.
* Returns: boolean value
*********************************************************************************************************************/
void FitnessAppWrapper::loadWeeklyPlan(std::ifstream& fileStream, DietPlan weeklyPlan[])
{
	//while (!fileStream.eof())
	for (int i = 0; i < 7; i++)
	{
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}
		
	cout << "The weekly diet plan is successfully loaded!\n" << endl;
}


/********************************************************************************************************************
* Function: loadDailyPlan()
* Description: Loads data from txt file into with input file stream variable called fileStream, it is a function
*              overloading.
* Input parameters: fileStream: input file stream, plan: an array of objects that belong to ExercisePlan class.
* Returns: boolean value
*********************************************************************************************************************/
void FitnessAppWrapper:: loadDailyPlan(std::ifstream& fileStream, ExercisePlan& plan)
{
	fileStream >> plan;
}



/********************************************************************************************************************
* Function: loadWeeklyPlan()
* Description: Loads data from txt file into with input file stream variable called fileStream, it is a function
*              overloading.
* Input parameters: fileStream: input file stream, weeklyPlan: an array of objects that belong to ExercisePlan class.
* Returns: boolean value
*********************************************************************************************************************/
void FitnessAppWrapper:: loadWeeklyPlan(std::ifstream& fileStream, ExercisePlan weeklyPlan[])
{
	for (int i = 0; i < 7; i++)
	{
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}

	cout << "The weekly exercise plan is successfully loaded!\n" << endl;
}

//std::ifstream& FitnessAppWrapper::displayDailyExercisePlan(std::ifstream& fileStream, std::ostream& screen, ExercisePlan& exercise_plan)
//{
//	//since I defined overloaded functions I can just use << >> insertion operators to invoke the functions.
//	screen << exercise_plan;
//
//	//dont need these!!
//	/*cout << "\n" << exercise_plan.get_plan_name() << endl;
//	cout << "" << exercise_plan.get_goal_steps() << endl;
//	cout << "" << exercise_plan.get_date() << endl;*/
//
//	return fileStream;
//}



/********************************************************************************************************************
* Function: displayDailyExercisePlan()
* Description: This function prints data of a passed by referance object that belongs to ExercisePlan class to the console screen.
*              This will also be invoked multiple times in displayWeeklyExeciseplan() function to print the weekly plan
*              to the console screen.
* Input parameters: screen: output stream, exercise_plan: a passed by referance object that belongs to ExercisePlan class.
* Returns: screen: output stream passed by referance. 
*********************************************************************************************************************/
std::ostream& FitnessAppWrapper::displayDailyExercisePlan(std::ostream& screen, ExercisePlan& exercise_plan)
{
	//since I defined overloaded functions I can just use << >> insertion operators to invoke the functions.
	screen << exercise_plan;

	//dont need these!!
	/*cout << "\n" << exercise_plan.get_plan_name() << endl;
	cout << "" << exercise_plan.get_goal_steps() << endl;
	cout << "" << exercise_plan.get_date() << endl;*/

	return screen;
}


/********************************************************************************************************************
* Function: displayWeeklyExercisePlan()
* Description: This function prints data of an array of objects that belongs to ExercisePlan class to the console output.
* Input parameters: screen: output stream, exercise_plan: an array of objects that belongs to ExercisePlan class.
* Returns: screen: output stream passed by referance.
*********************************************************************************************************************/
std::ostream& FitnessAppWrapper::displayWeeklyExercisePlan(std::ostream& screen, ExercisePlan exercise_plan[])
{
	if (!isExercisePlanEmpty(exercise_plan))
	{
		//while (!fileStream.eof()) //will cause an issue get rid of the while loop
		for (int i = 0; i < 7; i++)
		{
			displayDailyExercisePlan(screen, exercise_plan[i]);
		}
	}

	//else // if the array is empty
	//{
	//	cout << "The weekly exercise plan is empty! Cannot display the plan.\n" << endl;
	//	cout << "Please make sure to load the weekly exercise plan beforehand!\n" << endl;
	//}

	return screen;
}



/********************************************************************************************************************
* Function: storeDailyExercisePlan()
* Description: This function stores currently up to date data of an object belonging to ExercisePlan into an output txt file.
*              This function is also invoked multiple times in storeWeeklyExercisePlan to store the recently updated weekly
*              plan into an output txt file.
* Input parameters: fileStream: output file stream, exercise_plan: a passed by referance object that belongs to ExercisePlan class.
* Returns: fileStream: output file stream passed by referance.
*********************************************************************************************************************/
std::ofstream& FitnessAppWrapper::storeDailyExercisePlan(std::ofstream& fileStream, ExercisePlan& exercise_plan)
{
	fileStream << exercise_plan;
	return fileStream;
}



/********************************************************************************************************************
* Function: storeWeeklyExercisePlan()
* Description: This function stores currently up to date data of an array of objects belonging to ExercisePlan into an output txt file.
* Input parameters: fileStream: output file stream, exercise_plan: an array of objects that belong to ExercisePlan class.
* Returns: fileStream: output file stream passed by referance.
*********************************************************************************************************************/
std::ofstream& FitnessAppWrapper::storeWeeklyExercisePlan(std::ofstream& fileStream, ExercisePlan exercise_plan[])
{
	//while (!fileStream.eof()) error will go beyond how many plans we have if set up eof.
	
	if (!isExercisePlanEmpty(exercise_plan))
	{
		fileStream.open("exercisePlans.txt", std::ios::out);
		
		for (int i = 0; i < 7; i++)
		{
			storeDailyExercisePlan(fileStream, exercise_plan[i]);
		}

		fileStream.close();

		cout << "Weekly exercise plan data stored successfully into the exercisePlans.txt file!\n" << endl;
	}

	//else // if the array is empty
	//{
	//	cout << "The weekly exercise plan is empty! Cannot store the plan to the output file\n" << endl;
	//	cout << "Please make sure to load the weekly exercise plan beforehand!\n" << endl;
	//}
	
	return fileStream;
}



/********************************************************************************************************************
* Function: displayDailyDietPlan()
* Description: This function prints data of a passed by referance object that belongs to DietPlan class to the console screen.
*              This will also be invoked multiple times in displayWeeklyDietplan() function to print the weekly plan
*              to the console screen.
* Input parameters: screen: output stream, exercise_plan: a passed by referance object that belongs to DietPlan class.
* Returns: screen: output stream passed by referance.
*********************************************************************************************************************/
std::ostream& FitnessAppWrapper::displayDailyDietPlan(std::ostream& screen, DietPlan& diet_plan)
{
	screen << diet_plan;

	return screen;
}


/********************************************************************************************************************
* Function: displayWeeklyDietPlan()
* Description: This function prints data of an array of objects that belongs to DietPlan class to the console output.
* Input parameters: screen: output stream, diet_plan: an array of objects that belongs to DietPlan class.
* Returns: screen: output stream passed by referance.
*********************************************************************************************************************/
std::ostream& FitnessAppWrapper::displayWeeklyDietPlan(std::ostream& screen, DietPlan diet_plan[])
{
	if (!isDietPlanEmpty(diet_plan))
	{
		for (int i = 0; i < 7; i++)
		{
			displayDailyDietPlan(screen, diet_plan[i]);
		}
	}

	//else // if the array is empty
	//{
	//	cout << "The weekly diet plan is empty! Cannot store the plan to the output file\n" << endl;
	//	cout << "Please make sure to load the weekly diet plan beforehand!\n" << endl;
	//}

	return screen;
}



/********************************************************************************************************************
* Function: storeDailyDietPlan()
* Description: This function stores currently up to date data of an object belonging to DietPlan into an output txt file.
*              This function is also invoked multiple times in storeWeeklyDietPlan to store the recently updated weekly
*              plan into an output txt file.
* Input parameters: fileStream: output file stream, diet_plan: a passed by referance object that belongs to DietPlan class.
* Returns: fileStream: output file stream passed by referance.
*********************************************************************************************************************/
std::ofstream& FitnessAppWrapper::storeDailyDietPlan(std::ofstream& fileStream, DietPlan& diet_plan)
{
	fileStream << diet_plan;
	return fileStream;
}



/********************************************************************************************************************
* Function: storeWeeklyDietPlan()
* Description: This function stores currently up to date data of an array of objects belonging to DietPlan into an output txt file.
* Input parameters: fileStream: output file stream, diet_plan: an array of objects that belong to DietPlan class.
* Returns: fileStream: output file stream passed by referance.
*********************************************************************************************************************/
std::ofstream& FitnessAppWrapper::storeWeeklyDietPlan(std::ofstream& fileStream, DietPlan diet_plan[])
{
	if (!isDietPlanEmpty(diet_plan))
	{
		fileStream.open("dietPlans.txt", std::ios::out);

		for (int i = 0; i < 7; i++)
		{
			storeDailyDietPlan(fileStream, diet_plan[i]);
		}

		fileStream.close();

		cout << "Weekly diet plan data stored successfully into the dietPlans.txt file!\n" << endl;
	}

	//else // if the array is empty
	//{
	//	cout << "The weekly diet plan is empty! Cannot store the plan to the output file\n" << endl;
	//	cout << "Please make sure to load the weekly diet plan beforehand!\n" << endl;
	//}

	return fileStream;
}




/********************************************************************************************************************
* Function: displayMenu()
* Description: This displays the main menu of Fitness Application to the console screen.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
void FitnessAppWrapper::displayMenu()
{

	cout << "Welcome to the Fitness App Program!\n\n\n" << endl;

	cout << "Main Menu: " << endl << endl;

	cout << "1. Load weekly diet plan from file.\n" << endl;
	cout << "2. Load weekly exercise plan from file.\n" << endl;
	cout << "3. Store weekly diet plan to file.\n" << endl;
	cout << "4. Store weekly exercise plan to file.\n" << endl;
	cout << "5. Display weekly diet plan to screen.\n" << endl;
	cout << "6. Display weekly exercise plan to screen.\n" << endl;
	cout << "7. Edit daily diet plan.\n" << endl;
	cout << "8. Edit daily exercise plan.\n" << endl;
	cout << "9. Exit." << endl;
	cout << "Note: Exit writes the most recent weekly plans to the corresponding files.\n" << endl << endl;
	
	
}


/********************************************************************************************************************
* Function: runApp()
* Description: This function serves as a main implementation of the Fintness Application program.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
void FitnessAppWrapper::runApp()
{
	
	//int total_days = 7;
	//std::ostream screen; no default constructor exists forosstream

	int exit_sure = 0;

	//Is there any way I can complete this function without making dummy object variables like the three below??
	//DietPlan edit_instance1;
	//ExercisePlan edit_instance2; //we can't name the object the same!!!
	//FitnessAppWrapper instance;

	do
	{
		displayMenu();

		int menu_choice;
		cout << "Please Enter number through 1 to 9 to choose a menu:";

		cin >> menu_choice;

		switch (menu_choice)
		{

		case 1:// load weekly diet plan
			//std::ifstream fileStream; //error: initialization of filestream is skipped by case label.
			system("cls");
			inputfileStream.open("dietPlans.txt", std::ios::in);
			loadWeeklyPlan(inputfileStream, diet_plan_array);
			inputfileStream.close();
			putchar('\n');
			system("pause");
			system("cls");
			break;

		case 2: //load weekly exercise plan
			system("cls");
			inputfileStream.open("exercisePlans.txt", std::ios::in);
			loadWeeklyPlan(inputfileStream, exercise_plan_array);
			inputfileStream.close();
			putchar('\n');
			system("pause");
			system("cls");
			break;

		case 3: //store weekly diet plan to file
			system("cls");
			//outputfileStream.open("dietPlans.txt", std::ios::out); if this line included if forgot to load the data, then all the data in the txt file gone.
			storeWeeklyDietPlan(outputfileStream, diet_plan_array);
			//outputfileStream.close();
			putchar('\n');
			system("pause");
			system("cls");
			break;

		case 4: //store weekly exercise plan to file
			system("cls");
			storeWeeklyExercisePlan(outputfileStream, exercise_plan_array);
			putchar('\n');
			system("pause");
			system("cls");
			break;

		case 5://Display weekly diet plan to screen
			system("cls");
			displayWeeklyDietPlan(cout, diet_plan_array);
			putchar('\n');
			system("pause");
			system("cls");
			break;

		case 6: //Display weekly exercise plan to screen.
			system("cls");
			displayWeeklyExercisePlan(cout, exercise_plan_array);
			putchar('\n');
			system("pause");
			system("cls");
			break;

		case 7: //7. Edit daily diet plan.
			system("cls");
			//DietPlan edit_instance1; error initialization is skipped by case label!
			//outputfileStream.open("dietPlans.txt", std::ios::out); //since I am not storing anything to the file, as of now
			//making adjustments to the array! The moment you open an output file it will erase what's currently inside of the file
			//if function not doing anything to the output file but only open and close it, it will erase the whole data, which is an issue
			DietPlan::editGoal(diet_plan_array);
			//outputfileStream.close();
			putchar('\n');
			system("pause");
			system("cls");
			break;

		case 8: //8. Edit daily exercise plan.
			system("cls");
			//ExercisePlan edit_instance2; //we can't name the object the same!!!
			//outputfileStream.open("exercisePlans.txt", std::ios::out);
			ExercisePlan::editGoal(exercise_plan_array); //static members get access to 
			//outputfileStream.close();
			putchar('\n');
			system("pause");
			system("cls");
			break;

		case 9: //9. Exit. Note: this must write the most recent weekly plans to the coresponding files
			system("cls");
			exit_sure = exit();

			if (exit_sure == 1 && !isDietPlanEmpty(diet_plan_array) && !isExercisePlanEmpty(exercise_plan_array)) //keeping both exercise and diet plans up to date!
			{
				//outputfileStream.open("exercisePlans.txt", std::ios::out);
				storeWeeklyExercisePlan(outputfileStream, exercise_plan_array);
				//outputfileStream.close();

				//outputfileStream.open("dietPlans.txt", std::ios::out);
				storeWeeklyDietPlan(outputfileStream, diet_plan_array);
				//outputfileStream.close();

				system("cls");
				cout << "\nBoth the dietPlans.txt and the exercisePlans.txt have been updated with the current data\n" << endl;
				cout << "\nSee you Later!\n" << endl;

				putchar('\n');
				system("pause");
				system("cls");

				break;
			}

			else if (exit_sure == 1 && isDietPlanEmpty(diet_plan_array) || isExercisePlanEmpty(exercise_plan_array))
			{
				system("cls");
				cout << "\nSince the data has not been loaded yet, the corresponding files will just stay the same\n" << endl;
				cout << "\nSee you Later!\n" << endl;

				putchar('\n');
				system("pause");
				system("cls");

				break;
			}
		}


	} while (exit_sure == 0);

}




/********************************************************************************************************************
* Function: exit()
* Description: This function determines whether or not exit out of the Fitness Application program.
* Input parameters: Nothing
* Returns: exit_sure: exit_sure = 1 terminates the program, while exit_sure = 0 loops back to the main menu display.
*********************************************************************************************************************/
int FitnessAppWrapper::exit()
{
	system("cls");
	
	int again = 0;
	int exit_sure = 0;
	int yes_or_no = 0;

	do
	{
		again = 0;

		cout << "Are you sure you would lie to exit the FitnessApp? Enter only 1 for Yes and 2 for No " << endl;
		cout << "1. Yes         2. No" << endl;
		cin >> yes_or_no;

		if (yes_or_no == 1)
		{
			cout << "Note that Both the exercise and the diet plan will be updated with the most recent plans!\n" << endl;
			cout << "See you next time!\n" << endl;

			exit_sure = 1;

		}

		else if (yes_or_no == 2)
		{
			cout << "You entered No, it will bring you back to the main menu.\n" << endl;
			system("pause");
			system("cls");
			exit_sure = 0;
		}

		else
		{
			cout << "Please enter only 1 for Yes and 2 for No\n" << endl;
			again = 1;
			putchar('\n');
			system("pause");
			system("cls");
		}


	} while (again == 1);

	
	return exit_sure;
}


