#include <iostream>
#include <cmath>
using namespace std;

void input(double number[], double MAX_SIZE, double& used_number){
	int next, i = 0;
	cout <<"Input a positive number up to 20: ";
	
	cin >> next;
	for(i = 0; i < MAX_SIZE && next > 0; i++){
		if(next >= 0){
		number[i] = next;
		cin >>next;	
		}
		else
		break;
	}
	used_number = i;
}

double mean(double number[], double used_number){
	double sum = 0;
	for (int i = 0; i < used_number; i++){ 
		sum += number[i];
	}
	return sum/used_number;
}

double standard_dev(double number[], double used_number, double mean)
{
	cout.setf(ios::fixed);
	cout.setf (ios::showpoint);
	cout.precision(3);
	double sum = 0, initial = 0;
	
	for (int i = 0; i < used_number; i++){
		initial = number[i] - mean;
		initial *= initial;
		sum += initial;
 	}
	return sqrt(sum/used_number);
}

void output(double number[], double used_number, double mean){
	cout <<"With the datas ";
	for(int i = 0; i < used_number; i++){
		cout <<number[i]<<" ";
	}
	cout <<", we can have an Average data of "<<mean<<endl<<"that will have a standard devation of "<< standard_dev(number, used_number, mean);
}

int main(){
	const int MAX_SIZE = 20;
	double number[MAX_SIZE], used_number;
	double average;
	
	input(number, MAX_SIZE, used_number);
	average = mean(number, used_number);
	cout <<endl<<endl;
	
	output(number, used_number, average);
}