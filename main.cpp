#include "Eigen/Dense"
#include "network.h"

// using Eigen::MatrixXd;

int main() {
  // Read the data in
  test_t my_data;
  read_data("sound.csv", my_data);

  // Create a network
  Network n(2,1);

  // Create a matrix for our data and populate it
  Eigen::MatrixXd mat(SIZE, 2);
  for (size_t i = 0; i < SIZE; i++) {
    mat(i, 0) = my_data.dim1[i];
    mat(i, 1) = my_data.dim2[i];
  }

  // Mean normalization
  Eigen::MatrixXd centered = mat.rowwise() - mat.colwise().mean();

  // Calculate PCA the traditional way
  Eigen::MatrixXd cov = (centered.adjoint() * centered) / double(mat.rows() - 1);
  Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> eig(cov);
  std::cout << "Statistically calculated PCA transform for 1 dimension:" << "\n";
  std::cout << eig.eigenvectors().rightCols(1) << "\n";


  // Let the NN calculate PCA
  n.train(centered);

  // Apply the eigenvector to the input and print it
  // n.print_applied(centered);
}
