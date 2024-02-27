#include <stdio.h>
void algorithm_KMP(char* massive, char* pod_massive, int* array, int size_m, int size_p_m) {
	printf("Вступительный тест для '%s':\n", massive);
	int i = 0;
	int j = 0;
	while ((i < size_m) || (j < size_p_m)) {
		if (massive[i] == pod_massive[j]) {
			i++;
			j++;
		}
		else {
			if (j == 0)
				i++;
			else {
				j--;
				i -= array[j];
				j = 0;
			}
		}
		if (j == size_p_m)
			printf("'%s' в положении %d\n", pod_massive, i - (size_p_m));
		if (i == size_m) {
			printf("Больше совпадений не найдено\n");
			break;
		}
	}

}
void prefix_find(char* pod_massive, int* array, int size) {
	*array = 0;
	for (int i = 1; i < size; i++) {
		int j = array[i - 1];
		while ((j > 0) && (pod_massive[i] != pod_massive[j]))
			j = array[j - 1];
		if (pod_massive[i] == pod_massive[j])
			j++;
		array[i] = j;
	}
}
int main() {
	char massive[] = "ABCDBCABCABDA";
	char pod_massive[] = "ABD";
	int array[sizeof(pod_massive) - 1];
	prefix_find(pod_massive, array, sizeof(pod_massive) - 1);
	algorithm_KMP(massive, pod_massive, array, sizeof(massive) - 1, sizeof(pod_massive) - 1);
	return 0;
}