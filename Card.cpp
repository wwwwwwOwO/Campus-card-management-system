#include <iostream>
#include "Student.hpp"
#include "Card.hpp"
Record::Record(double amount):Amount(amount){
    cout << "\n���������ڣ��¡��գ��ÿո��������" << endl;
    cin >> Month >> Day;
    cout << "\n�����뵱ǰʱ�䣨ʱ���֡��룬�ÿո��������" << endl;
    cin >> Hour >> Minute >> Second;
}

void Record::Print_Record()const{
    cout << setfill(' ') << left << setw(10) << Amount;
    cout << setfill(' ') << setw(2) << Month << "��" << setfill(' ') << setw(2) << Day << "��";
    cout << setfill(' ') << setw(2) << Hour << "ʱ" << setfill(' ') << setw(2) << Minute << "��" << setfill(' ') << setw(2) << Second << "��       ";
}

ChargeRecord::ChargeRecord(double amount):Record(amount){
    cout << endl;
    cout << "��ѡ��֧����ʽ��" << endl;
    for (int i = 0; i < 3;i++){
        cout << i + 1 << "��" << method[i] << endl;
    }  
    cin >> Method;

    cout << endl;
    cout << "�ɹ���ֵ " << amount << " Ԫ��" << endl;
}

void ChargeRecord::Print_ChargeRecord()const {
    Print_Record();
    cout << method[Method - 1] << endl;
}

ConsumeRecord::ConsumeRecord(double amount):Record(amount){
    cout << endl;
    cout << "��ѡ�����ѵص㣺" << endl;
    for (int i = 0; i < 8;i++){
        cout << i + 1 << "��" << place[i] << endl;
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
    cout << "ѧ��Ϊ " << setfill('0') << setw(4) << stu->getID() << " ��ѧ���ɹ���У԰�� " << setfill('0') << setw(4) << Number << endl;
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
        cout << "������У԰�����룺" << endl;
        cin >> temp;

        if(temp==Password){
            cout << "������ȷ��" << endl;
            return true;
        }            
        else
            cout << "������󣡻�ʣ " << i << " �λ���" << endl;
    }
    cout << "���������꣡��֤ʧ�ܡ�" << endl;
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
    cout << "�����Ǹ�У԰���Ľ�10����ֵ��¼:" << endl;
    cout << "���              ʱ��               ֧����ʽ" << endl;
    for (int i = 0; i<charge_record.size(); i++)
    {
        charge_record.at(i)->Print_ChargeRecord();
    }
}
void Card::printConsume() const{
    cout << endl;
    cout << "�����Ǹ�У԰���Ľ�10�����Ѽ�¼:" << endl;
    cout << "���              ʱ��               ���ѵص�" << endl;
    for (int i = 0; i<consume_record.size(); i++)
    {
        consume_record.at(i)->Print_ConsumeRecord();
    }
}
void Card::printWater() const{
    cout << endl;
    cout << "�����Ǹ�У԰���Ľ�10����ˮʹ�ü�¼:" << endl;
    cout << "���              ʱ��              ʱ�������ӣ�" << endl;
    for (int i = 0; i<water_record.size(); i++)
    {
        water_record.at(i)->Print_WaterRecord();
    }
}
