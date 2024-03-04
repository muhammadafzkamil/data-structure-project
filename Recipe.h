#pragma once
#ifndef RECIPE_H
#define RECIPE_H

#include <iostream>
#include <string>
#include "List.h"

using namespace std;

class Recipe
{
public:
	string title;
	List<string>* ingredients;
	List<string>* steps;

	Recipe(string, List<string>*, List<string>*);
	void display();
	void update(string, List<string>*, List<string>*);

	void displayIngredients();
	void displaySteps();
	static Recipe* inputRecipe();
};

#endif // RECIPE_H
