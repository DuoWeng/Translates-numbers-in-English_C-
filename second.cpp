#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;
string digit[] = {"","one","two","three","four","five","six","seven","eight","nine"};
string tens[] = {"","","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
string teens[] = {"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
string d2digit(int);
string d3digit(int);
string d6digit(int);
string d9digit(int);
int main(void){
    bool stop = false;
    long num = 0;
    do{
	cout << "Please enter a number:"<<endl;
    	std::string input= "";
    	cin >> input;
	int len = input.length();
    	int i;
    	for(i = 0;i < len;i++){
	if(input[i] > '9' || input[i] < '0') {stop = true;break;}}
	if(!stop){
		cout <<"The number is :"<<input<<endl;
		int val;
		if(len < 10) {
		stringstream(input) >> val;
		if(val == 0) {cout << "zero"<<endl;}
		else if(val < 10) cout << digit[val]<<endl;
		else if(val < 100) cout << d2digit(val)<<endl;
		else if(val < 1000) cout << d3digit(val)<<endl;
		else if(val < 1000000) cout << d6digit(val)<<endl;
		else if(val < 1000000000) cout<< d9digit(val)<<endl;}
		else if(len == 10) { int i,j;stringstream(input.substr(0,1)) >> i;stringstream(input.substr(1)) >> j;cout << digit[i]<< " billion "<<d9digit(j)<<endl;}
		else cout << "You input invalid number. Try again."<<endl;
		}
      }while(!stop);
      return 0;
}

string d2digit(int i){
if(i < 10) return digit[i];
if(i < 20) return teens[i%10];
if(i%10 == 0) return tens[i/10];
return tens[i/10]+" "+digit[i%10];
}
string d3digit(int i){
  if(i < 100) return d2digit(i);
  return digit[i/100]+" hundred "+d2digit(i%100);
}
string d6digit(int i){
  if(i < 1000) return d3digit(i);
  if(i < 10000) return digit[i/1000]+" thousand "+d3digit(i%1000);
  return d3digit(i/1000)+" thousand "+d3digit(i%1000);
}
string d9digit(int i){
  if(i < 1000000) return d6digit(i);
  if(i < 100000000) return d2digit(i/1000000)+" million "+d6digit(i%1000000);
  return d3digit(i/1000000)+" million "+d6digit(i%1000000);
}




