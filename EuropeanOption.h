//
// Created by serge on 6/5/2022.
//

#ifndef QUANTLIB_EUROPEANOPTION_H
#define QUANTLIB_EUROPEANOPTION_H
#include <string>
class EuropeanOption{

private:
    void init();
    void copy(const EuropeanOption& o2);
    double CallPrice() const ;
    double PutPrice() const ;
    double CallDelta() const ;
    double PutDelta() const ;
    double N(double f) const;

public:

    double r;
    double sig;
    double K;
    double T;
    double U;
    double b;

    std::string optType;


public:
    EuropeanOption();
    EuropeanOption(const EuropeanOption& o2 );
    EuropeanOption(const std::string& optionType);


    virtual ~EuropeanOption();

    EuropeanOption& operator=(const EuropeanOption& option2);

    double Price();
    double Delta();

    void toggle();

};


#endif //QUANTLIB_EUROPEANOPTION_H
