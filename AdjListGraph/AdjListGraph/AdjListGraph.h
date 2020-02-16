#pragma once
//AdjMatGraph : 인접 행렬을 이용한 그래프 클래스
#include <cstdio>
#define MAX_VTXS 256 //표현 가능한 최대 vertex
#include "Node.h"
class AdjListGraph {
protected:
	int size;//정점의 개수
	char vertices[MAX_VTXS];//정점 정부
	Node* adj[MAX_VTXS]; //인접리스트
public:
	AdjListGraph() :size(0) {  }
	~AdjListGraph() { reset(); }
	//그래프의 초기화
	void reset() {
		for (int i = 0; i < size; i++)
			if (adj[i] != NULL) delete adj[i];
		size = 0;
	}
	bool isEmpty() { return (size == 0); }
	bool isFull() { return (size >= MAX_VTXS); }
	char getVertex(int i) { return vertices[i]; }
	//vertext 삽입 연산
	void insertVertex(char val) {
		if (!isFull()) {
			vertices[size] = val;
			adj[size++] = NULL;
		}
		else printf("Error");
	}

	//edge 삽입 연산: 무방향 그래프의 경우임.(방향, 가중치 그래프에서는 수정)
	void insertEdge(int u, int v) {
		adj[u] = new Node(v, adj[u]);//인접 리스트에 추가
		adj[v] = new Node(u, adj[v]);//방향 그래프면 주석
	}

	//그래프 정보를 출력함 
	void display() {
		printf("%d\n", size); 
		for (int i = 0; i < size; i++) {
			printf("%c   ", getVertex(i)); //정접의 이름 출력
			for (Node* v = adj[i]; v != NULL; v = v->getLink())
				printf("   %c", getVertex(v->getId()));
			printf("\n");
		}
	}
	Node* adjacent(int v) { return adj[v]; }
/*
	//파일 입력 함수
	void load(const char* filename) {
		FILE* fp = fopen(filename, "r");
		if (fp != NULL) {
			int n;
			fscanf_s(fp, "%d", &n); //정접의 전체 개수
			for (int i = 0; i < n; i++) {
				char str[80];
				fscanf(fp, "%s", str); //정접의 이름
				insertVertex(str[0]);
				for (int j = 0; j < n; j++) {
					int val;
					fscanf_s(fp, "%d", &val); //간선의 정보
					if (val != 0)//간선이 있으면
						insertEdge(i, j);//간선 삽입
				}
			}
			fclose(fp);
		}
	}
	//파일 저장 함수
	void store(char* filename) {
		FILE* fp = fopen(filename, "w");
		if (fp != NULL) {
			display();
			fclose(fp);
		}
	}
	*/
};