#ifndef HARDENING_LAW_HEADER
#define HARDENING_LAW_HEADER
#include "plasticity_tensor.h"


/* Isotropic hardening law: yield stress sigma_y as a function of the
equivalent plastic strain ebar_p, and its slope. */
//Here the user can choose between Linear hardening, Voce hardening, and Swift hardening.
//
// Contract:
// ebar_p is the accumulated equivalent plastic strain and must be finite
// and non-negative (ebar_p >= 0).
// The caller is responsible for enforcing this condition.
// sigma_y() returns the yield stress.
// dsigma_y() returns its derivative with respect to ebar_p.

namespace plast{

  class HardeningLaw{
  public:
    virtual ~HardeningLaw() {}
    virtual double sigma_y(double ebar_p) const = 0; //yield stress sigma_y(ebar_p).
    virtual double dsigma_y(double ebar_p) const = 0;  //slope d sigma_y / d ebar_p (must be >= 0).

    // Check whether ebar_p belongs to the hardening law's domain
    virtual bool is_valid(double ebar_p) const = 0;
  };


  //linear hardening: sigma_y = sigma0 + H*ebar_p
  class LinearHardening : public HardeningLaw{
  public:
    LinearHardening(double sigma0, double H);
    double sigma_y(double ebar_p) const override;
    double dsigma_y(double ebar_p) const override;
    bool is_valid(double ebar_p) const override;

  private:
    double m_sigma0;
    double m_H;
  };

  //Voce hardening: sigma_y = sigma0 + (sigma_inf - sigma0)(1 - exp(-delta*ebar_p)) + H*ebar_p
  class VoceHardening : public HardeningLaw{
  public:
    VoceHardening(double sigma0, double sigma_inf, double delta, double H);
    double sigma_y(double ebar_p) const override;
    double dsigma_y(double ebar_p) const override;
    bool is_valid(double ebar_p) const override;

  private:
    double m_sigma0;
    double m_sigma_inf;
    double m_delta;
    double m_H;
  };

  //Swift hardening: sigma_y = K*(eps0 + ebar_p)^n
  class SwiftHardening : public HardeningLaw{
  public:
    SwiftHardening(double K, double eps0, double n);
    double sigma_y(double ebar_p) const override;
    double dsigma_y(double ebar_p) const override;
    bool is_valid(double ebar_p) const override;

  private:
    double m_K;
    double m_eps0;
    double m_n;
  };
} 
#endif