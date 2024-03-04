#include "Recipe.h"


Recipe::Recipe(string title, List<string>* steps, List<string>* ingredients)
{
    this->title = title;
    this->steps = steps;
    this->ingredients = ingredients;
}

void  Recipe::display()
{
    cout << "Title: " << title << endl;

    cout << "\nIngredients: " << endl;
    displayIngredients();

    cout << "\nSteps: " << endl;
    displaySteps();
    

    
}

void Recipe::update(string title, List<string>* steps, List<string>* ingredients)
{
    this->title = title;
    this->steps = steps;
    this->ingredients = ingredients;
}

void Recipe::displayIngredients()
{
    Node<string>* current = ingredients->head;
    while (current)
    {
        cout << current->data << endl;
        current = current->next;
    }
}

void Recipe::displaySteps()
{
    Node<string>* current = steps->head;
    while (current)
    {
        cout << current->data << endl;
        current = current->next;
    }
}



Recipe* Recipe::inputRecipe()
{
    cout << "Enter Dish name: ";
    string dish;
    cin >> dish;

    cout << "Enter # of ingredients for this dish: ";
    int ingredientsCount;
    cin >> ingredientsCount;
    List<string>* ingredients = new List<string>();
    for (int i = 1; i <= ingredientsCount; i++)
    {
        cout << "Enter ingredient # " << i << ": ";
        string ingredient;
        cin >> ingredient;
        ingredients->append(ingredient);
    }

    cout << "Enter # of steps for this dish: ";
    int stepsCount;
    cin >> stepsCount;
    List<string>* steps = new List<string>();
    for (int i = 1; i <= stepsCount; i++)
    {
        cout << "Enter step # " << i << ": ";
        string step;
        cin >> step;
        steps->append(step);
    }

    Recipe* recipe = new Recipe(dish, ingredients, steps);

    return recipe;
}
