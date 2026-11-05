#ifndef PLASTIC_STATE_HEADER
#define PLASTIC_STATE_HEADER
#include <vector>
#include "plasticity_tensor.h"


/*
The header correctly keeps the state layout hidden from the rest of the solver.
That means the finite element code should not access individual state indices directly.
It should interact with the state only through the six functions.
*/
namespace plast{
  const unsigned N_STATE = 7; //6 symmetric tensor components + 1 scalar

  //finite strain: state = { (C^p)^{-1}, ebar_p }
  void unpack_finite(const std::vector<double>& s, Mat3& Cp_inv, double& ebar_p);
  void pack_finite (const Mat3& Cp_inv, double ebar_p, std::vector<double>& s);
  void initial_state_finite(std::vector<double>& s);
  
  //small strain: state = { eps^p, ebar_p }
  void unpack_small(const std::vector<double>& s, Mat3& eps_p, double& ebar_p);
  void pack_small (const Mat3& eps_p, double ebar_p, std::vector<double>& s);
  void initial_state_small(std::vector<double>& s);
} 
#endif