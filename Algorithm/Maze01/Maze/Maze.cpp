// Maze.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define NONBLOCKED 0	// 뚫린 길
#define BLOCKED 1		// 벽
#define PATH 2			// 맞는 길
#define VISITED 3		// 방문함

#define WIDTH 8			// 미로의 너비
#define HEIGHT 8		// 미로의 높이


int maze[WIDTH][HEIGHT] = {
	0, 0, 0, 1, 1, 0, 1, 0,
	1, 1, 0, 0, 0, 0, 1, 0,
	0, 1, 0, 1, 1, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 1, 1,
	1, 1, 0, 1, 0, 1, 0, 0,
	0, 0, 0, 1, 1, 1, 1, 0,
	0, 1, 0, 0, 0, 0, 0, 0,
	0, 1, 1, 1, 0, 1, 1, 0
};

int visited[WIDTH][HEIGHT] = { 0, };

const int ENTRY_ROW = 0;
const int ENTRY_COL = 0;

const int GOAL_ROW = 7;
const int GOAL_COL = 7;

void trace() {
	int i, j;
	int tmp_map[WIDTH][HEIGHT] = { 0 };

	for (i = 0; i < HEIGHT; ++i) {
		for (j = 0; j < WIDTH; ++j) {
			if (maze[i][j] == BLOCKED) {
				printf("■");
			}
			else if (maze[i][j] == PATH) {
				printf("☆");
			}
			else {
				printf("□");
			}
		}
		printf("\n");
	}
}

// 도착지에 제대로 도착했다면 --> TRUE (1)
// 아직 도착지가 아닌 칸이라면 --> FALSE (0)
int push(int r, int c) {

	// 이미 방문했던 칸이니?
	if (visited[r][c] == VISITED) {
		return FALSE;
	}

	// 방문했음을 표시
	visited[r][c] = VISITED;

	// 벽이니?
	if (maze[r][c] == BLOCKED) {
		return FALSE;
	}



	int tmp = maze[r][c];  // 현재 칸의 원래 데이터 보관
	maze[r][c] = PATH; // 일단 '경로'임을 표시

	// 도착지에 도착했니?
	if (r == GOAL_ROW && c == GOAL_COL) {
		return TRUE;
	}


	// 왼쪽 칸으로  push() 재실행(재귀호출)
	if (c > 0 && push(r, c - 1)) {
		return TRUE;
	}
	// 윗쪽 칸으로  push() 재실행(재귀호출)
	if (r > 0 && push(r - 1, c)) {
		return TRUE;
	}
	// 오른쪽 칸으로  push() 재실행(재귀호출)
	if (c < WIDTH - 1 && push(r, c + 1)) {
		return TRUE;
	}
	// 아랫쪽 칸으로  push() 재실행(재귀호출)
	if (r < HEIGHT - 1 && push(r + 1, c)) {
		return TRUE;
	}

	maze[r][c] = tmp;

	return FALSE;
}

void main() {
	push(ENTRY_ROW, ENTRY_COL);
	trace();
}
// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
