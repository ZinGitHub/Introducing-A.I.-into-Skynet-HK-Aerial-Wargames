#include <iostream>
#include <ctime> 
using std::cout;
using std::endl;
using std::cin;

int main()
{
	// Changes the color for background and font.
	system("color 0A");
	// Changes the name of the program.
	system("title Skynet HK Aerial Wargames");
	// Stating that the program is generating a random enemy location on 8x8 grid.
	cout << "Generate Random enemy location on 8x8 grid...." << endl;
	// Boolean variable to play Again
	bool playAgain = true;
	// Integer variable that will restore user input on whether they want to play again.
	int result = 0;

	// The while statement that will keep running the program until user doesn't
	while (playAgain == true)
	{
		// Provides the random function a new seed and a starting point.
		srand(time(0));
		// The highest integer number in the grid is 64.
		int searchGridHighNumber = 64;
		// The lowest integer number in the grid is 1.
		int searchGridLowNumber = 1;
		// Creating a random integer for the enemy location.
		int enemyLocation = rand() % searchGridHighNumber + searchGridLowNumber;
		// cout stating the location of the enemy in the grid.
		cout << "The enemy is located at location #" << enemyLocation << " on 8x8 grid with 1-64 sectors." << endl;
		// cout stating that Skynet HK-Aerial software is starting up.
		cout << "Skynet HK-Aerial Initializing software....." << endl;

		// integer declaring the amount of predictions taken to find the enemy.
		int HumanPilotedSearchTargetLocationPredictionCounter = 0;
		int aIBinarySearchTargetLocationPredictionCounter = 0;
		int aILinearSearchTargetLocationPredictionCounter = 0;
		int aIRandomSearchTargetLocationPredictionCounter = 0;

		// Upgraded versions of the linear and random AI's.
		int aIEnhancedLinearSearchTargetLocationPredictionCounter = 0;
		int aIEnhancedRandomSearchTargetLocationPredictionCounter = 0;

		// Boolean variables declaring whether the enemy was found and destroyed.
		bool isSearchByAllDronesCompleteWithTargetFoundByAllDrones = false;
		bool isAIBinarySearchTargetFound = false;
		bool isAILinearSearchTargetFound = false;
		bool isAIRandomSearchTargetFound = false;
		bool isHumanPilotedSearchTargetFound = false;

		// Integer variable that holds the amount of predictions it took to find the location of the target.
		int aIBinarySearchTargetLocationPrediction = 0;
		int aILinearSearchTargetLocationPrediction = 0;
		int aIRandomSearchTargetLocationPrediction = 0;
		int HumanPilotedSearchTargetLocationPrediction = 0;

		// Cout stating that all drones are being launched. 
		cout << "Preparing to launch all of Skynet's Hunter Killer drones.";
		// Pausing the system. 
		system("pause");


		// A while statement for human to find the target.
		while (!isSearchByAllDronesCompleteWithTargetFoundByAllDrones)
		{
			while (isHumanPilotedSearchTargetFound == false)
			{
				// Gathering the location predicted by the human.
				cout << "\n\nEnter Target Location Human:";
				cin >> HumanPilotedSearchTargetLocationPrediction;

				// Incrementing the value of the prediction counter for the human.
				HumanPilotedSearchTargetLocationPredictionCounter++;

				// Cout acting as a divider.
				cout << "=============================================================" << endl;
				// Cout stating that there is a ping being sent for the human search.
				cout << "Skynet HK-Aerial Radar sending out ping #" << HumanPilotedSearchTargetLocationPredictionCounter << endl;
				// A if statement for when the number of the location predicted by the human is greater than the number of the enemy location.
				if (HumanPilotedSearchTargetLocationPrediction > enemyLocation)
				{
					// The number variable holding the new highest number in the grid, and subtract 1 because you don't need to search the number guessed.
					searchGridHighNumber = HumanPilotedSearchTargetLocationPrediction - 1;
					// Cout stating that the location predicted by the human is higher than the enemy location. 
					cout << "The target location prediction of " << HumanPilotedSearchTargetLocationPrediction << " was higher than the actual enemy location " << "." << endl;
				}
				// A else if statement for whenever the number of the location predicted by the human is less than the number of the enemy location.
				else if (HumanPilotedSearchTargetLocationPrediction < enemyLocation)
				{
					// The number variable holding the new lowest number in the grid, and add 1 because you don't need to search the number guessed.
					searchGridLowNumber = HumanPilotedSearchTargetLocationPrediction + 1;
					// Cout stating that the location predicted by the human is lower than the enemy location.
					cout << "The target location prediction of " << HumanPilotedSearchTargetLocationPrediction << " was lower than the actual enemy location " << "." << endl;
				}
				// A else if statement that is processed whenever the human has found the enemy location.
				else if (HumanPilotedSearchTargetLocationPrediction == enemyLocation)
				{
					// A cout statement the location of the enemy.
					cout << "Enemy was hiding at location #" << enemyLocation << endl;
					// A cout statement that reveals that human has found the target.
					cout << "Target was found at location #" << HumanPilotedSearchTargetLocationPrediction << endl;
					// A cout statement that tell's how many predictions it took for the human to find the target.
					cout << "The Skynet HK-Aerial Human Pilot took " << HumanPilotedSearchTargetLocationPredictionCounter << " predictions to find the enemy location on a grid size of 8x8 (64)." << endl;
					// Boolean stating that the human has officially found the target.
					isHumanPilotedSearchTargetFound = true;
				}
				// A else statement for whenever the drone is experiencing a glitch/malfunction in the system.
				else
				{
					// A block of cout statements to inform the user that the drone is going through a glitch procedure.
					cout << "Drone has malfunction while doing Human search!" << endl;
					cout << "Send Drone for Software Diagnostics!" << endl;
					cout << "Abandoning Human Search!" << endl;
					isHumanPilotedSearchTargetFound = true;
				}
			}
			// A while statement for the AI linear search.
			while (isAILinearSearchTargetFound == false)
			{
				// Incrementing the location prediction by 1.
				aILinearSearchTargetLocationPrediction = ++aILinearSearchTargetLocationPrediction;
				// Incrementing the amount of how many predictions. 
				aILinearSearchTargetLocationPredictionCounter = ++aILinearSearchTargetLocationPredictionCounter;
				// Cout acting as a divider.
				cout << "=============================================================" << endl;
				// A cout stating the number of prediction and the location predicted.
				cout << endl << "Linear Search AI #" << aILinearSearchTargetLocationPredictionCounter << " prediction is " << aILinearSearchTargetLocationPrediction << endl;

				// A if statement for when the linear AI finds the target.
				if (aILinearSearchTargetLocationPrediction == enemyLocation)
				{
					// Boolean stating that this is a true statement.
					isAILinearSearchTargetFound = true;
					// A cout statement stating that the linear AI has found the target at this location.
					cout << "Enemy has been found by the Linear Search AI at location #" << enemyLocation << endl;
				}
				// A else if statement for when the linear AI does not find the enemy location.
				else if (aILinearSearchTargetLocationPrediction != enemyLocation)
				{
					// A cout statement stating that the linear AI has not found the enemy at it's location.
					cout << "Enemy has not been found by the Linear Search AI at location #" << enemyLocation << endl;
				}
				// A else statement for whenever the drone is experiencing a glitch/malfunction in the system.
				else
				{
					// A block of cout statements to inform the user that the drone need's diagnostics.
					cout << "Drone malfunction while doing Linear search!" << endl;
					cout << "Send Drone for Software Diagnostics!" << endl;
					cout << "Abandoning Linear Search!" << endl;
					isAILinearSearchTargetFound = true;
				}
			}
			// A while statement fir the random AI search.
			while (isAIRandomSearchTargetFound == false)
			{
				// A randomization for the location predicted.
				aIRandomSearchTargetLocationPrediction = rand() % 64 + 1;
				// Incrementing the amount of how many predictions.
				aIRandomSearchTargetLocationPredictionCounter = ++aIRandomSearchTargetLocationPredictionCounter;
				// Cout acting as a divider.
				cout << "=============================================================" << endl;
				// A cout stating the amount of the prediction and the prediction location.
				cout << endl << "Random Search AI #" << aIRandomSearchTargetLocationPredictionCounter << " prediction is " << aIRandomSearchTargetLocationPrediction << endl;

				// A if statement for when the random AI finds the location of the target. 
				if (aIRandomSearchTargetLocationPrediction == enemyLocation)
				{
					// A boolean to declare this as a true statement.
					isAIRandomSearchTargetFound = true;
					// A cout statement informing that the enemy was located.
					cout << "Enemy has been found by the Random Search AI at location #" << enemyLocation << endl;
				}
				// A else if statement for when the random AI does not find the location of the target.
				else if (aIRandomSearchTargetLocationPrediction != enemyLocation)
				{
					// A cout statement informing that the enemy was not located yet.
					cout << "Enemy has not been found by the Random Search AI at location #" << enemyLocation << endl;
				}
				// A else statement for whenever the drone is experiencing a glitch/malfunction in the system.
				else
				{
					// A block of cout statements to inform the user that the drone need's diagnostics.
					cout << "Drone malfunction while doing Random search!" << endl;
					cout << "Send Drone for Software Diagnostics!" << endl;
					cout << "Abandoning Random Search!" << endl;
					isAIRandomSearchTargetFound = true;
				}
			}

			// Resets the highest and lowest grid number for the binary AI search.
			searchGridHighNumber = 64;
			searchGridLowNumber = 1;
			// A while statement fot the AI binary search.
			while (isAIBinarySearchTargetFound == false)
			{
				//The algorithm for the binary AI search.
				aIBinarySearchTargetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
				// Incrementing the amount of predictions
				aIBinarySearchTargetLocationPredictionCounter++;
				// A cout statement that act's as a divider.
				cout << "=============================================================" << endl;
				// A cout statement for the pings being sent out.
				cout << "Skynet HK-Aerial Radar sending out ping #" << aIBinarySearchTargetLocationPredictionCounter << endl;
				// A if statement for when the number predicted by the AI is greater than the actual enemy location.
				if (aIBinarySearchTargetLocationPrediction > enemyLocation)
				{
					// The number variable holding the new highest number in the grid, and subtract 1 because you don't need to search the number guessed.
					searchGridHighNumber = aIBinarySearchTargetLocationPrediction - 1;
					// A cout statement informing that the prediction was higher than the enemy location.
					cout << "The target location prediction of " << aIBinarySearchTargetLocationPrediction << " was higher than the actual enemy location of " << enemyLocation << "." << endl;
					// A cout statement informing the uer of the new searchGridHighNumber.
					cout << "The new searchGridHighNumber = " << searchGridHighNumber << endl;
				}
				// A else if statement for when the number predicted by the AI is less than the enemy location.
				else if (aIBinarySearchTargetLocationPrediction < enemyLocation)
				{
					// The number variable holding the new lowest number in the grid, and add 1 because you don't need to search the number guessed.
					searchGridLowNumber = aIBinarySearchTargetLocationPrediction + 1;
					// A cout statement informing that the prediction was lower than the enemy location.
					cout << "The target location prediction of " << aIBinarySearchTargetLocationPrediction << " was lower than the actual enemy location of " << enemyLocation << "." << endl;
					// A cout statement informing the uer of the new searchGridLowNumber.
					cout << "The new searchGridLowNumber = " << searchGridLowNumber << endl;
				}
				// A else if statement for when the binary search AI finds the enemy location.
				else if (aIBinarySearchTargetLocationPrediction == enemyLocation)
				{
					// A cout statement informing about the location of the enemy.
					cout << "Enemy was hiding at location #" << enemyLocation << endl;
					// A cout statement informing that the binary search AI has located the target.
					cout << "Target was found at location #" << aIBinarySearchTargetLocationPrediction << endl;
					// A count statement informing about the amount of predictions.
					cout << "Skynet HK-Aerial Software took " << aIBinarySearchTargetLocationPredictionCounter << " predictions to find the enemy location on a grid size of 8x8 (64)." << endl;
					// Turning the boolean variable as true.
					isAIBinarySearchTargetFound = true;
				}
				// A else statement for whenever the drone is experiencing a glitch/malfunction in the system.
				else
				{
					// A block of cout statements to inform the user that the drone need's diagnostics.
					cout << "Drone malfunction while doing binary search!" << endl;
					cout << "Send Drone for Software Diagnostics!" << endl;
					cout << "Abandoning Binary Search!" << endl;
					isAIBinarySearchTargetFound = true;
				}
			}
			// A if statement that verifies that all drones have found the location of the enemy.
			if (isAILinearSearchTargetFound == true && isAIBinarySearchTargetFound == true)
			{
				isSearchByAllDronesCompleteWithTargetFoundByAllDrones = true;
			}
		}
		//Displaying the statistics of the drones launched.
		cout << "\n\n\n**********************************************" << endl;
		cout << "* All drones have now found the enemy." << endl;
		cout << "* The Enemy was hiding at grid location " << enemyLocation << endl;
		cout << "*" << endl;
		cout << "* The Human Player using a human Search took " << HumanPilotedSearchTargetLocationPredictionCounter << " guesses to find the enemy location final target prediction was " << HumanPilotedSearchTargetLocationPrediction << endl;

		cout << "* The AI Player using Linear Search took " << aILinearSearchTargetLocationPredictionCounter << " guesses to find the enemy location final target prediction was " << aILinearSearchTargetLocationPrediction << endl;
		cout << "* The AI Player using Random Search took " << aIRandomSearchTargetLocationPredictionCounter << " guesses to find the enemy location final target prediction was " << aIRandomSearchTargetLocationPrediction << endl;
		cout << "* The AI Player using Binary Search took " << aIBinarySearchTargetLocationPredictionCounter << " guesses to find the enemy location final target prediction was " << aIBinarySearchTargetLocationPrediction << endl;

		cout << "**********************************************" << endl;
		cout << "**********************************************" << endl;

		// Cout statement asking if user want's to play again.
		cout << "Would you like to try the simulation again?" << endl;
		cout << "1: Yes" << endl;
		cout << "2: No" << endl;
		cout << ">";
		cin >> result;
		// The if else statement that will either make the simulation loop back or not.
		if (result == 1)
		{
			playAgain = true;
		}
		else if (result == 2)
		{
			playAgain = false;
		}
		else
		{
			playAgain = false;
		}
	}
	//Pausing the Skynet HK-Aerial simulation.
	cout << "\n\nTo Exit this simulation ";
	system("pause");
	// The exit code. If zero is returned then the program ran successfully.
	return 0;
}
