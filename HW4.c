#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **create_matrix(int row, int col);
void print_matrix(int **matrix, int row, int col);
int free_matrix(int **matrix, int row, int col);
int fill_data(int **matrix, int row, int col);
int addition_matrix(int **matrix_a, int **matrix_b, int row, int col);
int subtraction_matrix(int **matrix_a, int **matrix_b, int row, int col);
int transpose_matrix(int **matrix, int **matrix_t, int row, int col);
int multiply_matrix(int **matrix_a, int **matrix_t, int row, int col);

int main()
{
  char command;
  printf("[----- ������  2018038063 -----]\n");

  int row, col;
  srand(time(NULL)); // rand�Լ��� �������� �ʱ�ȭ

  printf("Input row and col : ");
  scanf("%d %d", &row, &col); // ��� ���� �Է� ����

  int **matrix_a = create_matrix(row, col);   // ��� a�� ����
  int **matrix_b = create_matrix(row, col);   // ��� b�� ����
  int **matrix_a_t = create_matrix(col, row); // ��� a�� ��ġ����� ����

  printf("Matrix Created.\n");

  if (matrix_a == NULL || matrix_b == NULL)
  {
    return -1;
  }

  do
  {
    printf("----------------------------------------------------------------\n");
    printf("                     Matrix Manipulation                        \n");
    printf("----------------------------------------------------------------\n");
    printf(" Initialize Matrix   = z           Print Matrix        = p \n");
    printf(" Add Matrix          = a           Subtract Matrix     = s \n");
    printf(" Transpose matrix_a  = t           Multiply Matrix     = m \n");
    printf(" Quit                = q \n");
    printf("----------------------------------------------------------------\n");

    printf("Command = ");
    scanf(" %c", &command);

    switch (command)
    {
    case 'z':
    case 'Z':
      printf("Matrix Initialized\n"); // ����� ������ ����� �ʱ�ȭ
      fill_data(matrix_a, row, col);
      fill_data(matrix_b, row, col);
      break;
    case 'p':
    case 'P':
      printf("Print matrix\n"); // ��� a, b�� ���
      printf("matrix_a\n");
      print_matrix(matrix_a, row, col);
      printf("matrix_b\n");
      print_matrix(matrix_b, row, col);
      break;
    case 'a':
    case 'A':
      printf("Add two matrices\n"); // �� ���� ����� ���� ���Ѵ�
      addition_matrix(matrix_a, matrix_b, row, col);
      break;
    case 's':
    case 'S':
      printf("Subtract two matrices \n"); // �� ���� ����� ���� ����
      subtraction_matrix(matrix_a, matrix_b, row, col);
      break;
    case 't':
    case 'T':
      printf("Transpose matrix_a \n"); // ��� a�� ��ġ�Ѵ�
      printf("matrix_a\n");
      transpose_matrix(matrix_a, matrix_a_t, col, row);
      print_matrix(matrix_a_t, col, row);
      break;
    case 'm':
    case 'M':
      printf("Multiply matrix_a with transposed matrix_a \n"); // ����� ��ġ�ϰ� ��ġ�� ��İ� ���� ����� ���� ���Ѵ�
      transpose_matrix(matrix_a, matrix_a_t, col, row);
      multiply_matrix(matrix_a, matrix_a_t, row, col);
      break;
    case 'q':
    case 'Q':
      printf("Free all matrices..\n");   // ��� ��ĵ��� ����Ѵ�
      free_matrix(matrix_a_t, col, row); // �Ҵ��ߴ� �޸𸮸� �����h��
      free_matrix(matrix_a, row, col);
      free_matrix(matrix_b, row, col);
      break;
    default:
      printf("\n       >>>>>   Concentration!!   <<<<<     \n");
      break;
    }
  } while (command != 'q' && command != 'Q');
  return 1;
}

int **create_matrix(int row, int col) // 2���� �迭 ����� �����
{
  if (row <= 0 || col <= 0)
  {
    printf("��� ���� ������ �ٽ� Ȯ���ϼ���\n");
    return NULL;
  }
  int **matrix = (int **)malloc(sizeof(int *) * row);
  for (int r = 0; r < row; r++)
  {
    matrix[r] = (int *)malloc(sizeof(int) * col);
  }
  if (matrix == NULL)
  {
    printf("�޸� �Ҵ� ����\n");
    return NULL;
  }
  return matrix;
}

void print_matrix(int **matrix, int row, int col) // ����� ���
{
  if (row <= 0 || col <= 0)
  {
    printf("��� ���� ������ �ٽ� Ȯ���ϼ���\n");
  }
  for (int r = 0; r < row; r++)
  {
    for (int c = 0; c < col; c++)
    {
      printf("%2d ", matrix[r][c]);
    }
    printf("\n");
  }
  printf("\n");
  if (matrix == NULL)
  {
    printf("�޸� �Ҵ� ����\n");
  }
}

int free_matrix(int **matrix, int row, int col) // �����Ҵ��� ��Ŀ� �Ҵ�Ǿ��� �޸𸮸� ����
{
  if (row <= 0 || col <= 0)
  {
    printf("��� ���� ������ �ٽ� Ȯ���ϼ���\n");
    return NULL;
  }
  for (int r = 0; r < row; r++)
  {
    free(matrix[r]);
  }
  free(matrix);
  return 1;
}

int fill_data(int **matrix, int row, int col) // ����� ������ ������ ä��
{
  if (row <= 0 || col <= 0)
  {
    printf("��� ���� ������ �ٽ� Ȯ���ϼ���\n");
    return NULL;
  }
  for (int r = 0; r < row; r++)
  {
    for (int c = 0; c < col; c++)
      matrix[r][c] = rand() % 20;
  }
  if (matrix == NULL)
  {
    printf("�޸� �Ҵ� ����\n");
    return -1;
  }
  return 1;
}

int addition_matrix(int **matrix_a, int **matrix_b, int row, int col) // ��� a, b�� ���� ���Ѵ�
{
  if (row <= 0 || col <= 0)
  {
    printf("��� ���� ������ �ٽ� Ȯ���ϼ���\n");
    return NULL;
  }
  int **matrix_add = create_matrix(row, col);
  for (int r = 0; r < row; r++)
    for (int c = 0; c < col; c++)
      matrix_add[r][c] = matrix_a[r][c] + matrix_b[r][c];
  if (matrix_add == NULL)
  {
    printf("�޸� �Ҵ� ����\n");
    return -1;
  }
  print_matrix(matrix_add, row, col);
  free_matrix(matrix_add, row, col);
  return 1;
}

int subtraction_matrix(int **matrix_a, int **matrix_b, int row, int col) // ��� a, b �� ���� ����
{
  if (row <= 0 || col <= 0)
  {
    printf("��� ���� ������ �ٽ� Ȯ���ϼ���\n");
    return NULL;
  }
  int **matrix_sub = create_matrix(row, col);
  for (int r = 0; r < row; r++)
    for (int c = 0; c < col; c++)
      matrix_sub[r][c] = matrix_a[r][c] - matrix_b[r][c];
  if (matrix_sub == NULL)
  {
    printf("�޸� �Ҵ� ����\n");
    return -1;
  }
  print_matrix(matrix_sub, row, col);
  free_matrix(matrix_sub, row, col);
  return 1;
}

int transpose_matrix(int **matrix, int **matrix_t, int row, int col) //��� a�� ��ġ�Ѵ�
{
  if (row <= 0 || col <= 0)
  {
    printf("��� ���� ������ �ٽ� Ȯ���ϼ���\n");
    return NULL;
  }
  for (int r = 0; r < row; r++)
  {
    for (int c = 0; c < col; c++)
      matrix_t[r][c] = matrix[c][r];
  }
  if (matrix == NULL)
  {
    printf("�޸� �Ҵ� ����\n");
    return -1;
  }
  return 1;
}

int multiply_matrix(int **matrix_a, int **matrix_t, int row, int col) //��� a�� ��� a�� ��ġ�� ����� ���� ���Ѵ�
{
  if (row <= 0 || col <= 0)
  {
    printf("��� ���� ������ �ٽ� Ȯ���ϼ���\n");
    return NULL;
  }
  int **matrix_mul = create_matrix(row, col);
  for (int r = 0; r < row; r++)
  {
    for (int c = 0; c < col; c++)
    {
      int sum = 0;
      for (int n = 0; n < col; n++)
      {
        sum = sum + matrix_a[r][n] * matrix_t[n][c];
      }
      matrix_mul[r][c] = sum;
    }
  }
  if (matrix_mul == NULL)
  {
    printf("�޸� �Ҵ� ����\n");
    return -1;
  }
  print_matrix(matrix_mul, row, row);
  free_matrix(matrix_mul, row, col);
  return 1;
}
