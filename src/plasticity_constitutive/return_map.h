#ifndef RETURN_MAP_HEADER
#define RETURN_MAP_HEADER
#include "elastic_law.h"
#include "hardening_law.h"
#include "yield_criterion.h"
#include "generic/matrices.h"


namespace plast{
  struct ReturnMapOptions{
    double tol = 1e-10; //relative tolerance on the residuals
    double yield_tol = 1e-12; //relative tolerance in the admissibility test
    int max_iter = 50;
    bool force_general = false; //use the general Newton even for von Mises
  };

  
  struct ReturnMapResult{
    Mat3 eps_e; //updated elastic (log) strain
    double ebar_p = 0.0; //updated accumulated plastic strain
    Mat3 tau; //updated Kirchhoff stress
    Mat9 D; //consistent tangent d tau / d eps_tr
    double dgamma = 0.0; //plastic multiplier increment
    bool plastic = false; //false: the step was elastic
    bool converged = false;
    int iterations = 0;
  };


  class ReturnMap{
  public:
    ReturnMap(const ElasticLaw* elastic_pt, const YieldCriterion* yield_pt,
        const HardeningLaw* hardening_pt, const ReturnMapOptions& opts);
    ReturnMapResult compute(const Mat3& eps_tr, double ebar_n) const;
  private:
    void radial_return (const Mat3& eps_tr, double ebar_n, ReturnMapResult& r) const;
    void general_newton(const Mat3& eps_tr, double ebar_n, ReturnMapResult& r) const;
    const ElasticLaw* m_elastic_pt;
    const YieldCriterion* m_yield_pt;
    const HardeningLaw* m_hardening_pt;
    ReturnMapOptions m_opts;
  };
} 
#endif