#include"head.h"
#include<cmath>


enum seq{day,time,ratioCrush,oreSize,relativeSize,E,diameter,eWidth,betaR,betaM,betaF,last};

void printline(){
    std::cout<<"-----------------------"<<std::endl;
}

void getS(dataControl& data){
    auto ratio = data.get(ratioCrush);
    double S = ratio[0];
    double S1 = ratio[1];
    double S2 = ratio[2];
    double S3 = S/(S1*S2);
    double exponent = 1;
    double Sa = pow(S,exponent/3);

    printline();
    data.push(ratioCrush,S3);
    std::cout<<"S="<<S<<" S1="<<S1<<" S2="<<S2<<" S3="<<S3<<" Sa="<<Sa<<std::endl;
    printline();
}

void getMaxSize(dataControl& data){
    auto ratio = data.get(ratioCrush);
    double D = data.get(oreSize)[0];
    double d4 = D/ratio[1];
    double d8 = d4/ratio[2];
    double d11 = d8/ratio[3];

    data.push(oreSize,d4);
    data.push(oreSize,d8);
    data.push(oreSize,d11);
    std::cout<<"D="<<D<<" d4="<<d4<<" d8="<<d8<<" d11="<<d11<<std::endl;
    printline();
}

void confirm_e(dataControl& data){
    if(data[eWidth].size()!=0){
        auto e = data[eWidth];
        std::cout<<"e4="<<e[0]<<" e8="<<e[1]<<" e13="<<e[2]<<std::endl;
        printline();
        return;
    }
    auto size = data[oreSize];
    auto Z = data[relativeSize];
    double e4 = size[1]/Z[0];
    double e8 = size[2]/Z[1];
    //常规筛分制度
    double e13 = size[3];

    std::cout<<"请输入e的取值"<<std::endl;
    std::cout<<"e4计算值："<<e4<<" 请输入："<<std::endl;
    std::cin>>e4;
    std::cout<<"e8计算值："<<e8<<" 请输入："<<std::endl;
    std::cin>>e8;
    std::cout<<"e13计算值："<<e13<<std::endl;
    std::cout<<"是否采用等值筛分制度[y/n]"<<std::endl;
    char flag = 'y';
    std::cin>>flag;
    if(flag=='y'){
        e13=8;
    }else e13=10;

    data[eWidth] = {e4,e8,e13};
    std::cout<<"e4="<<e4<<" e8="<<e8<<" e13="<<e13<<std::endl;
    printline();
}

void confirm_AE(dataControl& data){
    if(data[diameter].size()!=0){
        auto EN = data[E];
        auto dia = data[diameter];
        std::cout<<"a1="<<dia[0]<<" a2="<<dia[1]<<" a3="<<dia[2]<<std::endl;
        std::cout<<"E1="<<EN[0]<<" E2="<<EN[1]<<" E3="<<EN[2]<<std::endl;
        printline();
        return;
    }
    auto size = data[oreSize];
    auto e = data[eWidth];
    double a1,a2,a3;
    double E1,E2,E3;
    std::cout<<"请输入a1的值,E1=60%"<<e[0]<<"<a1<"<<size[1]<<std::endl;
    E1=0.6;
    std::cin>>a1;
    std::cout<<"请输入a2的值,E2=80%"<<e[1]<<"<a2<"<<size[2]<<std::endl;
    E2 = 0.8;
    std::cin>>a2;
    std::cout<<"若常规筛分制度，a3=10,E3=85%"<<std::endl;
    std::cout<<"是否选用等值筛分制度[y/n]"<<std::endl;
    char flag = 'y';
    std::cin>>flag;
    if(flag=='y'){
        int type = 0;
        std::cout<<"请输入选用的方案[1/2/3]"<<std::endl;
        std::cin>>type;
        switch(type){
            case 1:
                a3 = size[3]*1.1;
                E3 = 0.73;
                break;
            case 2:
                a3 = size[3]*1.2;
                E3 = 0.65;
                break;
            case 3:
                a3 = size[3]*1.3;
                E3 = 0.6;
                break;
            default:
                break;
        }
    }else{
        a3 = e[2];
        E3 = 0.85;
    }
    data[diameter] = {a1,a2,a3};
    data[E] = {E1,E2,E3};
    std::cout<<"a1="<<a1<<" a2="<<a2<<" a3="<<a3<<std::endl;
    std::cout<<"E1="<<E1<<" E2="<<E2<<" E3="<<E3<<std::endl;
}

void getBR(dataControl& data){
    if(data[betaR].size()!=0){
        auto BR = data[betaR];
        std::cout<<"betaR:B1="<<BR[0]<<std::endl;
        return;
    }
    double Z = data[eWidth][0]/data[oreSize][0];
    double B1;
    std::cout<<"粗筛与原矿粒度之比Z1为："<<Z<<std::endl;
    std::cout<<"请输入B1-"<<data[eWidth][0]<<"的值"<<std::endl;
    std::cin>>B1;
    data[betaR] = {B1};
    std::cout<<"betaR:B1="<<data[betaR][0]<<std::endl;
}

void printQ(char num,double val){
    std::cout<<"Q"<<num<<"="<<val<<"t/h"<<std::endl;
}

void printY(char num,double val){
    std::cout<<"y"<<num<<"="<<val*100<<"%"<<std::endl;
}

void rough(dataControl& data){
    auto EN = data[E];
    double mass = data[day][0];
    auto times = data[time];

    getBR(data);
    double B1 = data[betaR][0];
    double Q1 = mass/times[0];
    double y1 = 1;
    double Q2 = Q1*EN[0]*B1;
    double y2 = Q2/Q1;
    double Q4 = Q1 - Q2;
    double y4 = y1 - y2;

    printQ('1',Q1);
    printY('1',y1);
    printQ('2',Q2);
    printY('2',y2);
    printQ('3',Q4);
    printY('3',y4);
    printQ('5',Q1);
    printY('5',y1);
}

void getBM(dataControl& data){
    double Z1 = data[diameter][1]/data[oreSize][0];
    std::cout<<"Z1="<<Z1<<" 请输入B1-"<<
}

void middling(dataControl& data){

}

void start(dataControl& data){
    getS(data);
    getMaxSize(data);
    confirm_e(data);
    confirm_AE(data);
    rough(data);
}

int main(int argc,char* argv[]){
    if(argc!=2){
        std::cout<<"please give an input file"<<std::endl;
        exit(0);
    }
    std::string name(argv[1]);
    dataControl test(name,last);
    start(test);
    return 0;
}
