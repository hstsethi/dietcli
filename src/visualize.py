import pandas as pd
import matplotlib.pyplot as plt

def plotCalorieBreakdown():
    consumed = pd.read_json("consumed.json")
    macro = consumed["Macronutrients"]
    calorie_fat = macro["Fats"] * 9
    calorie_protein = macro["Protein"] * 4
    calorie_carbs = macro["Carbs"] * 4
    
    labels = ["Calorie by Fats", "Calorie by Protein", "Calorie by Carbs"]
    values = [calorie_fat, calorie_protein, calorie_carbs]
    plt.pie(values, labels=labels, autopct="%1.1f%%")
    plt.title("Calorie Breakdown by Macro Nutrient | DietCLI")
    plt.show()
plotCalorieBreakdown()
