#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <iomanip> 
#include <deque>
#define Rate 0.1
using namespace std;
enum state{ OFF,ON,LOST };
const string STATE[3]= {"δ����", "�Ѽ���", "��ʧ��"};
const string method[3] = {"�ֽ�֧��", "΢��֧��", "֧����֧��"};
const string place[8] = {"��һ����", "�ڶ�����", "��������", "���ķ���", "����ʳ��", "����¥����", "��������", "���ֶ೬��"};

class Record{
    int Month, Day, Hour, Minute, Second;
    double Amount;

public:
    Record(double amount);
    void Print_Record()const;
};

class ChargeRecord:public Record{
    int Method;

public:
    ChargeRecord(double amount );
    void Print_ChargeRecord() const;
};

class ConsumeRecord:public Record{
    int Place;

public:
    ConsumeRecord(double amount);
    void Print_ConsumeRecord() const;
};

class WaterRecord:public Record{
    int Time;

public:
    WaterRecord(int );
    void Print_WaterRecord() const;
};

class Card{
    const int Number;
    string Password;
    double Value, WaterAccount;
    state State;
    Student *student;
    deque<ChargeRecord*> charge_record;
    deque<ConsumeRecord*> consume_record;
    deque<WaterRecord*> water_record;
public:
    Card(int Num, Student *);
    ~Card();
    bool isChecked();                         //��֤����
    void add(double amount);                  //��������ˮ�˻�����������
    void minus(double amount);
    void addWater(double amount);
    void minusWater(double amount);
    void setState(state);
    void setPassword(string);

    void recordCharge(ChargeRecord *);       //����ֵ������ʱ���ɵĳ�ֵ��¼������Ѽ�¼��ѹ�����
    void recordConsume(ConsumeRecord *);
    void recordWater(WaterRecord *);
    void printCharge() const;
    void printConsume() const;
    void printWater() const;

    int getNum()const { return Number; }
    double getValue()const { return Value; }
    double getWaterAccount()const { return WaterAccount; }
    int getState()const { return State; }
 
};

#endif
