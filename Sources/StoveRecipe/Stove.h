//
//  Stove.h
//  Created by yameng on 2018/10/30.
//

#ifndef Stove_h
#define Stove_h

#include "Recipe.h"
#include <list>
using namespace std;

/**
 * @brief A basic Subject class containing some requirements of subjects.
 *
 */
class Subject
{
public:
    /**
     * @brief A virtual function to attach an observer to this subject.
     *
     * @param _ (Observer *): The observer pointer to be attached to this subject.
     */
    virtual void Attach(Observer *) = 0;
    /**
     * @brief A virtual function to detach an observer to this subject.
     *
     * @param _ (Observer * ): The observer pointer to be detached to this subject.
     */
    virtual void Detach(Observer *) = 0;
    /**
     * @brief A virtual function to notify messages to observers attached to this subject.
     *
     */
    virtual void Notify() = 0;
};

/**
 * @brief A class inherited from Subject class containing some requirements of the stove.
 *
 */
class Stove : public Subject
{
public:
    Stove(){}
    ~Stove(){}
    
    /**
     * @brief Attach an observer to this subject.
     *
     * @param pObserver (Observer *): The observer pointer to be attached to this subject.
     */
    void Attach(Observer *pObserver){
        m_ObserverList.push_back(pObserver);
    }

    /**
     * @brief Detach an observer to this subject.
     *
     * @param pObserver (Observer * ): The observer pointer to be detached to this subject.
     */
    void Detach(Observer *pObserver){
        m_ObserverList.remove(pObserver);
    }
    
    /**
     * @brief Notify messages to observers attached to this subject.
     *
     */
    void Notify(){
        for (auto i : m_ObserverList){
            i->Update();
        }
    }
    
    /**
     * @brief Get the number of observers attached to this subject.
     *
     * @return (int) The length of observer list.
     */
    const int GetSize(){
        return m_ObserverList.size();
    }
    
private:
    /**
     * The list of observers attached to this subject.
     */
    list<Observer *> m_ObserverList;
};

#endif /* stove_h */
