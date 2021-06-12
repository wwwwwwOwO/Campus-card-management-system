#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;
const string DEPARTMENT[7] = {"数据科学与计算机学院", "数学学院", "中山医学院", "管理学院", "岭南学院", "外国语学院", "马克思主义学院"};
const string MAJOR[7] = {"计算机系", "数学系", "医学", "工商管理", "经济学", "英语系", "哲学"};

class Card;
class Student{
    const string Name;
    int ID,Department, Major, Grade, Class;
    Card *card;

public:
    Student(string Name_, int ID_,int Department_, int Major_, int Grade_, int Class_);
    void setCard(Card *);
    void Check();
    void Activate();
    void Charge();
    void ChargeCard();
    void ChargeWater();
    void Consume();
    void Loss();

    string getName()const {    return Name; }
    int getID()const {    return ID; }
    int getDepartment()const {    return Department; }
    int getMajor()const {    return Major; }
    int getGrade()const {    return Grade; }
    int getClass()const {    return Class; }
    
    Card *getCard() const { return card; }
};

#endif
