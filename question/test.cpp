int main()
{
	int b;
	int const *a = &b;//const int *d = &b;��ͬ�����ε���ָ������ڴ��ŵĶ�����һ���ģ�������ͨ��a���ı�
	int * const c = &b;//ָ�볣�� ָ��ĵ�ַ���ܱ仯����ַ��ŵ������Ա仯
	int const* const a = &b;//const int* const a;��ͬ��
}