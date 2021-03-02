#include <stdio.h>

struct info {
	char name[20];
	double score;
	int credit;
};

void input_data(struct info students[], int num) {
	for (int i = 0; i < num; i++) {
		printf("학생%d의 이름, 평점 평균, 취득 학점을 입력하세요 : ", i+1);
		scanf("%s %lf %d", students[i].name, &students[i].score, &students[i].credit);
		if (students[i].score < 0 || students[i].credit < 0) {
			printf("잘못된 정보입니다. 다시 입력하세요\n");
			i--;
		}
	}
}

void scholarship(struct info students[], int num) {
	for (int i = 0; i < num; i++)
		if (students[i].score >= 4.3 && students[i].credit >= 20)
			printf("%s %f %d\n", students[i].name, students[i].score, students[i].credit);
}

int main(void)
{
	struct info students[5];
	input_data(students, 5);
	scholarship(students, 5);
	return 0;
}
