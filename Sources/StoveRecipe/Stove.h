//
//  Stove.h
//  Created by yameng on 2018/10/30.
//

#ifndef Stove_h
#define Stove_h

#include "../Object.h"
#include "Recipe.h"
#include <list>
using namespace std;

/**
 * @brief A basic Subject class containing some requirements of subjects.
 *
 */
class Subject : public Object
{
public:
    
    /**
     * @brief A virtual function to attach an observer to this subject.
     *
     * @param (Observer *) _: The observer pointer to be attached to this subject.
     */
    virtual void Attach(Observer *) = 0;
    
    /**
     * @brief A virtual function to detach an observer to this subject.
     *
     * @param (Observer * ) _: The observer pointer to be detached to this subject.
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
    /**
     * size_t will be considered when referring to indices and sizes of arrays.
     */
    using size_t = unsigned int;
    
public:
    
    /**
     * @brief Default constructor.
     *
     */
    Stove(){}
    
    /**
     * @brief Default destructor.
     *
     */
    ~Stove(){}
    
    /**
     * @brief Return basic information about the class.
     *
     * @return (string) Name and address of this class.
     */
    virtual string who_am_i() const override {
        stringstream add;
        add << this;
        string ret = "Stove@" + add.str();
        return ret;
    }
    
    /**
     * @brief Attach an observer to this subject.
     *
     * @param (Observer *) pObserver: The observer pointer to be attached to this subject.
     */
    virtual void Attach(Observer *pObserver) override {
        m_ObserverList.push_back(pObserver);
    }

    /**
     * @brief Detach an observer to this subject.
     *
     * @param (Observer * ) pObserver: The observer pointer to be detached to this subject.
     */
    virtual void Detach(Observer *pObserver) override {
        m_ObserverList.remove(pObserver);
    }
    
    /**
     * @brief Notify messages to observers attached to this subject.
     *
     */
    virtual void Notify() override {
        for (auto i : m_ObserverList){
            i->Update();
        }
    }
    
    /**
     * @brief Get the number of observers attached to this subject.
     *
     * @return (int) The length of observer list.
     */
    unsigned int GetSize() const {
        return m_ObserverList.size();
    }
    
private:
    /**
     * The list of observers attached to this subject.
     */
    list<Observer *> m_ObserverList;
    
};

#endif /* stove_h */
