#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int TC;
	int test_case;
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� cin �� ����Ͽ� ǥ�� �Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	���� ������ PC ���� �׽�Ʈ �� ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �˴ϴ�.
	��, �� �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�. */
	//freopen("input.txt", "r", stdin);

	cin >> TC;
	for (test_case = 1; test_case <= TC; ++test_case) {
		//	�� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
		int N, r, L;
		scanf("%d", &N);
		scanf("%d %d", &r, &L);
		int arr[100001] = { 0 };
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);









		//	�� �κп��� ������ ����Ͻʽÿ�.  
		cout << "Case #" << test_case << endl;

	}

	return 0;	//	�������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}