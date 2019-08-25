////做法很不简洁
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
//		for (int num : nums) ++colors[num];//一个点是这里的不简洁
//		for (int i = 0, cur = 0; i < 3; ++i) {//还有一个点是这里分开考虑
//			for (int j = 0; j < colors[i]; ++j) {
//				nums[cur++] = i;
//			}
//		}
//	}
//};
////总结学习以上所说的两个点
////1.将单个统计编程将值存放在数组里边，利用c++11新特性来统计每个数字出现的顺序
//for(int num:nums)++colors[num];//特定的针对012进行计数并放到colors数组里边
////2.另一个不简洁点在于输出次数，与其分开处理，不如利用两个循环，
////如果数组里边元素多的时候，显然分开处理并不适用、
////注意题目要求覆盖原数组
////i是当前值
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
////滑动窗口：注意几个点
////1.先统计t中个字符出现次数
////2.遍历s，当遍历到的当前值是t中字符是即map[s[i]]-- >= 0, cnt + 1;
////3.如果cnt == t.size();说明当前已经找到一个字串包含所有t中字符，此时缩小左边界
////左边界上的值如果也在t中，那么cnt-1；注意之前已经自减过，所以此时的值要加一后再跟0比较
////之后对left++缩小左边界
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
//			if (A[pre]==A[cur]&&count==0)//count==0意味着超过两次重复
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