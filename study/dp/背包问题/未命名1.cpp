//��������
#include<iostream>
#include<algorithm>

using namespace std;

int w[5]={0,2,3,4,5};//ÿ����Ʒ��Ӧ������ ������0��Ϊ�������j-w[i]==0ʱ����
int v[5]={0,3,4,5,6};//ÿ����Ʒ��Ӧ�ļ�ֵ 
int bagW=8;			 //������������	
int dp[5][9]={{0}};  //dp[i][j]��ǰ��i����Ʒ������������Ϊjʱ������ֵ 
int item[5];		 //���Ž���� 

//�ҳ����Ž�ĺ��� 
void Best(int i, int j) {			
	if (i>=0) {
		if (dp[i][j]==dp[i-1][j]){
			item[i]=0;
			Best(i-1,j);
		}
		else if (j-w[i]>=0&&dp[i][j]==dp[i-1][j-w[i]]+v[i]){ //���ж�������Ϊ����ֹ�ݹ� 
			item[i]=1;
			Best(i-1,j-w[i]);
		}
	}
}
 
int main()
{	
	//���ƶ�̬�滮�� 
	for(int i=1;i<=4;i++){
		for(int j=1;j<=bagW;j++){
			if(j<w[i])
				dp[i][j]=dp[i-1][j];//װ���µ�i����Ʒʱ 
			else
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);//װ���µ�i����Ʒʱ��ȡװ�º��ֵ 
		}													  //�Ͳ�װ��ʱ������ֵ�� ���ߵ����ֵ		
	}	

	//�����̬�滮�� 
	for(int i=0;i<=4;i++){
		for(int j=0;j<=bagW;j++){
			cout<<dp[i][j]<<' ';
		}
		cout<<endl;
	}

	//�ҳ�����dp��Ӧ��i&j 
	int max_i=0,max_j=0,max=dp[0][0];
	for(int i=0;i<=4;i++){
		for(int j=0;j<=bagW;j++){
			if(dp[i][j]>max){
				max_i=i;max_j=j;
			}
		}	
	} 

	//�ҳ����Ž�
	Best(max_i,max_j);

	//������Ž�
	for(int i=1;i<=4;i++)
		cout<<item[i]<<' ';
	cout<<endl;
	 
	return 0;
} 
