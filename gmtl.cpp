#include <iostream>
#include <cstring>
#include <gmtl/gmtl.h>
#include <gmtl/Matrix.h>

//#include "math_3d.h"
using namespace std;
using namespace gmtl;

void PrintMatrix(const Matrix44f& matrix )
{
   for (auto i = 0; i < 4; ++i)
   {
      for (auto j= 0; j < 4; ++j)
         cout << matrix[i][j] << " ";
      cout << endl;
   }
}
/*
void PrintMatrix2(const Matrix4f& matrix )
{
   for (auto i = 0; i < 4; ++i)
   {
      for (auto j= 0; j < 4; ++j)
         cout << matrix.m[i][j] << " ";
      cout << endl;
   }
}
*/
template <class T>
void PrintVec(const Vec<T, 4>& v)
{
   for (auto j= 0; j < 4; ++j)
      cout << v[j] << " ";
   cout << endl;
}
#define M_PI       3.14159265358979323846
#define ToRadian(x) (float)(((x) * M_PI / 180.0f))
int main()
{
  /*    Matrix4f m_3d;
      memset(&m_3d.m, 0, sizeof(float[4][4]));
      m_3d.m[0][1] = 2;
      for (auto i = 0; i < 4; ++i)
      {
         m_3d.m[i][i]= 1;
      }
      m_3d.InitRotateTransform(0,45,45);
      PrintMatrix2(m_3d);
      */
      cout << "hello" << endl;
      Matrix44f myMatrix;
      myMatrix[0][1] = 2;
      Vec4f vec = {1,2,4,5};
      Vec3f vec3 = {.4f,0,0};
      vec[1] = 2;
      vec[0] = 1;
      cout << "Matrix: " << endl;
//      cout << "Matrix : " << sizeof(Matrix44f) <<endl;
//      cout << "Matrix : " << sizeof(float[16]) <<endl;
//      cout << "Vector : " << sizeof(Vec4f) <<endl;
      auto mt = makeTrans< Matrix44f > (vec3);
      PrintMatrix(mt);
      cout << "Vector : " << sizeof(float[4]) <<endl;
      AxisAnglef angle(ToRadian(45),0,0,1);
      AxisAnglef angle2(ToRadian(45),0,1,0);
      
      //setScale(myMatrix, .2f);
      setRot(myMatrix, angle);
      setRot(myMatrix, angle2);
      
      PrintMatrix(myMatrix);
      cout << "Vector : " << endl;
      PrintVec(vec);
      cout << "Vector : " << &vec[0] <<endl;
      cout << "Vector : " << &vec <<endl;
      cout << "Vector : " << vec.getData() <<endl;
      cout << "Result : " << endl;
      auto v = myMatrix * vec;
      PrintVec(v);
      normalize(v);
      PrintVec(v);
      cout << "Hello" << endl;
      
   return 0;
}