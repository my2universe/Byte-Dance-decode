#include<string>
#include<vector>
#include<iostream>
using namespace std;
//class Solution {
//public:
//	vector<vector<int>> permute(string s) {
//		vector<vector<string>> res;
//		helper(s, 0,  out, res);
//		return res;
//	}
//	//从前往后，以level为标志判断是否遍历了所有的字符串
//	vector<vector<string>> helper(string s, int level, vector<string>& out, vector<vector<string>>& res) {
//		if (level == s.size()) { return res; }
//		for (int i = 1; i < s.size(); ++i) {
//			if (s[i] == 0)
//			{
//				if (s[i - 1] == 1 || s[i - 1] == 2)//只能组合成2位数
//				{
//					for (int m = 0; m < res.size(); m++)
//					{
//						res[m].pop_back();
//						res[m].push_back(s.substr(i - 2, 2));
//					}
//				}
//				else
//				{
//					res.clear();
//					return res;
//				}
//				
//			}
//			if (s[i] != 0)
//			{
//				if (s[i-1]==1||s[i-1]==2&&s[i]<=6)//按单个字符处理和按双字符处理//这样写不行可能弹出两个字符
//				{
//					vector<vector<string>>res1=res;
//					vector<vector<string>>res2=res;
//					for (int m = 0; m < res1.size(); m++)//shuang 
//					{
//						string tmp = res1[m].back();
//						if (tmp.size()==1)
//						{
//							res1[m].pop_back();
//							res1[m].push_back(s.substr(i - 2, 2));//dan
//						}
//						else if(tmp.size()==2)//既可以拆成12，也可111
//						{
//							res1[m].pop_back();
//							res1[m].push_back(s.substr(i - 2, 2));//dan
//							res1[m].push_back(s.substr(i - 2, 2));//dan
//						}
//
//					}
//					for (int m = 0; m < res2.size(); m++)
//					{
//						res2[m].push_back(s.substr(i - 1, 1));
//					}
//					for (int m = 0; m < res2.size(); m++)
//					{
//						res.push_back(res1[m]);
//					}
//				
//				}
//				else
//				{
//					for (int m=0;m<res.size();m++)
//					{
//						
//						res[m].push_back(s.substr(i - 1, 1));
//					}
//				}
//			}
//		}
//	}
//};
////class Solution {
////public:
////	vector<string> restoreIpAddresses(string s) {
////		vector<string> res;
////		restore(s, "", res);
////		return res;
////	}
////	void restore(string s, string out, vector<string> &res) {
////			if (s.empty()) res.push_back(out);
////			else {
////				for (int i = 1; i <= 2; ++i) {
////					if (s.size() >= i && isValid(s.substr(0,i))) {
////						if (s[0] == 0)return;
////						else
////							restore(s.substr(i), out + ("A" + atoi(s.substr(0, i).c_str()) - 1),res);
////					}
////				}
////			}
////	}
////	bool isValid(string s)
////	{
////		if (s.empty() || s.size() > 2)return false;
////		int res = atoi(s.c_str());
////		return res <= 26 && res >= 0;
////	}
////
////};
bool isValid(string s)
{
	if (s.empty() || s.size() > 2)return false;
	int res = atoi(s.c_str());
	return res <= 26 && res >= 0;
}
void restore(string s, string out, vector<string> &res) {
	if (s.empty()) res.push_back(out);
	else {
		for (int i = 1; i <= 2; ++i) {
			if (s.size() >= i && isValid(s.substr(0, i))) {
				if (s[0] == '0')return;
				else
				{
					char c=char((int)'A' + atoi(s.substr(0, i).c_str()) - 1);
					restore(s.substr(i), out+c, res);
				}
			}
		}
	}
}

int main()
{
	string s ={"12122"};
	vector<string> res;
	restore(s, "", res);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i]<<endl;
	}
	system("pause");
}