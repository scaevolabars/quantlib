//
// Created by serge on 6/5/2022.
//

#include "EuropeanOption.h"
#include <math.h>

double EuropeanOption::N(double value) const {
        return 0.5 * erfc(-value * M_SQRT1_2);
}

double EuropeanOption::CallPrice() const {
    double tmp = sig *sqrt(T);
    double d1 = (log(U/K) + (b + (sig*sig)*0.5)*T)/tmp;
    double d2 = d1 - tmp;
    return (U * exp((b - r)*T) * N(d1)) - (K * exp(-r * T) * N(d2));
}

double EuropeanOption::PutPrice() const {
    double tmp = sig *sqrt(T);
    double d1 = (log(U/K) + (b + (sig*sig)*0.5)*T)/tmp;
    double d2 = d1 - tmp;
    return ( (K * exp(-r * T) * N(-d2) - U * exp((b - r)*T) * N(-d1)));
}

double EuropeanOption::CallDelta() const {
    double tmp = sig *sqrt(T);
    double d1 = (log(U/K) + (b + (sig*sig)*0.5)*T)/tmp;
    double d2 = d1 - tmp;
    return exp((b-r)*T) * N(d1);
}

double EuropeanOption::PutDelta() const {
    double tmp = sig *sqrt(T);
    double d1 = (log(U/K) + (b + (sig*sig)*0.5)*T)/tmp;
    double d2 = d1 - tmp;
    return exp((b-r)*T) * N(d1);
}

void EuropeanOption::init() {

    r = 0.08;
    sig = 0.3;
    K = 65.0;
    T = 0.25;
    U = 60.0;
    b = r;
    optType = "C";

}

void EuropeanOption::copy(const EuropeanOption &o2) {

    r = o2.r;
    sig = o2.sig;
    K = o2.K;
    T = o2.T;
    U = o2.U;
    b = o2.b;
    optType = o2.optType;

}

EuropeanOption::EuropeanOption() {
    init();

}

EuropeanOption::EuropeanOption(const EuropeanOption &o2) {
    copy(o2);
}

EuropeanOption::EuropeanOption(const std::string &optionType) {
    init();
    optType= optionType;
    if (optType == "c"){
        optType = "C";
    }
}

EuropeanOption::~EuropeanOption() {

}
EuropeanOption & EuropeanOption::operator=(const EuropeanOption &option2) {

    if (this == &option2) return *this;
    copy(option2);
    return *this;

}

double EuropeanOption::Price() {
    if (optType == "C"){
        return CallPrice();
    } else return PutPrice();
}

double EuropeanOption::Delta() {
    if (optType == "C"){
        return CallDelta();
    } else return PutDelta();
}

void EuropeanOption::toggle() {
    if (optType == "C"){
        optType = "P";
    } else optType = "C";
}