#pragma once
class String
{
	char* ar;
	int lengs = 0;
public:
	void show()
	{
		for (int i = 0; ar[i] != '\0'; i++)
		{
			cout << ar[i];
		}
		cout << endl << endl;
	}
	String()
	{

	}
	String(const char str[]) {
		for (int i = 0; str[i] != '\0'; i++)
		{
			lengs++;
		}
		ar = new char[lengs + 1];
		for (int i = 0; i < lengs; i++)
		{
			ar[i] = str[i];
		}
		ar[lengs] = '\0';
	}
	int size() {
		return lengs;
	}
	void resize(int n, char c)
	{
		char* buf = new char[n];
		if (n < lengs)
		{
			lengs = n;
			for (int i = 0; i < lengs; i++)
			{
				buf[i] = ar[i];
			}
		}
		else {
			for (int i = 0; i < lengs; i++)
			{
				buf[i] = ar[i];
			}

			for (int i = lengs; i < n; i++)
			{
				buf[i] = c;
			}
			lengs = n;
		}
		buf[n] = '\0';
		delete[]ar;
		ar = buf;
	}
	void clear()
	{
		for (int i = 0; i < lengs; i++)
		{
			ar[i] = NULL;
		}
	}
	bool empty()
	{
		bool flag = true;
		for (int i = 0; i < lengs; i++)
		{
			if (ar[i] != NULL) {
				flag = false;
				return flag;
			}
		}
		return flag;

	}
	void push_back(char c)
	{
		char* buf = new char[lengs + 1];
		for (int i = 0; i < lengs; i++)
		{
			buf[i] = ar[i];
		}
		buf[lengs] = c;
		buf[lengs] = '\0';
		ar = nullptr;
		delete[]ar;
		ar = buf;
		lengs++;
	}
	void append(int n, char c)
	{
		char* buf = new char[lengs + n];
		for (int i = 0; i < lengs; i++)
		{
			buf[i] = ar[i];
		}
		for (int i = lengs; i < lengs+n; i++)
		{
			buf[i] = c;
		}
		buf[lengs+n] = '\0';
		ar = nullptr;
		delete[]ar;
		ar = buf;
		lengs+=n;
	}
	void append(string str2)
	{
		int n = str2.size();
		char* buf = new char[lengs + n];
		for (int i = 0; i < lengs; i++)
		{
			buf[i] = ar[i];
		}
		for (int i = lengs,k=0; i < lengs + n; i++)
		{
			buf[i] = str2[k++];
		}
		buf[lengs + n] = '\0';
		ar = nullptr;
		delete[]ar;
		ar = buf;
		lengs += n;
	}
	void append(String str2)
	{
		int n = str2.size();
		char* buf = new char[lengs + n];
		for (int i = 0; i < lengs; i++)
		{
			buf[i] = ar[i];
		}
		for (int i = lengs, k = 0; i < lengs + n; i++)
		{
			buf[i] = str2.ar[k++];
		}
		buf[lengs + n] = '\0';
		ar = nullptr;
		delete[]ar;
		ar = buf;
		lengs += n;
	}
	void append(string str2,int pos,int n)
	{
		if (pos < lengs && pos >= 0) {
			char* buf = new char[lengs + n];
			int s = 0;

			for (int i = 0; i < pos; i++)
			{
				buf[i] = ar[s++];
			}
			for (int i = pos, k = 0; i < pos + n; i++)
			{
				buf[i] = str2[k++];
			}
			for (int i = pos + n; i < lengs + n; i++)
			{
				buf[i] = ar[s++];
			}
			buf[lengs + n] = '\0';
			ar = nullptr;
			delete[]ar;
			ar = buf;
			lengs += n;
		}
	}
	void erase(int pos)
	{
		char* buf = new char[pos];
		for (int i = 0; i < pos; i++)
		{
			buf[i] = ar[i];
		}
		buf[pos] = '\0';
		ar = nullptr;
		delete[]ar;
		ar = buf;
		lengs = pos;
	}
	void erase(int pos,int n)
	{
		if (pos < lengs && pos >= 0)
		{
			char* buf;
			int k = 0;
			if ((pos + n) > lengs) {
				buf = new char[pos];
			}
			else  buf = new char[lengs - n];
			for (int i = 0; i < pos; i++)
			{
				buf[k++] = ar[i];
			}
			for (int i = pos + n; i < lengs; i++)
			{
				buf[k++] = ar[i];
			}

			buf[k] = '\0';
			ar = nullptr;
			delete[]ar;
			ar = buf;
			lengs = k;
		}
	}
	void insert(int pos,int n,char c)
	{
		if (pos >= 0 && pos < lengs)
		{
			
			char* buf = new char[lengs + n];
			for (int i = 0; i < pos; i++)
			{
				buf[i] = ar[i];
			}
			for (int i = pos; i < pos+n; i++)
			{
				buf[i] = c;
			}
			for (int i = pos+n,k=pos; i < lengs; i++)
			{
				buf[i] = ar[(k++)];
			}
			buf[lengs] = '\0';
			ar = nullptr;
			delete[]ar;
			ar = buf;
			lengs +=n;
		}
	}
	void insert(int pos,string str2)
	{
		if (pos >= 0 && pos < lengs)
		{
			int n = str2.size();
			char* buf = new char[lengs +str2.size()];
			for (int i = 0; i < pos; i++)
			{
				buf[i] = ar[i];
			}
			for (int i = pos,k=0; i < pos + n; i++)
			{
				buf[i] = str2[k++];
			}
			for (int i = pos + n, k = pos; i < lengs; i++)
			{
				buf[i] = ar[(k++)];
			}
			buf[lengs] = '\0';
			ar = nullptr;
			delete[]ar;
			ar = buf;
			lengs += n;
		}
	}
	void insert(int pos, String str2)
	{
		if (pos >= 0 && pos < lengs)
		{
			int n = str2.size();
			char* buf = new char[lengs + str2.size()];
			for (int i = 0; i < pos; i++)
			{
				buf[i] = ar[i];
			}
			for (int i = pos, k = 0; i < pos + n; i++)
			{
				buf[i] = str2.ar[k++];
			}
			for (int i = pos + n, k = pos; i < lengs; i++)
			{
				buf[i] = ar[(k++)];
			}
			buf[lengs] = '\0';
			ar = nullptr;
			delete[]ar;
			ar = buf;
			lengs += n;
		}
	}
	char* subStr(int pos)
	{
		if (pos < lengs && pos >= 0) {
			char* buf = new char[lengs - pos];
			int k = 0;
			for (int i = pos; i < lengs; i++)
			{
				buf[k++] = ar[i];
			}
			buf[k] = '\0';
			ar = nullptr;
			delete[]ar;
			ar = buf;
			lengs-=pos;
		}
		return ar;
	}
	char* subStr(int pos,int n)
	{
		if (pos < lengs && pos >= 0) {
			char* buf;
			if(pos+n>lengs)buf = new char[lengs - pos];
			else buf = new char[n];
			int k = 0;
			if ((pos + n) < lengs)lengs = pos + n;
			for (int i = pos; i < lengs; i++)
			{
				buf[k++] = ar[i];
			}
			buf[k] = '\0';
			ar = nullptr;
			delete[]ar;
			ar = buf;
			lengs -= pos;
		}
		return ar;
	}
	void replace(int pos, int n, char c)
	{
		if (pos >= 0 && pos < lengs) {
			char* buf = new char[lengs];
			for (int i = 0; i < pos; i++)
			{
				buf[i] = ar[i];
			}
			if ((pos + n) > lengs) {
				for (int i = pos; i < lengs; i++)
				{
					buf[i] = c;
				}
			}
			else {
				for (int i = pos; i < pos+n; i++)
				{
					buf[i] = c;
				}
				for (int i = pos+n; i < lengs; i++)
				{
					buf[i] = ar[i];
				}
			}

			buf[lengs] = '\0';
			ar = nullptr;
			delete[]ar;
			ar = buf;
		}
	}
	void replace(int pos, int n, String str21)
	{
		if (pos >= 0 && pos < lengs) {
			char* buf = new char[lengs];
			for (int i = 0; i < pos; i++)
			{
				buf[i] = ar[i];
			}
			if ((pos + n) > lengs) {
				for (int i = pos,k=0; i < lengs; i++)
				{
					buf[i] = str21.ar[k++];
				}
			}
			else {
				int k = 0;
				for (int i = pos; i < pos + n; i++)
				{
					buf[i] = str21.ar[k++];
				}
				for (int i = pos + n; i < lengs; i++)
				{
					buf[i] = ar[i];
				}
			}

			buf[lengs] = '\0';
			ar = nullptr;
			delete[]ar;
			ar = buf;
		}
	}
	void replace(int pos, int n, string str2)
	{
		if (pos >= 0 && pos < lengs) {
			char* buf = new char[lengs];
			for (int i = 0; i < pos; i++)
			{
				buf[i] = ar[i];
			}
			if ((pos + n) > lengs) {
				for (int i = pos, k = 0; i < lengs; i++)
				{
					buf[i] = str2[k++];
				}
			}
			else {
				int k = 0;
				for (int i = pos; i < pos + n; i++)
				{
					buf[i] = str2[k++];
				}
				for (int i = pos + n; i < lengs; i++)
				{
					buf[i] = ar[i];
				}
			}

			buf[lengs] = '\0';
			ar = nullptr;
			delete[]ar;
			ar = buf;
		}
	}
	int find(string str2, int pos = 0)
	{
		bool flag;
		for (int i = 0; i < lengs; i++)
		{
			flag = false;
			if (ar[i] == str2[0])
			{
				if (str2.size() > lengs-i)return-1;
				flag = true;
				for (int j = 0; j < str2.size(); j++)
				{
					if (ar[i + j] != str2[j]) {
						flag = false;
						break;
					}
				}
				if (flag)return i;
			}
		}
		return -1;
	}
	int rfind(string str2, int pos = 0) 
	{
		int k = (str2.size()-1);
		bool flag;
		for (int i = lengs-1; i >= 0; i--)
		{
			flag = false;
			if (ar[i] == str2[k])
			{			
				flag = true;
				for (int j = i; j >= str2[0]; j--)
				{
					if (ar[i] != str2[k--]) {
						flag = false;
						k = (str2.size() - 1);
						break;
					}
				}
				if (flag)return i;
			}
		}
		return -1;
	}
	int find_first_of(string str2, int pos = 0)
	{
		for (int i = pos; i < lengs; i++)
		{
			for (int j = 0; j < str2.size(); j++)
			{
				if (ar[i] == str2[j])
				{
					return i;
				}
			}
		}
		return -1;
	}
	int find_last_of(string str2)
	{
		for (int i = lengs-1; i >= 0; i--)
		{
			for (int j = 0; j < str2.size(); j++)
			{
				if (ar[i] == str2[j])
				{
					return i;
				}
			}
		}
		return -1;
	}
	int find_first_not_of(string str2)
	{
		bool flag = false;
		for (int i = 0; i < lengs; i++)
		{
			if (ar[i] != str2[0]) {
				flag = true;
				for (int j = 0; j < str2.size(); j++)
				{
					if (ar[i] == str2[j])
					{
						flag = false;
						break;
					}
				}
				if (flag)return i;
			}
		}
		return -1;
	}
	int find_last_not_of(string str2)
	{
		bool flag = false;
		for (int i = lengs-1; i >= 0; i--)
		{
			if (ar[i] != str2[0]) {
				flag = true;
				for (int j = 0; j < str2.size(); j++)
				{
					if (ar[i] == str2[j])
					{
						flag = false;
						break;
					}
				}
				if (flag)return i;
			}
		}
		return -1;
	}
	char* c_str()
	{
		return ar;
	}
};

