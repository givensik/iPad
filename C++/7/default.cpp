#include <iostream>
#include <string>
using namespace std;

int main() {
	string s  = "1000";
	int num = 2333;


	// string to integer
	cout << "- 문자열 int형으로 변환 -\n";
	int num2 = stoi(s);	// stod => double 타입, stoll => long long 타입
	cout << "숫자 : " << num << " + " << num2 << " = " << num + num2 << "\n";

	cout << "====================================\n";

	// integer to string
	cout << "- 숫자 문자열로 변환 -\n";
	string s2 = to_string(num);
	cout << "문자열 : " << s << " + " << s2 << " = " << s + s2 << "\n";


	return 0;
}