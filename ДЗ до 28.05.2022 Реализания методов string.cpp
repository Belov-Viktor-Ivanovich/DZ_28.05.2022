

#include <iostream>
#include"String.cpp"

int main()
{
	String str("khgjhgkjbkj");
	cout << str.size() << endl;
	str.show();

	str.resize(15, 'c');
	cout << str.empty() << endl;
	cout << str.size()<<endl;
	str.show();

	/*str.clear();
	cout << str.size()<<endl;
	cout << str.empty() << endl;
	str.show();*/

	str.push_back('a');
	cout << str.size() << endl;
	cout << str.empty() << endl;
	str.show();

	str.append(2, 'a');
	cout << str.size() << endl;
	str.show();

	string str2("fff");
	str.append(str2);
	cout << str.size() << endl;
	str.show();

	String str21("sss");
	str.append(str21);
	cout << str.size() << endl;
	str.show();
	str.append(str2, 2, 3);
	cout << str.size() << endl;
	str.show();

	str.erase(20);
	cout << str.size() << endl;
	str.show();

	str.erase(15, 2);
	cout << str.size() << endl;
	str.show();

	str.insert(10, 2, 'q');
	cout << str.size() << endl;
	str.show();

	str.insert(2, str2);
	cout << str.size() << endl;
	str.show();

	str.insert(2, str21);
	cout << str.size() << endl;
	str.show();

	String str3;
	str3 = str.subStr(4);
	cout << str3.size() << endl;
	str3.show();
	str = str3;
	cout << str.size() << endl;
	str.show();

	str = str.subStr(2, 12);
	cout << str.size() << endl;
	str.show();

	str.replace(9, 5, '9');
	cout << str.size() << endl;
	str.show();

	str.replace(9, 5, str21);
	cout << str.size() << endl;
	str.show();

	str.replace(9, 5, str2);
	cout << str.size() << endl;
	str.show();

	str.replace(2, 5, 'f');
	cout << str.size() << endl;
	str.show();

	cout<<str.find(str2)<<endl;
	cout << str.rfind(str2) << endl;
	cout << str.find_first_of(str2,7) << endl;
	cout << str.find_last_of(str2) << endl;
	cout << str.find_first_not_of(str2) << endl;
	cout << str.find_last_not_of(str2) << endl;
	cout << str.c_str();
}

