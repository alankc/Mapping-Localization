#ifndef NORMALDISTRIBUTION_H
#define NORMALDISTRIBUTION_H

class NormalDistribution {
public:
    NormalDistribution(double mu, double sigma) : mu(mu), sigma(sigma){};
    NormalDistribution() : mu(0.0), sigma(1.0){};
    double Normcdf(double x);
    double Normpdf(double x);
private:
    double mu;
    double sigma;
};

#endif /* NORMALDISTRIBUTION_H */

