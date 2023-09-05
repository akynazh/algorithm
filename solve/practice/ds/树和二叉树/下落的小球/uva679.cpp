#include <cstdio>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int D, I, k = 1; // 深度 小球个数 结果编号
		scanf("%d%d", &D, &I); 
		for (int i = 1; i < D; i++) { // 最多跳D-1次1
			if (I % 2) { // 奇数个小球
				I = (I + 1) / 2; // 向右走的小球个数
				k = k * 2; // 从该结点出发的第奇数个小球一定朝左走
			} else { // 偶数个小球
				I = I / 2; // 向左走的小球个数
				k = k * 2 + 1; // 从该结点出发的第偶数个小球一定朝右走
			}
		}
		printf("%d\n", k);
	}
	return 0;
}
