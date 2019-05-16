int main()
{
	int b;
	int const *a = &b;//const int *d = &b;等同，修饰的是指向的是内存存放的东西是一定的，不可以通过a来改变
	int * const c = &b;//指针常量 指向的地址不能变化，地址存放的数可以变化
	int const* const a = &b;//const int* const a;等同，
}