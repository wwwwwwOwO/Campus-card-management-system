#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <iomanip> 
#include <deque>
#define Rate 0.1
using namespace std;
enum state{ OFF,ON,LOST };
const string STATE[3]= {"未激活", "已激活", "挂失中"};
const string method[3] = {"现金支付", "微信支付", "支付宝支付"};
const string place[8] = {"第一饭堂", "第二饭堂", "第三饭堂", "第四饭堂", "清真食堂", "行政楼餐厅", "教育超市", "快乐多超市"};

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
    bool isChecked();                         //验证密码
    void add(double amount);                  //对余额或热水账户余额进行增减
    void minus(double amount);
    void addWater(double amount);
    void minusWater(double amount);
    void setState(state);
    void setPassword(string);

    void recordCharge(ChargeRecord *);       //将充值或消费时生成的充值记录类或消费记录类压入队列
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
