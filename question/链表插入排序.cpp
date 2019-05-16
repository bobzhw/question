

/**插入排序，插入排序是指从前往后进行排序，每次都与已排序的进行比较，找到自己
在已排序序列中的最佳位置，思路就是对已排序的序列进行遍历比较， 如果找到第一个比
其大的元素，则插入当前位置。若遍历完后没有找到比他大的元素，则插入到序列最尾端*/
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