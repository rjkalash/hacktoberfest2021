//Dynamic Programming
//Burst Balloon - To maximize bursting value
//DP Solution
//Time complexity - O(n^3)
//space complexity - O(n^2)
#include<bits/stdc++.h>
using namespace std;
struct balloon
{
	int maxval,lastindex;
};
int burstmaxval(int burstval[ ],int n)
{
	balloon dp[n][n];
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"("<<dp[i][j].maxval<<","<<dp[i][j].lastindex<<") ";
		}
		cout<<endl;
	}
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			dp[i][i].maxval=1*burstval[i+1]*burstval[i];
			//cout<<"if0 "<<dp[i][i].maxval<<endl;
		}
		else if(i==n-1)
		{
			dp[i][i].maxval=burstval[i-1]*1*burstval[i];
			//cout<<"ifn-1 "<<dp[i][i].maxval<<endl;
		}
		else
		{
			dp[i][i].maxval=burstval[i-1]*burstval[i+1]*burstval[i];
			//cout<<"else "<<dp[i][i].maxval<<endl;
		}
		dp[i][i].lastindex=i;
	}
	for(int l=2;l<=n;l++)
	{
		for(int i=0;i<n-l+1;i++)
		{
			int j=i+l-1;
			dp[i][j].maxval=INT_MIN;
			int max1;
			for(int k=i;k<=j;k++)
			{
				if(k==i)
				max1=0+dp[k+1][j].maxval;
				else if(k==j)
				max1=dp[i][k-1].maxval+0;
				else
				max1=dp[i][k-1].maxval+dp[k+1][j].maxval;
				if(i==0 && j!=n-1)
				max1+=(1*burstval[j+1]*burstval[k]);
				else if(i!=0 && j==n-1)
				max1+=(burstval[i-1]*1*burstval[k]);
				else if(i==0 && j==n-1)
				max1+=(1*1*burstval[k]);
				else if(1!=0 && j!=n-1)
				max1+=(burstval[i-1]*burstval[j+1]*burstval[k]);
				if(max1>dp[i][j].maxval)
				{
					dp[i][j].maxval=max1;
					dp[i][j].lastindex=k;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"("<<dp[i][j].maxval<<","<<dp[i][j].lastindex<<")"<<" ";
		}
		cout<<endl;
	}
	return dp[0][n-1].maxval;
}
int main()
{
	int burstval[ ]={3,1,5,8};
	int n=sizeof(burstval)/sizeof(int);
	cout<<burstmaxval(burstval,n);
	return 0;
}
