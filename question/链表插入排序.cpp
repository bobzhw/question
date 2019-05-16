

/**�������򣬲���������ָ��ǰ�����������ÿ�ζ���������Ľ��бȽϣ��ҵ��Լ�
�������������е����λ�ã�˼·���Ƕ�����������н��б����Ƚϣ� ����ҵ���һ����
����Ԫ�أ�����뵱ǰλ�á����������û���ҵ��������Ԫ�أ�����뵽������β��*/
// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		if (head == nullptr)
			return nullptr;
		ListNode* tmp = new ListNode(0);
		tmp->next = head;
		head = head->next;
		tmp->next->next = nullptr;
		while (head != nullptr)
		{
			ListNode* ptr = tmp->next;
			ListNode* pre = tmp;
			ListNode* buf = head;
			head = head->next;
			while (ptr != nullptr)
			{
				if (buf->val < ptr->val)
				{
					pre->next = buf;
					buf->next = ptr;
					break;
				}
				pre = ptr;
				ptr = ptr->next;
			}
			if (ptr == nullptr)
			{
				pre->next = buf;
				buf->next = nullptr;
			}


		}
		head = tmp->next;
		if (tmp != nullptr)
		{
			delete(tmp);
			tmp = nullptr;
		}
		return head;

	}
};