cmake_minimum_required(VERSION 3.12)
project(DesPat_MyKitchen)

set(CMAKE_CXX_STANDARD 11)

add_executable(DesPat_MyKitchen Testing/ObjectTesting.cpp Sources/Refrigerator/Refrigerator.h Sources/Refrigerator/Refrigerator.cpp Testing/IngredientTesting.cpp Sources/Ingredients/Ingredient.cpp Sources/Ingredients/Ingredient.h Application.cpp Application.cpp)