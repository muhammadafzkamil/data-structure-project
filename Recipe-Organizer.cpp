
#include "List.h"
#include <iostream>
#include <string>
#include "HashTable.h"
#include "AVLTree.h"
#include "User.h"
#include "Recipe.h"

using namespace std;


int main() {
	cout << "\n\n\n-------------------------Welcome to Recipe Organizer-------------------------\n\n\n";
	// Creating a HashTable to store cuisines

	List<List<AVLTree>> mainList;
	HashTable table(10);
 

  
  
	// User signup
	string name, email, password;
	cout << "Enter your name: ";
	cin >> name;
	cout << "Enter your email address: ";
	cin >> email;
	cout << "Enter your password: ";
	cin >> password;

	// Creating and signing up user
	User u;
	User* use;
	use = u.signup(name, email, password);

	// User verification
	string recheck_email, recheck_password;
up:
	cout << "\nNow enter the same email and password:\n";
	cin >> recheck_email;
	cin >> recheck_password;

	// User signin
	bool confirm = use->signin(recheck_email, recheck_password);

	if (confirm) {

		// Main program for user actions
		int ans1;
		do {
			cout << "Do you want to change your info? Press 1\n";
			cout << "Do you want to display user info? Press 2\n";
			cout << "Do you want to more option? Press 3\n";
			cout << "Do you want to exit? Press 0\n\n";
			cin >> ans1;

			switch (ans1) {
			case 1: {
				cout << "\nEnter your name: ";
				cin >> name;
				cout << "Enter your email address: ";
				cin >> email;
				cout << "Enter your password: ";
				cin >> password;

				use->changeInfo(name, email, password);
				break;
			}
			case 2: {
				use->display();
				break;
			}
			case 3: {


				cout << "\n\nOptions:\n";
				cout << "0. Exit\n";
				cout << "1. Add Cuisine\n";
				cout << "2. Add Meal Category\n";
				cout << "3. Add Recipe\n";
				cout << "4. Search Recipe\n";
				cout << "5. display Cuisine list\n";
				cout << "6. display Meal Category  list\n";
				cout << "7. display foods list\n";






				int choice;
				cout << "\nEnter your choice: ";
				cin >> choice;

				switch (choice) {

				case 1:
				{
					cout << "\nInput cuisine: ";
					string category;
					cin >> category;

					Node<List<AVLTree>>* current = mainList.head;

					while (current && current->label != category)
						current = current->next;

					if (current)
					{
						cout << "existing category" << endl;
						List<AVLTree> tree = current->data;
					}

					else
					{
						cout << "new category" << endl;
						List<AVLTree> list;
						mainList.append(list, category);
					}
					break;
				}

				case 2: {
					// Add Meal Category
					string cuisineName, mealCategoryName;
					cout << "\nEnter Cuisine Name: ";
					cin >> cuisineName;

					Node<List<AVLTree>>* current = mainList.find(cuisineName);

					if (current)
					{
						cout << "\nEnter Meal Category Name: ";
						cin >> mealCategoryName;

						AVLTree tree;
						AVLNode* categoryNode = tree.insert(nullptr); // You can use a unique key for categories
						current->data.append(tree, mealCategoryName);
					}
					else
					{
						cout << "Cuisine not found. Please add the cuisine first.\n";
					}
					break;
				}


					  // ...

				case 3: {
					// Add Recipe
					string cuisineName, mealCategoryName, recipeTitle;
					cout << "Enter Cuisine Name: ";
					cin >> cuisineName;

					Node<List<AVLTree>>* cuisineNode = mainList.find(cuisineName);

					if (cuisineNode)
					{
						cout << "Enter Meal Category Name: ";
						cin >> mealCategoryName;

						Node<AVLTree>* categoryNode = cuisineNode->data.find(mealCategoryName);

						if (categoryNode)
						{
							AVLTree* categoryTree = &categoryNode->data;

							int addMore;
							do {
								Recipe* newRecipe = Recipe::inputRecipe();
								string ans = newRecipe->title;

								// Check if the recipe title already exists in the tree

								categoryTree->root = categoryTree->insert(newRecipe); 
								table.put(ans, newRecipe);
								cout << "Recipe Added Successfully!\n";


								cout << "Do you want to add another recipe? (1 for yes, 0 for no): ";
								cin >> addMore;

							} while (addMore == 1);
						}
						else
						{
							cout << "Meal Category not found. Please add the meal category first.\n";
						}
					}
					else
					{
						cout << "Cuisine not found. Please add the cuisine first.\n";
					}
					break;
				}






				case 4: {
					// Search Recipe
					cout << "Enter recipe name:";
					string ans;
					cin >> ans;
					cout << endl;

					if (table.contains(ans))
						table.get(ans)->display();
					else
						cout << "Thier is no recipe in tree:\n " << endl;

					break;
				}

				case 5:
				{
					Node<List<AVLTree>>* current = mainList.head;
					while (current)
					{
						cout << current->label << "->";
						current = current->next;
					}

					cout << endl;
					break;


				}


				case 6: {
					// Print Meal Categories
					cout << "Enter Cuisine Name: ";
					string cuisineName;
					cin >> cuisineName;

					Node<List<AVLTree>>* cuisineNode = mainList.find(cuisineName);

					if (cuisineNode)
					{
						cout << "\nMeal Categories for Cuisine " << cuisineName << ":\n";
						Node<AVLTree>* categoryNode = cuisineNode->data.head;
						while (categoryNode)
						{
							cout << categoryNode->label << "->";
							categoryNode = categoryNode->next;
						}

						cout << endl;
						break;
					}
					else
					{
						cout << "Cuisine not found.\n";
					}
					break;
				}

					  // ...

				case 7: {
					// Print Tree for Specific Cuisine and Meal Category
					cout << "Enter Cuisine Name: ";
					string cuisineName;
					cin >> cuisineName;

					Node<List<AVLTree>>* cuisineNode = mainList.find(cuisineName);

					if (cuisineNode)
					{
						cout << "Enter Meal Category Name: ";
						string mealCategoryName;
						cin >> mealCategoryName;

						Node<AVLTree>* categoryNode = cuisineNode->data.find(mealCategoryName);

						if (categoryNode)
						{
							AVLTree categoryTree = categoryNode->data;
							cout << "\nTree for Cuisine " << cuisineName << " and Meal Category " << mealCategoryName << ":\n";
							categoryTree.display();

						}
						else
						{
							cout << "Meal Category not found.\n";
						}

						break;
					}
					else
					{
						cout << "Cuisine not found.\n";
						break;
					}

				}





				case 0:
				{
					break;
				}


				}


				break;
			}

			case 0:
			{
				break; // Exit the loop
			}

			default:
				cout << "Invalid choice. Please enter a valid option.\n";

			} //switch end

		} while (ans1 != 0);
	}

	else {
		cout << "\nYou entered either the wrong email or password.\nDo you want to try again? Press 1 for yes, else 0.\n";
		int n;
		cin >> n;

		// Retry signin
		if (n == 1)
			goto up;
		else
			goto down;
	}



down:
	return 0;
}





