#include <iostream>

#include <ct/core/core.h>
#include <ct/core/plot/plot.h>
#include <ct/optcon/optcon.h> 
using namespace std;
using namespace ct::core ;
using namespace ct::core::plot;
int main ()
{

    // a damped oscillator has two states, position and velocity
    const size_t state_dim = SecondOrderSystem::STATE_DIM;  // = 2
    // create a state
    StateVector<state_dim> x;
    StateVectorArray<state_dim> states; //To record states along trajectory
    ct::core::tpl::TimeArray<double> time_stamps; //To record Time Stamps along trajectory
    // we initialize it at a point with unit deflection and zero velocity
    x(0) = 1.0;//Position 
    x(1) = 0.0;//Velocity
    // create an oscillator, which is a predefined system in ct_core
    double w_n = 5;
    shared_ptr<SecondOrderSystem> oscillator(new SecondOrderSystem(w_n));
    // create an integrator
    Integrator<state_dim> integrator(oscillator);
    // simulate 1000 steps
    double dt = 0.001;
    Time t0 = 0.0;
    size_t nSteps = 2000;
    states.push_back(x);
for (size_t i = 0; i < nSteps; i++){
    integrator.integrate_n_steps(x, i*dt, 1, dt);
    // print the new state
    states.push_back(x);
    time_stamps.push_back(i*dt);


}
 // Plot Output:
 std::vector<double> time_plot, position_plot, velocity_plot;

 for (size_t i = 0; i < time_stamps.size(); i++)
    {
        time_plot.push_back(time_stamps[i]);
        position_plot.push_back(states[i](0));
        velocity_plot.push_back(states[i](1));

    }


 // plot position
    ct::core::plot::subplot(3, 1, 1);
ct::core::plot::title("Simulation Results");
    ct::core::plot::labelPlot("Position", time_plot, position_plot);
    ct::core::plot::legend();
    ct::core::plot::ylabel("Position");
     ct::core::plot::xlabel("Time");
    // plot velocity
    ct::core::plot::subplot(3, 1, 2);
    ct::core::plot::labelPlot("Velocity", time_plot, velocity_plot);
    ct::core::plot::legend();
    ct::core::plot::ylabel("Velocity");
     ct::core::plot::xlabel("Time");
        // plot velocity
    ct::core::plot::subplot(3, 1, 3);
    ct::core::plot::labelPlot("Phase Plot",velocity_plot,position_plot);
    ct::core::plot::legend();
    ct::core::plot::ylabel("Velocity");
     ct::core::plot::xlabel("Position");
    
    ct::core::plot::show();

return 0;


}
