#ifndef ELASTIC_LAW_HEADER
#define ELASTIC_LAW_HEADER
#include "plasticity_tensor.h"


namespace plast{
  class ElasticLaw{
  public:
    virtual ~ElasticLaw() {}
    virtual Mat3 stress(const Mat3& eps_e) const = 0; //Kirchhoff stress from elastic logarithmic strain
    virtual const Mat9& modulus() const = 0;
    virtual bool is_isotropic() const = 0;
    virtual double shear_modulus() const = 0;
    virtual double bulk_modulus() const = 0;
  };
  
  class HenckyElasticity : public ElasticLaw{
  public:
    HenckyElasticity(double E, double nu);
    Mat3 stress(const Mat3& eps_e) const override;
    const Mat9& modulus() const override;
    bool is_isotropic() const override;
    double shear_modulus() const override;
    double bulk_modulus() const override;

  private:
    double m_mu;
    double m_K;
    Mat9 m_De;
  };
} 
#endif