////�����ܲ����
////class Solution {
////public:
////	void sortColors(vector<int>& nums) {
////		int zero, one, two;
////		//too studpid;
////		for (int i = 0; i < nums.size(); i++)
////		{
////			if (nums[i] == 0)
////			{
////				zero++;
////			}
////			if (nums[i] = 1)
////			{
////				one++;
////			}
////			else
////				two++;
////		}
////	}
////};
//
//
//
//
//class Solution {
//public:
//	void sortColors(vector<int>& nums) {
//		vector<int> colors(3);
//		for (int num : nums) ++colors[num];//һ����������Ĳ����
//		for (int i = 0, cur = 0; i < 3; ++i) {//����һ����������ֿ�����
//			for (int j = 0; j < colors[i]; ++j) {
//				nums[cur++] = i;
//			}
//		}
//	}
//};
////�ܽ�ѧϰ������˵��������
////1.������ͳ�Ʊ�̽�ֵ�����������ߣ�����c++11��������ͳ��ÿ�����ֳ��ֵ�˳��
//for(int num:nums)++colors[num];//�ض������012���м������ŵ�colors�������
////2.��һ�������������������������ֿ�����������������ѭ����
////����������Ԫ�ض��ʱ����Ȼ�ֿ����������á�
////ע����ĿҪ�󸲸�ԭ����
////i�ǵ�ǰֵ
//for(int i=0,cur=0;i<3;i++)
//{
//	for (int j = 0; j < colours.size(), j++)
//		nums[cur++] = i;
//}
//
//class Solution {
//public:
//	string minWindow(string s, string t) {
//		string res = "";
//		unordered_map<char, int> letterCnt;
//		int left = 0, cnt = 0, minLen = INT_MAX;
//		for (char c : t) ++letterCnt[c];
//		for (int i = 0; i < s.size(); ++i) {
//			if (--letterCnt[s[i]] >= 0) ++cnt;
//			while (cnt == t.size()) {
//				if (minLen > i - left + 1) {
//					minLen = i - left + 1;
//					res = s.substr(left, minLen);
//				}
//				if (++letterCnt[s[left]] > 0) --cnt;
//				++left;
//			}
//		}
//		return res;
//	}
//};
//
//
//
////�������ڣ�ע�⼸����
////1.��ͳ��t�и��ַ����ִ���
////2.����s�����������ĵ�ǰֵ��t���ַ��Ǽ�map[s[i]]-- >= 0, cnt + 1;
////3.���cnt == t.size();˵����ǰ�Ѿ��ҵ�һ���ִ���������t���ַ�����ʱ��С��߽�
////��߽��ϵ�ֵ���Ҳ��t�У���ôcnt-1��ע��֮ǰ�Ѿ��Լ��������Դ�ʱ��ֵҪ��һ���ٸ�0�Ƚ�
////֮���left++��С��߽�
//
//
//class Solution {
//public:
//	string minWindow(string s, string t) {
//		int min_length;
//		string res = "";
//		int left = 0, cnt = 0;
//		unordered_map count;
//		for (auto i :t)
//		{
//			count[i]++;
//		}
//		for (int i=0;i<s.size();i++)
//		{
//			if (--count[s[i]] >= 0)
//				cnt++;
//			while (cnt == t.size())
//			{
//				if (min_length> i - left + 1) {
//					min_length = i - left + 1;
//					res = s.substr(left, min_length);
//					if (++count[s[left]] > 0)
//					{
//						cnt--;
//					}
//					left++;
//				}
//			}
//		}
//		return res;
//	}
//};
//class Solution {
//public:
//	vector<vector<int>> combine(int n, int k) {
//		vector<vector<int>> res;
//		vector<int> out;
//		helper(n, k, 1, out, res);
//		return res;
//	}
//	void helper(int n, int k, int level, vector<int>& out, vector<vector<int>>& res) {
//		if (out.size() == k) { res.push_back(out); return; }
//		for (int i = level; i <= n; ++i) {
//			out.push_back(i);
//			helper(n, k, i + 1, out, res);
//			out.pop_back();
//		}
//	}
//};
//class Solution {
//public:
//	int removeDuplicates(int A[], int n) {
//		if (n <= 2) return n;
//		int pre = 0, cur = 1, count = 1;
//		while(cur<n)
//		{
//			if (A[pre]==A[cur]&&count==0)//count==0��ζ�ų��������ظ�
//			{
//				++cur;
//			}
//			else
//			{
//				if (A[pre] == A[cur])
//					--count;
//				else
//					count = 1;
//				A[++pre] = A[cur++];
//			}
//		}
//		return pre + 1;
//	}
//};