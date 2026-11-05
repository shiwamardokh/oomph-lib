#ifndef PLASTICITY_TENSOR_HEADER
#define PLASTICITY_TENSOR_HEADER
#include "generic/matrices.h"


namespace plast{
  using Mat3 = oomph::DenseMatrix<double>; //3x3 second-order tensor
  using Mat9 = oomph::DenseMatrix<double>; //9x9 fourth-order tensor 
  using Mat10 = oomph::DenseMatrix<double>; //10x10 tensor
  using Vec3 = oomph::Vector<double>; //vector of length 3
  using Vec9 = oomph::Vector<double>; //vector of length 9
  using Vec10 = oomph::Vector<double>; //vector of length 10
  

  inline int idx(const int a, const int b){return 3 * a + b;} 

  //input validation
  void check_mat3(const Mat3& A); 
  void check_vec3(const Vec3& v);
  void check_vec9(const Vec9& v);
  void check_mat9(const Mat9& T);

  //tensor/vector conversions
  Vec9 to_vec9(const Mat3& A);
  Mat3 from_vec9(const Vec9& v);

  Mat3 apply(const Mat9& T, const Mat3& A); //T[9x9]:A[3x3] -> [3x3]
  Mat3 sym(const Mat3& A); //symmetrize a second-order tensor
  Mat3 dev(const Mat3& A); //deviatoric part of a second-order tensor
  double contract(const Mat3& A, const Mat3& B); //contract two second-order tensors
  double frobenius_norm(const oomph::DenseMatrix<double>& A); //frobenius norm of a cubic matrix
  double norm(const oomph::Vector<double>& v); //norm of a vector

  Mat9 identity_sym(); //symmetric fourth-order identity tensor
  Mat9 identity_dyad(); //dyadic product of the identity tensor
  Mat9 identity_dev(); //deviatoric part of the fourth-order identity tensor


  //spectral machinery
  void spectral(const Mat3& X, Vec3& lam, Mat3& V); //eigenvalues and eigenvectors of X
  Mat3 assemble(const Vec3& f, const Mat3& V); //assemble a tensor from eigenvalues and eigenvectors
  Mat3 divided_differences_log(const Vec3& lam, double rel_tol); //divided differences of the logarithm
  Mat9 isotropic_derivative(const Mat3& theta, const Mat3& V); //isotropic fourth-order derivative
}
#endif