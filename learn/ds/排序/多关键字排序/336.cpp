#include <bits/stdc++.h>
using namespace std;
int N;
struct Student {
    string name;
    int age;
    double score;
};
Student stu[110];
bool cmp(Student s1, Student s2) {
    double c1 = s1.score - s2.score;
    if (c1 != 0) return c1 > 0;
    if (s1.name.compare(s2.name)) return s1.name < s2.name;
    if (s1.age != s2.age) return s1.age < s2.age;
    return true;
}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) 
        cin >> stu[i].name >> stu[i].age >> stu[i].score;
    sort(stu, stu+N, cmp);
    for (int i = 0; i < N; i++)
        cout << stu[i].name << " " << stu[i].age << " " << stu[i].score << endl;
    return 0;
}