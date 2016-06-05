/*------------------------------------------------
�ۑ�1b	sinx�̋ߎ�

2014/05/21
4I31	�����J�l
------------------------------------------------*/

#include<stdio.h>
#include<math.h>
#define PI 3.141592653589793		//�~�������`����

/*		�K������߂�֐�(�ċA�œ������悤�ɂ��Ă���)
			����double	�߂�ldouble					*/
double kaijo(double n){
	if (n > 0){
		return n*kaijo(n - 1);//�ċA����
	}
	else{
		return 1;//�֐����甲���o��
	}
}

/*	main�֐�	*/
int main(void)
{
	//sum:�����𑫂��Ă���	x:���͒l	a:(-1)^n	b:1/(2n+1)!	c:x^(2n+1)
	double sum = 0.0, x = 1.0, a = 1.0, b = 1.0, c = 1.0;

	printf("sin x ��p������p���ċ��߂�v���O����\n\n");
	printf("x����͂��Ă�������[degree]�F");		//���͒l�́�[degree]�ɂ���
	scanf_s("%lf", &x);

	x = x * PI /180.0;			//�v�Z����[radian]�ł��邩��ϊ�����(PI�͉~�����Ńw�b�_�[�ɒ�`����)
	printf("���ۂ̒l : %5.10e\n", sin(x));		//���ۂ̌v�Z�l��\������D����Ƒ��Ό덷���Ƃ��Ă���

	for (int n = 0; fabs(sin(x) - sum) >= 0.00000001; n++)//���Ό덷��10^8�ɂȂ�ƃ��[�v���甲����	fabs�͐�Βl�����߂�
	{
		a = pow(-1.0, n);				//(-1)^n
		b = 1.0 / kaijo(2.0 * n + 1.0);	//b:1/(2n+1)!
		c = pow(x, 2.0 * n + 1.0);		//c:x^(2n+1)
		sum = sum + a*b*c;				//��

		printf("��%d���̒l : %5.10e	�ߎ��l : %5.10e\n", n + 1, a*b*c, sum);//���s�r���o��
		printf("���Ό덷 : %5.10e\n\n", fabs(sin(x) - sum));			//�r���̑��Ό덷
	}

	printf("�ߎ��l\n%26.18e\n", sum);	//�ŏI���ʕ\��

	getch();							//�����Ɏ��s���ʂ������Ȃ��悤�ɂ�������

	return 0;
}