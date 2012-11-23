#include "FormFactorBigCylinder.h"
#include "StochasticDiracDelta.h"

#include "MathFunctions.h"
#include "Numeric.h"

double wrapFunctionForGSL2(double qR, void* p_unary_function)
{
    std::binder1st<std::const_mem_fun1_t<double, FormFactorBigCylinder, double> > *p_f =
            (std::binder1st<std::const_mem_fun1_t<double, FormFactorBigCylinder, double> > *)p_unary_function;
    return (*p_f)(qR);
}

FormFactorBigCylinder::FormFactorBigCylinder(double height, double radius)
: m_bin_size(1.0)
{
    setName("FormFactorBigCylinder");
    m_height = height;
    m_radius = radius;
    init_parameters();
}

FormFactorBigCylinder::~FormFactorBigCylinder()
{
}

/* ************************************************************************* */
// initialize pool parameters, i.e. register some of class members for later access via parameter pool
/* ************************************************************************* */
void FormFactorBigCylinder::init_parameters()
{
    getParameterPool()->clear();
    getParameterPool()->registerParameter("height", &m_height);
    getParameterPool()->registerParameter("radius", &m_radius);
    getParameterPool()->registerParameter("bin_size", &m_bin_size);
}


FormFactorBigCylinder* FormFactorBigCylinder::clone() const
{
    FormFactorBigCylinder *p_clone = new FormFactorBigCylinder(m_height, m_radius);
    p_clone->setBinSize(m_bin_size);
    return p_clone;
}

complex_t FormFactorBigCylinder::evaluate_for_q(const cvector_t &q) const
{
    double R = m_radius;
    double H = m_height;

    complex_t qzH_half = q.z()*H/2.0;
    complex_t z_part = H*MathFunctions::Sinc(qzH_half)*std::exp(complex_t(0.0, 1.0)*qzH_half);

    double qrR = std::abs(q.magxy())*R;
    double effective_bin_size = m_bin_size*R;
    double qRmin = qrR - effective_bin_size/2.0;
    double qRmax = qrR + effective_bin_size/2.0;

    std::binder1st<std::const_mem_fun1_t<double, FormFactorBigCylinder, double> >
        f_base = std::bind1st(std::mem_fun(&FormFactorBigCylinder::iTilde), this);
    gsl_function f;
    f.function = &wrapFunctionForGSL2;
    f.params = &f_base;
    double average_intensity = MathFunctions::Integrate1D(&f, qRmin, qRmax)/effective_bin_size;

    double J1_qrR_div_qrR = std::sqrt(average_intensity);
    double radial_part = 2.0*M_PI*R*R*J1_qrR_div_qrR;

    return radial_part*z_part;
}

double FormFactorBigCylinder::iTilde(double qR) const
{
    static double a = 1.0/4.0;
    static double b = std::sqrt(M_PI/3.0/std::sqrt(3.0));

    return a/(1.0 + std::pow(std::abs(b*qR),3.0));
}

/* ************************************************************************* */
// print class
/* ************************************************************************* */
void FormFactorBigCylinder::print(std::ostream &ostr) const
{
    ISample::print(ostr);
//    ostr << " (height:"<<m_height << " radius:"<<m_radius << ")";
}
