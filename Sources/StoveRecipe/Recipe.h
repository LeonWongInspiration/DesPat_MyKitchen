//
//  Recipe.h
//  Created by yameng on 2018/10/30.
//

#ifndef Recipe_h
#define Recipe_h

#include <iostream>
#include <list>
#include <thread>
using namespace std;

/**
 * @brief A basic Observer class containing some requirements of observers.
 *
 */
class Observer
{
public:
    /**
     * @brief A virtual function to update its state when this observer has received messages from subject.
     *
     */
    virtual void Update() = 0;
};

/**
 * @brief A class inherited from Observer class containing some requirements of the recipe.
 *
 */

class Recipe : public Observer
{
public:
    Recipe() : m_id(0) {}
    ~Recipe() {}
    Recipe(const int id) : m_id(id) {}
    
    /**
     * @brief Update its state when this observer has received messages from subject.
     *
     */
    void Update(){
        cout << endl;
        cout << "菜谱" << m_id << "在进行中。" << endl;
    }
    
    /**
     * @brief Set commands of this recipe.
     *
     * @param tList (list<int>) The list of commands to be set in this recipe.
     * @warning This function is temporory. Command pattern is not completed.
     */
    void SetTime(list<int>tList){
        for(auto i: tList){
            m_Time.push_back(i);
        }
    }
    
    /**
     * @brief Start to execute the commands.
     *
     * @warning This function is temporory. Command pattern is not completed.
     */
    void Start(){
        int pos = 1;
        for(auto i: m_Time){
            cout << endl;
            cout << "菜谱" << m_id << "：正在进行第" << pos << "步" << endl;
            this_thread::sleep_for(chrono::seconds(i));
            pos++;
        }
    }
    
private:
    /**
     * The list of commands.
     */
    list<int> m_Time;
    /**
     * The ID of recipe.
     */
    int m_id;
};

#endif /* Recipe_h */
