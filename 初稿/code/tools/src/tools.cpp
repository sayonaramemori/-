#include"head.h"
#define COMMENT '#'

//print any message
void print(const std::string& msg){
    std::cout<<msg<<std::endl;
    return;
}

//get all lines in the form of string
std::vector<std::string> dataControl::read(const std::string& name){
    std::ifstream ifs(name);
    std::vector<std::string> res;
    if(ifs.is_open()){
        std::string line;
        while(std::getline(ifs,line)){
            if(line.size()==0)continue;
            if(line.find(COMMENT)==std::string::npos)
            res.push_back(line);
        }
    }else{
        std::cout<<"open file failed, nothing has been read"<<std::endl;
    }
    return res;
}

//convert a string to double sequence
std::vector<double> dataControl::toNumber(const std::string& str){
    std::vector<double> res;
    int begin = 0;
    for(int i=0;i<str.size();++i){
        if(str[i]==' '){
            continue;
        }else{
            begin = i;
            ++i;
            while(str[i]!=' '&&i<str.size())++i;
            res.push_back(std::stod(str.substr(begin,i-begin)));
        }
    }
    return res;
}

//print a vector<double> 
void dataControl::printNumber(const std::vector<double>& number){
    std::for_each(number.begin(),number.end(),[](double it){
        std::cout<<it<<std::endl;
    });
}


//construction function
dataControl::dataControl(const std::string& name,int size){
    fileName = name;
    getDatas();
    datas.resize(size);
}

//To modify a value 
bool dataControl::set(int type,int pos,double val){
    if(datas[type].size()>pos){
        datas[type][pos] = val;
        return true;
    }else{
        if(datas[type].size()==pos){
            datas[type].push_back(val);
            return true;
        }else{
            print("set val failed");
            return false;
        }
    }
}

bool dataControl::push(int type, double val){
    if(datas.size()>type){
        datas[type].push_back(val);
        return true;
    }else return false;
}

dataUnit dataControl::get(int type){
    if(datas.size()>type){
        return datas[type];
    }else{
        print("get failed");
        return dataUnit();
    }
}

dataUnit& dataControl::operator[](std::size_t type){
    return datas[type];
}

//print all datas have been read
void dataControl::printAll(){
    std::cout<<"line number:"<<datas.size()<<std::endl;
    for_each(datas.begin(),datas.end(),[&](const dataUnit& val){
        printNumber(val);
    });
    return;
}

//get datas from the specific file
void dataControl::getDatas(){
    lineStr = read(fileName);
    for_each(lineStr.begin(),lineStr.end(),[&](const std::string& line){
            datas.push_back(toNumber(line));
    });
}
