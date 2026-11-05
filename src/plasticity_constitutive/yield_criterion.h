#ifndef YIELD_CRITERION_HEADER
#define YIELD_CRITERION_HEADER
#include "plasticity_tensor.h"


//Yield criterion describes the shape of the yield surface.
//Only isotropic von Mises plasticity is implemented for now.
namespace plast{
  class YieldCriterion{
  public:
    virtual ~YieldCriterion() {}
    virtual double equivalent_stress(const Mat3& tau) const = 0; // f(tau)
    virtual Mat3 flow_direction(const Mat3& tau) const = 0; // N = df/dtau
    virtual Mat9 flow_direction_derivative(const Mat3& tau) const = 0; // d2f/dtau2
    virtual bool is_von_mises() const; // base: false
    double yield_function(const Mat3& tau, double sigma_y) const; // Phi = f - sigma_y
  };

  class VonMises : public YieldCriterion{
  public:
    double equivalent_stress(const Mat3& tau) const override;
    Mat3 flow_direction(const Mat3& tau) const override;
    Mat9 flow_direction_derivative(const Mat3& tau) const override;
    bool is_von_mises() const override; // true
  };
} 
#endif