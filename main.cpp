#include <bits/stdc++.h>
using namespace std;

class Calculator {
	int l, h;
	int count_all, except_opt;
	bool print_opt;
	vector<vector<vector<int>>> except_case;
	void print(vector<vector<int>> board) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < l; j++) {
				cout << board[i][j] << " ";
			}
			cout << '\n';
		}
		cout << '\n';
	}
	void make_case(vector<vector<int>> board, int si, int sj, int cnt) {
		if (cnt == h * l / 2) {
			count_all++;
			bool cut=false;
			for (int i = 1; i < h; i++) {
				cut = true;
				for (int j = 0; j < l; j++) {
					if (board[i][j] == 1) {
						cut = false;
						break;
					}
				}
				if (cut) {
					goto confirm_cut;
				}
			}
			for (int j = 1; j < l; j++) {
				cut = true;
				for (int i = 0; i < h; i++) {
					if (board[i][j] == 2) {
						cut = false;
						break;
					}
				}
				if (cut) {
					goto confirm_cut;
				}
			}
			confirm_cut:
			if (print_opt) {
				print(board);
			}
			if (cut) {
			}
			else {
				except_case.push_back(board);
			}
			return;
		}
		int i, j;
		for (i = si; i < h; i++) {
			if (i == si) {
				j = sj;
			}
			else j = 0;
			for (; j < l; j++) {
				if (board[i][j] == 0) {
					bool south_impossible = i == h - 1 || board[i + 1][j];
					bool western_impossible = j == l - 1 || board[i][j + 1];
					board[i][j] = -1;
					if (south_impossible && western_impossible) {
						
					}
					else if (south_impossible) {
						board[i][j + 1] = 2;
						make_case(board, i, j, cnt + 1);
					}
					else if (western_impossible) {
						board[i + 1][j] = 1;
						make_case(board, i, j, cnt + 1);
					}
					else {
						board[i + 1][j] = 1;
						make_case(board, i, j, cnt + 1);
						board[i + 1][j] = 0;
						board[i][j + 1] = 2;
						make_case(board, i, j, cnt + 1);
					}
					return;
				}
			}
		}

	}
public:
	Calculator(int l, int h, bool print_opt=false, int except_opt=0) : l(l), h(h), print_opt(print_opt), except_opt(except_opt), count_all(0) {

	}
	void do_it() {
		vector<vector<int>> board(h, vector<int>(l, 0));
		make_case(board,0,0,0);
	}
	void result() {
		cout << "--- result of calculating about " << l << "*" << h << " tile ---"<<'\n';
		cout << "case count: " << count_all << '\n';;
		cout << "exception case: " << except_case.size() << '\n';
		int amt=0;
		if (except_opt > 0) {
			amt = min(except_opt, (int)except_case.size());
		}
		else if (except_opt <0) {
			amt = (int)except_case.size();
		}
		for (int i = 0; i < amt; i++) {
			print(except_case[i]);
		}
	}
};
void test_for(int l, int h, bool p, int e) {
	cout << "\33[2K"; //line clear
	cout << "\x1b[A"; //up line (ESC [ A) must be support VT100 escape seq
	
	Calculator c(l, h, p, e);
	c.do_it();
	c.result();
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	bool dont_ask = false, print_tile = false;
	int print_except=0;
	cout << "안녕하세요. 이 프로그램은 직사각형 타일의 가로, 세로 길이를 입력 받아 해당 타일 내부에 2칸짜리 도미노를 채워 넣어 항상 타일을 가르는 선이 생기는 지 판별합니다. 타일의 가로 세로 길이 대신 0을 입력하면 도움말을 볼 수 있습니다.\n";
	while (1) {
		cout << "타일의 가로, 세로 길이를 입력하세요: ";
		int x, y; cin >> x;
		if (x <= 0) {
			cout << "\n";
			if (x == 0) {
				cout << "도움말\n";
				cout << "타일의 정보 대신 한 개의 숫자를 입력하여 몇 가지 명령을 실행할 수 있습니다. 아래에 그 리스트가 나와 있습니다:\n";
				cout << "예외 출력: 프로그램이 방문한 예외 케이스의 타일을 출력합니다. -4를 입력하여 설정합니다. 현재 상태: " << ((print_except == 0) ? "출력하지 않음":((print_except>0?((string)to_string(print_except)+"개와 예외 케이스 개수 중 더 적은 개수만큼 출력"):"모든 예외 케이스 출력")));
				cout << "모든 타일 출력: 프로그램이 방문한 모든 타일을 출력합니다. 매우 많은 출력이 발생할 수 있습니다. -3을 입력하여 토글합니다. 현재 상태: " << ((print_tile) ? "활성화됨" : "비활성화됨") << "\n";
				cout << "계산 경고 무시: 계산 시간이 매우 길게 예측될 경우 이를 경고하지 않습니다. -2를 입력하여 토글합니다. 현재 상태: " << ((dont_ask) ? "활성화됨" : "비활성화됨")<<'\n';
				cout << "-1: 프로그램 종료";
				cout << "0: 도움말 보기";
			}
			else if (x == -1) {
				cout << "프로그램을 종료합니다. ";
				break;
			}
			else if (x == -2) {
				if (dont_ask) {
					cout << "\'계산 경고 무시\'를 비활성화합니다.";
				}
				else {
					cout << "\'계산 경고 무시\'를 활성화합니다. ";
				}
				dont_ask = !dont_ask;
			}
			else if (x == -3) {
				if (print_tile) {
					cout << "\'모든 타일 출력\'을 활성화합니다.";
				}
				else {
					cout << "\'모든 타일 출력\'을 비활성화합니다.";
				}
				print_tile = !print_tile;
			}
			else if (x == -4) {
				cout << "예외 출력을 설정합니다.";
				cout << "양의 정수를 입력할 경우 그 값과 예외 케이스 개수 중 더 작은 것 만큼 출력하고,\n";
				cout << "0을 입력할 경우 출력하지 않고,\n";
				cout << "음의 정수를 입력할 경우 모든 예외 케이스를 출력합니다.\n";
				cout << "정수를 입력해 주세요: ";
				cin >> print_except;
			}
		}
		else {
			cin >> y;
			if (x * y % 2) {
				cout << "타일에 도미노를 모두 배치할 수 없습니다. 다시 입력하세요.";
				continue;
			}
			else if (x * y > 64 && !dont_ask) {
				ask:
				cout << "계산이 매우 오래 걸릴 수 있습니다. 정말 이대로 실행하시겠습니까?(y/n)";
				char c; cin >> c;
				if (c == 'y') {
					goto test;
				}
				else if (c == 'n') {
					cout << "다시 입력하세요.";
					continue;
				}
				else {
					cout << "대답을 인식할 수 없습니다. 맞으면 y, 틀리면 n으로 다시 입력해 주세요.";
					goto ask;
				}
			}
			test:
			test_for(x, y, print_tile, print_except);
		}
	}
}
