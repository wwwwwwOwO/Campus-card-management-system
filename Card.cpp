#include <iostream>
#include "Student.hpp"
#include "Card.hpp"
Record::Record(double amount):Amount(amount){
    cout << "\n请输入日期（月、日，用空格隔开）：" << endl;
    cin >> Month >> Day;
    cout << "\n请输入当前时间（时、分、秒，用空格隔开）：" << endl;
    cin >> Hour >> Minute >> Second;
}

void Record::Print_Record()const{
    cout << setfill(' ') << left << setw(10) << Amount;
    cout << setfill(' ') << setw(2) << Month << "月" << setfill(' ') << setw(2) << Day << "日";
    cout << setfill(' ') << setw(2) << Hour << "时" << setfill(' ') << setw(2) << Minute << "分" << setfill(' ') << setw(2) << Second << "秒       ";
}

ChargeRecord::ChargeRecord(double amount):Record(amount){
    cout << endl;
    cout << "请选择支付方式：" << endl;
    for (int i = 0; i < 3;i++){
        cout << i + 1 << "：" << method[i] << endl;
    }  
    cin >> Method;

    cout << endl;
    cout << "成功充值 " << amount << " 元！" << endl;
}

void ChargeRecord::Print_ChargeRecord()const {
    Print_Record();
    cout << method[Method - 1] << endl;
}

ConsumeRecord::ConsumeRecord(double amount):Record(amount){
    cout << endl;
    cout << "请选择消费地点：" << endl;
    for (int i = 0; i < 8;i++){
        cout << i + 1 << "：" << place[i] << endl;
    }
    cin >> Place;

}

void ConsumeRecord::Print_ConsumeRecord()const {
    Print_Record();
    cout << place[Place - 1] << endl;
}

WaterRecord::WaterRecord(int T):Time(T),Record(T*Rate){
}

void WaterRecord::Print_WaterRecord()const {
    Print_Record();
    cout << Time << endl;
}

Card::Card(int Num, Student * stu):Number(Num),student(stu),Password("000000"){
    Value = 0;
    WaterAccount = 0;
    State = OFF;

    cout << endl;
    cout << "学号为 " << setfill('0') << setw(4) << stu->getID() << " 的学生成功绑定校园卡 " << setfill('0') << setw(4) << Number << endl;
}
Card::~Card(){
	for(int i=0;i<10;i++){
		if(!charge_record.empty()){
			delete charge_record.front();
            charge_record.pop_front();
		}
		if(!consume_record.empty()){
			delete consume_record.front();
            consume_record.pop_front();
		}
		if(!water_record.empty()){
			delete water_record.front();
            water_record.pop_front();
		}
	}
}
void Card::add(double amount){
    Value += amount;
}
void Card::minus(double amount){
    Value -= amount;
}
void Card::addWater(double amount){
    WaterAccount += amount;
}
void Card::minusWater(double amount){
    WaterAccount -= amount;
}
void Card::setState(state st){
    State = st;
}
void Card::setPassword(string newp){
    Password = newp;
}
bool Card::isChecked(){
    string temp;
    for (int i = 9; i >= 0;i--){
        cout << endl;
        cout << "请输入校园卡密码：" << endl;
        cin >> temp;

        if(temp==Password){
            cout << "密码正确！" << endl;
            return true;
        }            
        else
            cout << "密码错误！还剩 " << i << " 次机会" << endl;
    }
    cout << "机会已用完！验证失败。" << endl;
    return false;
}
void Card::recordCharge( ChargeRecord *cr){
    if(charge_record.size()>=10){
        delete charge_record.front();
        charge_record.pop_front();
    }
    charge_record.push_back(cr);
}
void Card::recordConsume( ConsumeRecord *cr){
    if(consume_record.size()>=10){
        delete consume_record.front();
        consume_record.pop_front();
    }
    consume_record.push_back(cr);
}
void Card::recordWater( WaterRecord *wr){
    if(water_record.size()>=10){
        delete water_record.front();
        water_record.pop_front();
    }
    water_record.push_back(wr);
}

void Card::printCharge() const{
    cout << endl;
    cout << "以下是该校园卡的近10条充值记录:" << endl;
    cout << "金额              时间               支付方式" << endl;
    for (int i = 0; i<charge_record.size(); i++)
    {
        charge_record.at(i)->Print_ChargeRecord();
    }
}
void Card::printConsume() const{
    cout << endl;
    cout << "以下是该校园卡的近10条消费记录:" << endl;
    cout << "金额              时间               消费地点" << endl;
    for (int i = 0; i<consume_record.size(); i++)
    {
        consume_record.at(i)->Print_ConsumeRecord();
    }
}
void Card::printWater() const{
    cout << endl;
    cout << "以下是该校园卡的近10条热水使用记录:" << endl;
    cout << "金额              时间              时长（分钟）" << endl;
    for (int i = 0; i<water_record.size(); i++)
    {
        water_record.at(i)->Print_WaterRecord();
    }
}
