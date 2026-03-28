#include <fstream>
#include <iostream>
#include "b1.h"
//#include "json.hpp"
//#include <cmath>
using std::clog;
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::ifstream;
using std::ofstream;

void read_f_file(string name){
	ifstream f_file;
	f_file.open(name);
	for(int i=1;i<=1000;i++){
			f_file >> *f_value[i];
	}
}

void write_f_file(string name){
	ofstream f_file;
	f_file.open(name);
	for(int i=1;i<=1000;i++){
			f_file << *f_value[i] << endl;
	}
}

void read_d_file(string name){
	ifstream d_file;
	d_file.open(name);
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			d_file >> datas[i][j];
		}
	}
}

int main(){
	clog<<"Loading net...\n";
	load();
	clog<<"Loaded.\n";
	for(;;){
		string cmd;
		cout<<">";
		cin>>cmd;
		if(cmd == "f_read" or cmd == "f_load"){
			string name;
			cin>>name;
			read_f_file(name);
		}
		else if(cmd == "f_write" or cmd == "f_save"){
			string name;
			cin>>name;
			write_f_file(name);
		}
		else if(cmd == "d_read" or cmd == "d_load"){
			string name;
			cin>>name;
			read_d_file(name);
		}
		else if(cmd == "cat_d"){
			for(int i=1;i<=9;i++){
				for(int j=1;j<=9;j++){
					cout<<datas[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		else if(cmd == "run"){
			run();
			cout<<"Output:"<<return_output;
		}
		else if(cmd == "training"){
			long long t_i;
			int max;
			double step,answer;
			cin>>step>>answer>>t_i>>max;
			for(long long i=1;i<=t_i;i++){
				training(step,answer,max);
				run();
				cout<<"Training "<<i<<" Result:"<<return_output<<endl;
				step = -step;
			}
		}
		else if(cmd == "?" or cmd == "help"){
			cout<<"f_load/f_read <FILE>"<<endl;
			cout<<"f_write/f_save <FILE>"<<endl;
			cout<<"d_load/d_read <FILE>"<<endl;
			cout<<"cat_d"<<endl;
			cout<<"run"<<endl;
			cout<<"training <STEP> <ANSWER> <LOOP> <MAX>"<<endl;
		}
		else{
			cout<<"[ERR] Command Not Found Error"<<endl;
		}
		cout<<endl;
	}
}
