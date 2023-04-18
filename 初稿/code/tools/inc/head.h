#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<fstream>

using dataOrigin = std::vector<std::string>;
using dataUnit = std::vector<double>;

class dataControl{
public:
    dataControl(const std::string& name,int size);
    bool set(int type,int pos,double val);
    bool push(int type,double val);
    dataUnit get(int type);
    void printAll();
    dataUnit& operator[](std::size_t type);
private:
    std::string fileName;
    dataOrigin lineStr;
    std::vector<dataUnit> datas;
private:
    dataOrigin read(const std::string& name);
    dataUnit toNumber(const std::string& str);
    void printNumber(const dataUnit& number);
    void getDatas();
};
