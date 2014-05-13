
//Longest Increasing Subsequence
#include <cstdio>

#define MAXN 100005

int a[MAXN];	//下表为i的元素是a[i]
int dp[MAXN];	//记录以a[i]为结尾的LIS的长度，注意，a[i]一定在此LIS中

/***********************
LIS状态转移方程：
i=0时，dp[i]=1;

i>0时，for j from 0 to i-1
dp[i]=max{1+dp[j](if a[j]<a[i]), 1(if a[j]>=a[i])}。
***********************/

void BuildSeqAndInitDP(int n)
{
	for (int i=0; i<n; ++i)
	{
		scanf("%d", &a[i]);
		dp[i]=1;	//初始化为1，即最长上升子序列是自己
	}
}

int LIS(int n)
{
	int max_overall=1;
	int max_here;

	for (int i=1; i<n; ++i)
	{
		max_here=dp[i];	//由于dp[]已经初始化，此处max_here事实上总是1
		for (int j=0; j<i; ++j)
		{
			if (a[j]<a[i] && 1+dp[j]>max_here)
			{
				max_here=1+dp[j];
			}
		}
		dp[i]=max_here;	//更新以a[i]为结尾的lis长度

		if (max_here>max_overall)
		{
			max_overall=max_here;	//更新全局lis长度
		}
	}

	return max_overall;
}

int main()
{
	int n;
	while (scanf("%d", &n)!=EOF)
	{
		BuildSeqAndInitDP(n);
		printf("%d\n", LIS(n));
	}
	return 0;
}
