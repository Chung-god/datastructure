#pragma once
//Node.h : ���� ����Ʈ�� �̿��� �׷����� ���� ��� Ŭ����
#include <cstdio>
class Node {
protected:
	int id; // vertex �� id
	Node* link; //���� ����� ������
public:
	Node(int i,Node *l =NULL) : id(i),link(l){}
	~Node() {
		if (link != NULL) delete link;
	}
	int getId() { return id; }
	Node* getLink() { return link; }
	void setLink(Node* l) { link = l; }
};