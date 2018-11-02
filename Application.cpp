//
// Created by LeonWong on 2018/11/2.
//

#include <iostream>
#include "Sources/Ingredients/Ingredient.h"
#include "Sources/Refrigerator/Refrigerator.h"

using namespace std;

int main() {
    Refrigerator<Ingredient> ref;
    Refrigerator<Ingredient> tmp;

    cout << "You have 1 Refrigerator now." << endl;

    Ingredient apple("Apple");
    apple.add_custom_property("Weight", "100g");
    apple.add_custom_property("Shape", "Round");

    Ingredient cucumber("Cucumber");
    cucumber.add_custom_property("Weight", "25g");
    cucumber.add_custom_property("Shape", "Strip");

    Ingredient pork("Pork");
    pork.add_custom_property("Weight", "200g");
    pork.add_custom_property("Shape", "Piece");

    do {
        cout << "What do you want?" << endl;
        cout << "[1] Buy Ingredients" << endl;
        cout << "[2] See my refrigerators" << endl;
        cout << "[3] See my cookers" << endl;
        cout << "[4] Do Recipe" << endl;
        cout << "[q] Quit" << endl;
        char choice;
        cin >> choice;
        if (choice == 'q') {
            break;
        }
        if (choice == '1') {
            do {
                cout << "Today's Offer!" << endl;
                cout << "[1] Apple 100g" << endl;
                cout << "[2] Cucumber 25g" << endl;
                cout << "[3] Pork 200g" << endl;
                cout << "[q] Leave store" << endl;
                cout << "Which one would you like?" << endl;
                char choice1;
                cin >> choice1;
                if (choice1 == 'q') {
                    break;
                }
                if (choice != '1' && choice != '2' && choice != '3') {
                    cout << "Bad choice!" << endl;
                    continue;
                }
                cout << "How many do you want?" << endl;
                int amount;
                cin >> amount;
                if (amount <= 0) {
                    cout << "Bad Quantity!" << endl;
                    continue;
                }
                if (choice1 == '1') {
                    ref.push_back(apple, amount);
                }
                else if (choice1 == '2') {
                    ref.push_back(cucumber, amount);
                }
                else if (choice1 == '3') {
                    ref.push_back(pork, amount);
                }
            } while (true);
        }

        if (choice == '2') {
            do {
                cout << "There is(are) " << 1 << " Refrigerator(s)!" << endl;
                cout << "[1] See Refrigerator 1" << endl;
                cout << "[q] Leave Refrigerators" << endl;
                char choice2;
                cin >> choice2;
                if (choice2 == 'q') {
                    break;
                }
                else if (choice2 == '1') {
                    int apples = ref.search(apple);
                    int cucums = ref.search(cucumber);
                    int porks = ref.search(pork);
                    if (apples != 0) {
                        cout << "Apple: " << apples << endl;
                    }
                    if (cucums != 0) {
                        cout << "Cucumber: " << cucums << endl;
                    }
                    if (porks != 0) {
                        cout << "Pork: " << porks << endl;
                    }
                    if (apples == 0 && cucums == 0 && porks == 0) {
                        cout << "Empty Refrigerator, Empty Stomach, Who Can Save Me With My Diet!" << endl;
                    }
                }
                else {
                    cout << "Bad choice!" << endl;
                }
            } while (true);
        }

        if (choice == '3') {
            cout << "Knife (Fruits)" << endl;
            cout << "Knife (Meat)" << endl;
            cout << "Pot" << endl;
        }

        if (choice == '4') {
            cout << "Would you like chicken dinner?" << endl;
            do {
                cout << "[1] Cut something." << endl;
                cout << "[2] Fry something." << endl;
                cout << "[q] Stop cooking" << endl;
                char choice4;
                cin >> choice4;
                if (choice4 == 'q') {
                    break;
                }
                if (choice4 == '1') {
                    cout << "You have knife(knives):" << endl;
                    cout << "[1] Knife (Fruits)" << endl;
                    cout << "[2] Knife (Meat)" << endl;
                    cout << "[3] Get Ingredients for demo" << endl;
                    cout << "[q] Stop cooking" << endl;
                    char choice41;
                    cin >> choice41;
                    if (choice41 == 'q') {
                        break;
                    }
                    if (choice41 == '1') {
                        cout << "Use Knife (Fruits):" << endl;
                        int apples = ref.search(apple);
                        int cucums = ref.search(cucumber);
                        if (apples == 0) {
                            if (cucums == 0) {
                                cout << "You do not have anything to cut!" << endl;
                                continue;
                            } else {
                                cout << "[1] Cucumbers: " << cucums << endl;
                                cout << "[q] Stop cooking." << endl;
                                char choice411;
                                cin >> choice411;
                                if (choice411 == 'q') {
                                    break;
                                } else if (choice411 == '1') {
                                    cout << "Amount you want to cut: ";
                                    int amount;
                                    cin >> amount;
                                    if (amount <= 0 || amount > cucums) {
                                        cout << "Bad Amount!" << endl;
                                        continue;
                                    } else {
                                        Ingredient cucumber_slice(cucumber);
                                        cucumber_slice.add_custom_property("Shape", "Slice");
                                        tmp.push_back(cucumber_slice, amount);
                                        ref.remove(cucumber, amount);
                                    };
                                } else {
                                    cout << "Bad choice!" << endl;
                                    continue;
                                }
                            }
                        } else {
                            if (cucums == 0) {
                                cout << "[1] Apples: " << apples << endl;
                                cout << "[q] Stop cooking." << endl;
                                char choice411;
                                cin >> choice411;
                                if (choice411 == 'q') {
                                    break;
                                } else if (choice411 == '1') {
                                    cout << "Amount you want to cut: ";
                                    int amount;
                                    cin >> amount;
                                    if (amount <= 0 || amount > apples) {
                                        cout << "Bad Amount!" << endl;
                                        continue;
                                    } else {
                                        Ingredient apple_slice(apple);
                                        apple_slice.add_custom_property("Shape", "Slice");
                                        tmp.push_back(apple_slice, amount);
                                        ref.remove(apple, amount);
                                    };
                                } else {
                                    cout << "Bad choice!" << endl;
                                    continue;
                                }
                            } else {
                                cout << "[1] Apples: " << apples << endl;
                                cout << "[2] Cucumbers" << cucums << endl;
                                cout << "[q] Stop cooking." << endl;
                                char choice411;
                                cin >> choice411;
                                if (choice411 == 'q') {
                                    break;
                                } else if (choice411 == '1') {
                                    cout << "Amount you want to cut: ";
                                    int amount;
                                    cin >> amount;
                                    if (amount <= 0 || amount > apples) {
                                        cout << "Bad Amount!" << endl;
                                        continue;
                                    } else {
                                        Ingredient apple_slice(apple);
                                        apple_slice.add_custom_property("Shape", "Slice");
                                        tmp.push_back(apple_slice, amount);
                                        ref.remove(apple, amount);
                                    };
                                } else if (choice411 == '2') {
                                    cout << "Amount you want to cut: ";
                                    int amount;
                                    cin >> amount;
                                    if (amount <= 0 || amount > cucums) {
                                        cout << "Bad Amount!" << endl;
                                        continue;
                                    } else {
                                        Ingredient cucumber_slice(cucumber);
                                        cucumber_slice.add_custom_property("Shape", "Slice");
                                        tmp.push_back(cucumber_slice, amount);
                                        ref.remove(cucumber, amount);
                                    };
                                } else {
                                    cout << "Bad choice!" << endl;
                                    continue;
                                }
                            }
                        }
                    } else if (choice41 == '2') {
                        cout << "Use Knife (Meat)" << endl;
                        int porks = ref.search(pork);
                        if (porks == 0) {
                            cout << "You have nothing to cut!" << endl;
                        }
                        else {
                            cout << "Pork: " << porks << endl;
                        }
                        cout << "All your meat has been cut!" << endl;
                        Ingredient pork_dices(pork);
                        pork.add_custom_property("Shape", "Dices");
                        ref.remove(pork);
                        tmp.push_back(pork_dices, porks);
                    } else if (choice41 == '3') {
                        Ingredient pork_slice(pork);
                        pork_slice.add_custom_property("Shape", "Diced");
                        Ingredient apple_slice(apple);
                        apple_slice.add_custom_property("Shape", "Slice");
                        tmp.push_back(pork_slice, 16);
                        tmp.push_back(apple_slice, 32);
                    } else {
                        cout << "Bad choice!" << endl;
                    }
                }
                if (choice4 == '2') {
                    cout << "You have one pot!" << endl;
                    cout << "You have cut:" << endl;
                    Ingredient pork_slice(pork);
                    pork_slice.add_custom_property("Shape", "Diced");
                    Ingredient apple_slice(apple);
                    apple_slice.add_custom_property("Shape", "Slice");
                    Ingredient cucumber_slice(cucumber);
                    cucumber_slice.add_custom_property("Shape", "Slice");
                    int apple_clices = tmp.search(apple_slice);
                    int cucum_slices = tmp.search(cucumber_slice);
                    int pork_slices = tmp.search(pork_slice);
                    int i = 1;
                    if (apple_clices != 0) {
                        cout << "[" << i << "] Apple Slices: " << apple_clices << endl;
                        i++;
                    }
                    if (cucum_slices != 0) {
                        cout << "[" << i << "] Cucumber Slices: " << cucum_slices << endl;
                        i++;
                    }
                    if (pork_slices != 0) {
                        cout << "[" << i << "] Diced Pork: " << pork_slices << endl;
                        i++;
                    }
                    cout << "[q] Stop cooking" << endl;
                    char choice_cook;
                    cin >> choice_cook;
                    string ing;
                    if (choice_cook == 'q') {
                        break;
                    } else if (choice_cook == '1') {
                        if (apple_clices != 0) {
                            cout << "Apple Slices!" << endl;
                            ing = "Apple";
                        } else if (cucum_slices != 0) {
                            cout << "Cucumber Slices!" << endl;
                            ing = "Cucumber";
                        } else if (pork_slices != 0) {
                            cout << "Dices Pork!" << endl;
                            ing = "Pork";
                        } else {
                            cout << "Bad choice!" << endl;
                            break;
                        }
                    } else if (choice_cook == '2') {
                        if (apple_clices != 0 && cucum_slices != 0) {
                            cout << "Cucumber Slices!" << endl;
                            ing = "Cucumber";
                        } else if (apple_clices != 0 && cucum_slices == 0 && pork_slices != 0) {
                            cout << "Diced Pork!" << endl;
                            ing = "Pork";
                        } else if (apple_clices == 0 && cucum_slices != 0 && pork_slices != 0) {
                            cout << "Diced Pork!" << endl;
                            ing = "Pork";
                        } else {
                            cout << "Bad choice!" << endl;
                            break;
                        }
                    } else if (choice_cook == '3') {
                        if (apple_clices != 0 && cucum_slices != 0 && pork_slices != 0) {
                            cout << "Diced Pork!" << endl;
                            ing = "Pork";
                        } else {
                            cout << "Bad choice!" << endl;
                            break;
                        }
                    } else {
                        cout << "Bad choice!" << endl;
                    }
                    _sleep(10000);
                    if (ing != "") {
                        cout << "Your Fried " << ing << " Has Done!" << endl;
                    }
                }
           } while (true);
        }
    } while (true);
}