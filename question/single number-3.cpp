class Solution {
public:
	int singleNumber(int A[], int n) {
		int ones = 0;
		int twos = 0;
		int three;
		for (int i = 0; i < n; i++)
		{
			int t = A[i];
			twos |= t&ones;//��һ�γ��֣�onesΪ0��twos����Ϊ0���ڶ��γ��֣�onesΪt��twos����Ϊt�������γ��֣�onesΪ0��twos��ȻΪt
			ones ^= t;     //��һ�γ��֣�ones����Ϊt���ڶ��γ��֣�ones����Ϊ0�������γ���onesΪt
			three = ones&twos;//��һ�γ��֣�threeΪ0���ڶ��γ��֣�threeΪ0��ֻ�е�����threeΪt
			ones &= ~three;//ȥ��ones�еĵ����γ��ֵ����
			twos &= ~three; //ȥ��twos�е����γ��ֵ�����
		}
		return ones | twos;
	}
};