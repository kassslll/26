#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* first = NULL;

void printList();
void addToHead(int);
int deleteFromHead();
int contains(int);
void clearList();
int sum();
int evenCount();
void oddsX10();
void elementIx100(int);
void elementLeftIx10(int);
void elementRightIx10(int);
void deleteElementI(int);
void recursionList(struct Node*);
void elementRepetition();
void turnElement(); 
void turnElementIansJ(int, int);
void sortedList();


void main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	first = NULL;
	printList();

	addToHead(10);
	printList();

	addToHead(30);
	printList();

	addToHead(60);
	printList();

	addToHead(50);
	printList();

	turnElementIansJ(1, 3);

	printList();
}

void printList() {
	struct Node* ptr = first;
	while (ptr != NULL) {
		printf("(%d)->", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

void addToHead(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->next = first;
	newNode->data = value;
	first = newNode;
}

int deleteFromHead() {
	int value = first->data;
	struct Node* delNode = first;
	first = first->next;
	free(delNode);
	return value;
}

int contains(int value) {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data == value) {
			return 1;
		}
		ptr = ptr->next;
	}
	return 0;
}

void clearList() {
	while (first != NULL) {
		struct Node* delNode = first;
		first = first->next;
		free(delNode);
	}
}

int sum() {
	struct Node* ptr = first;
	int s = 0;
	while (ptr != NULL) {
		s += ptr->data;
		ptr = ptr->next;
	}
	return s;
}

int evenCount() {
	struct Node* ptr = first;
	int count = 0;
	while (ptr != NULL) {
		if ((ptr->data) % 2 == 0) {
			count++;
		}
		ptr = ptr->next;
	}
	return count;
}

void oddsX10() {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data % 2 != 0) {
			ptr->data *= 10;
		}
		ptr = ptr->next;
	}
}

void elementIx100(int i) {
	struct Node* ptr = first;
	int index = 0;
	while (ptr != NULL) {
		if (index == i) {
			ptr->data *= 100;
			return;
		}
		ptr = ptr->next;
		index++;
	}
}

void elementLeftIx10(int i) {
	struct Node* ptr = first;
	int index = 1;
	while (ptr != NULL) {
		if (index < i) {
			ptr->data *= 10;
		}
		if (index == i) {
			ptr->data *= 10;
			return;
		}
		ptr = ptr->next;
		index++;
	}
}

void elementRightIx10(int i) {
	struct Node* ptr = first;
	int index = 1;
	while (ptr != NULL) {
		if (index >= i) {
			ptr->data *= 10;
		}
		ptr = ptr->next;
		index++;
	}
}

void deleteElementI(int i) {
	if (first == NULL) {
		return;
	}
	if (i == 1) {
		deleteFromHead();
		return;
	}
	struct Node* prev_ptr = first;
	struct Node* ptr = first->next;
	int index = 1;

	while (ptr != NULL) {
		if (index == i-1) {
			prev_ptr->next = ptr->next;
			return;
		}
		prev_ptr = ptr;
		ptr = ptr->next;
		index++;
	}
}    

void recursionList(struct Node* ptr) {
	if (ptr == NULL) {
		printf("NULL");
		return;
	}
	recursionList(ptr->next);
	printf("<-(%d)", ptr->data);
}

void elementRepetition() {
	struct Node* ptr = first;
	int lst[10];
	int index = 0;
	int value;
	while (ptr != NULL) {
		lst[index] = ptr->data;
		ptr = ptr->next;
		index++;
	}
	for (int i = 0; i < index+1; i++) {
		value = lst[i];
		for (int j = i + 1; j < index; j++) {
			if (value == lst[j]) {
				printf("Есть повторяющийся элемент\n");
				return;
			}
		}
	}
	printf("Нет повторяющихся елементов\n");


}  // 10

void turnElement() {
	struct Node* f = first->next;
	struct Node* p = f->next;
	f->next = p->next;
	p->next = f;
	first->next = p;
}

void turnElementIansJ(int i, int j) {
	struct Node* present = first;
	int valuei, valuej , index = 1;

	while (present != NULL) {
		if (index == i) {
			valuei = present->data;
		}
		if (index == j) {
			valuej = present->data;
			present->data = valuei;
			break;
		}
		index++;
		present = present->next;
	}

	present = first;
	index = 1;


	while (present != NULL) {
		if (index == i) {
			present->data = valuej;
			break;
		}
		index++;
		present = present->next;
	}
}

void sortedList() {
	struct Node* present = first;
	struct Node* future = present->next;

	int count = 1;
	int value;
	while (count != 0) {
		count = 0;
		present = first;
		future = present->next;

		while (future != NULL) {
			if (present->data > future->data) {
				value = present->data;
				present->data = future->data;
				future->data = value;
				count++;
			}
			present = present->next;
			future = future->next;
		}
	}
}