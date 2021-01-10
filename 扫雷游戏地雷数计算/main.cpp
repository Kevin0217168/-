#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>


using namespace std;

int N, M;
char** arr = NULL;

void readArr(char** arr) {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> arr[y][x];
		}
	}
}

char** creatArr(int y, int x) {
	char** arr = new char*[y];
	for (int i = 0; i < y; i++) {
		arr[i] = new char[x];
	}
	return arr;
}

void freeArr(char** arr, int yLen, int xLen) {
	for (int i = 0; i < yLen; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

void init() {
	freopen("dileinum.in", "r", stdin);
	freopen("dileinum.out", "w", stdout);

	cin >> N >> M;
	arr = creatArr(N, M);
	readArr(arr);
}

void display(char** arr) {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cout << arr[y][x] << " ";
		}
		cout << endl;
	}
}

int main(void) {
	init();

	int flag[3] = { 1, 0, -1 };

	// 遍历整个数组
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			char* target = &(arr[y][x]);
			if (*target == '*') continue;

			int count = 0;
			for (int yi = 0; yi < 3; yi++) {
				for (int xi = 0; xi < 3; xi++) {
					if (yi == 1 && xi == 1) continue;

					int ny = y + flag[yi];
					int nx = x + flag[xi];

					if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
						if (arr[ny][nx] == '*') {
							count++;
						}
					}
				}
			}

			*target = count + '0';
		}
	}

	display(arr);

	// 释放内存
	freeArr(arr, N, M);

	return 0;
}