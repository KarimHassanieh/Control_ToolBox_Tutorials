#include <iostream>

#include <ct/core/core.h>
#include <ct/core/plot/plot.h>

using namespace std;
using namespace ct::core ;
int main ()
{

    // a damped oscillator has two states, position and velocity
    const size_t state_dim = SecondOrderSystem::STATE_DIM;  // = 2
    // create a state
    StateVector<state_dim> x;
    // we initialize it at a point with unit deflection and zero velocity
    x(0) = 1.0;
    x(1) = 0.0;
    // create an oscillator, which is a predefined system in ct_core
    double w_n = 10;
    shared_ptr<SecondOrderSystem> oscillator(new SecondOrderSystem(w_n));
    // create an integrator
    Integrator<state_dim> integrator(oscillator);
    // simulate 1000 steps
    double dt = 0.001;
    Time t0 = 0.0;
    size_t nSteps = 1000;
    integrator.integrate_n_steps(x, t0, nSteps, dt);
    // print the new state
    cout << "state after integration: " << x.transpose() << endl;
 // Simple:
    std::vector<double> v({1, 2, 3, 4});
    ct::core::plot::plot(v);
    ct::core::plot::show();

    // Eigen Vector Types:
    Eigen::VectorXd times(100);
    times.setLinSpaced(100, 0, 20);
    Eigen::VectorXd points(100);
    points.setRandom();

    ct::core::plot::plot(times, points);
    ct::core::plot::show();

    ct::core::plot::labelPlot("A Name", times, points);
    ct::core::plot::show();

    // enable interactive mode as of now (only tests if it doesn't crash)
    // ct::core::plot::ion();

    // subplots
    ct::core::plot::subplot(3, 1, 1);
    ct::core::plot::plot(v);
    ct::core::plot::subplot(3, 1, 2);
    ct::core::plot::plot(v);
    ct::core::plot::subplot(3, 1, 3);
    ct::core::plot::plot(v);
    ct::core::plot::show(false);


    // plot multiple curves in a single graph
    std::vector<double> w({4, 3, 2, 1});
    ct::core::plot::plot(v, "x");
    ct::core::plot::plot(w, "o");
    ct::core::plot::show();

    // Histogram
    ct::core::plot::hist(points, 3);
    ct::core::plot::show();

    // Row vectors
    Eigen::MatrixXd matrix(2, 100);
    matrix.setRandom();
    ct::core::plot::plot(matrix.row(0), matrix.row(1));
    ct::core::plot::show();

    // BoxPlot
    Eigen::MatrixXd data(2, 100);
    data.setRandom();
    ct::core::plot::figure();
    std::vector<std::string> labels = {"A", "B"};
    ct::core::plot::boxplot(data, labels);
    ct::core::plot::show();

    // BoxPlot
    data.setRandom();
    ct::core::plot::figure();
    ct::core::plot::boxplot(data, {"A", "B"});
    ct::core::plot::show();

    // Boxplot unlabelled
    data.setRandom();
    ct::core::plot::figure();
    ct::core::plot::boxplot(data);
    ct::core::plot::show();

 
return 0;


}
