#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;
const string DEPARTMENT[7] = {"���ݿ�ѧ������ѧԺ", "��ѧѧԺ", "��ɽҽѧԺ", "����ѧԺ", "����ѧԺ", "�����ѧԺ", "���˼����ѧԺ"};
const string MAJOR[7] = {"�����ϵ", "��ѧϵ", "ҽѧ", "���̹���", "����ѧ", "Ӣ��ϵ", "��ѧ"};

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
