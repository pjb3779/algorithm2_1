#include <stdio.h>
#include <math.h>

// �� �� ������ �Ÿ��� ����ϴ� �Լ�
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
// �� A�� ���� PQ ������ �ּ� �Ÿ��� ����ϴ� �Լ�
double minDistance(double xA, double yA, double xP, double yP, double xQ, double yQ) {
    double minDist = distance(xA, yA, xP, yP);
    double dist = distance(xA, yA, xQ, yQ);
    // PQ ������ ���̿� ���� ���� ���
    double dx = xQ - xP;
    double dy = yQ - yP;
    // PQ�� ���� �ƴ� ������ ���
    if (dx != 0 || dy != 0) {
        // �� A�� ���� PQ�� ������ ������ �Ķ���� t ���
        double t = ((xA - xP) * dx + (yA - yP) * dy) / (dx * dx + dy * dy);
        // t ���� ���� �ּ� �Ÿ� ���
        if (t > 1) {
            dist = distance(xA, yA, xQ, yQ);
        } else if (t > 0) {
            double x = xP + t * dx;
            double y = yP + t * dy;
            dist = distance(xA, yA, x, y);
        } else {
            dist = distance(xA, yA, xP, yP);
        }
        // �ּ� �Ÿ� ����
        if (dist < minDist) {
            minDist = dist;
        }
    }
    return minDist;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        double xA, yA, xP, yP, xQ, yQ;
        scanf("%lf %lf", &xA, &yA);
        scanf("%lf %lf %lf %lf", &xP, &yP, &xQ, &yQ);
        // �ּ� �Ÿ� ��� �� ���
        double result = minDistance(xA, yA, xP, yP, xQ, yQ);
        printf("%.3lf\n", result);
    }
    return 0;
}

