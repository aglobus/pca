#include "utils.h"

#define LEARN_RATE 0.1

class Network {
public:
  Network(int n, int m) : m(m), n(n) {
    weight = Eigen::MatrixXd::Zero(n, m);
    weight << get_rand(), get_rand();
  }

  void train(Eigen::MatrixXd &set) {
    for (size_t j = 0; j < m; j++) { // m = 1 in this case
      for (size_t i = 0; i < set.rows(); i++ ) {
        Eigen::RowVector2d x = set.row(i);
        double y = weight.col(0).dot(x);
        Eigen::RowVector2d delta = LEARN_RATE * (y * x.transpose()) - (y*y*weight);
        weight += delta.transpose();
      }
    }
    std::cout << "NN Calculated PCA:" << "\n";
    std::cout << weight << "\n";
  }

  /* Eigen::MatrixXd apply(Eigen::MatrixXd &other) { */
  void print_applied(Eigen::MatrixXd &other) {
    Eigen::MatrixXd result(other.rows(), 1);
    for (size_t i = 0; i < other.rows(); i++) {
      std::cout << other.row(i) * weight << "\n";
    }
    /* return result; */
  }

private:
  int m; //output dim
  int n; //input dim
  Eigen::MatrixXd weight;

  double get_rand() {
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_real_distribution<double> distribution(0, 1);
    return distribution(engine);
  }
};
