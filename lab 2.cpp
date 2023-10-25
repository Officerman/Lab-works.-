#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	// ������������� ������������ ��� ����������
	ListNode() : val(0), next(nullptr) {}
	// ��� ������ ������������ ��������� ����������
	ListNode() {
		val = 0;
		next = nullptr;
	}
	// ����������� � ���������� ������
	ListNode(int x) : val(x), next(nullptr) {}
	// ����������� � ���������� ������ � ���������� �� ��������� ������� ������
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class MyLinkedList {
public:
	MyLinkedList() : head(nullptr), size(0) {}
	size_t get_size() { return size; }	// �������� ������ ������
	void add_at_tail(int val);	// �������� ������� � ����� ������
	void add_at_index(size_t index, int val); // �������� ������� �� �������
	void delete_at_index(size_t index);	// ������� ������� �� �������
	void add_at_head(int val);
	void print();
	void reverse();

private:
	ListNode* head;
	size_t size;
};

void MyLinkedList::add_at_tail(int val) {
	// ������� ����� �������� ListNode ��� ����� ������� ������
	ListNode* newNode = new ListNode(val, nullptr);

	if (head == nullptr) {
		head = newNode;
		return;
	}
	// ������� ��������� it �� ���������� ���������� �������� ������
	ListNode* it = head;
	while (it->next != nullptr)
		it = it->next;

	// ������������ ��������� �� ��������� ������� (next) �������� ���������� ��������
	// ����� ������ ���������� ��������
	it->next = newNode;

	++size;
}

void MyLinkedList::delete_at_index(size_t index) {
	if (index >= size + 1) {
		cout << "Index is larger than the size=" << size << "\n";
		return;
	}

	ListNode* prev = head;

	if (index == 0) {
		head = head->next;
		delete prev;
	}

	ListNode* curr = head->next;
	size_t pos = 0;

	while (prev != nullptr && pos < index - 1) {
		prev = prev->next;
		curr = curr->next;
		++pos;
	}
	prev->next = curr->next;
	delete curr;

	--size;
}

void MyLinkedList::add_at_index(size_t index, int val) {
	ListNode* prev = head;
	ListNode* curr = head->next;
	size_t pos = 0;

	while (prev != nullptr && pos < index - 1) {
		prev = prev->next;
		curr = curr->next;
		++pos;
	}
	ListNode* newNode = new ListNode(val, curr);
	prev->next = newNode;

	++size;
}

void MyLinkedList::add_at_head(int val) {
	ListNode* newNode = new ListNode(val, head);
	head = newNode;
	++size;
}

void MyLinkedList::print() {
	ListNode* curr = head;
	while (curr != nullptr) {
		cout << curr->val << " -> ";
		curr = curr->next;
	}
	cout << "NULL" << endl;
}

void MyLinkedList::reverse() {
	ListNode* prev = nullptr;
	ListNode* curr = head;
	ListNode* next = nullptr;

	while (curr != nullptr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	head = prev;
}

int main() {
	int arr[5] = { 1, 2, 3, 4, 5 };
	MyLinkedList* obj = new MyLinkedList();
	for (int val : arr) {
		obj->add_at_tail(val);
	}
	// obj->print_list();
	cout << "Deleting the last element...\n";
	obj->delete_at_index(4);
	// obj->print_list();

	cout << "Add at index 3\n";
	obj->add_at_index((size_t)2, 10);
	// obj->print_list();

	return 0;
}