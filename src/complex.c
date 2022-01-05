#include "../includes/fractol.h"

t_complex      complex_add(t_complex x, t_complex y)
{
    t_complex   result;

    result.a = x.a + y.a;
    result.b = x.b + y.b;

    return (result);
}

t_complex      complex_sub(t_complex x, t_complex y)
{
    t_complex   result;

    result.a = x.a - y.a;
    result.b = x.b - y.b;

    return (result);
}

t_complex      complex_multi(t_complex x, t_complex y)
{
    t_complex   result;

    result.a = (x.a * y.a) - (x.b * y.b);
    result.b = (x.a * y.b) + (x.b * y.a); //2 * x.a * y.a;

    return (result);
}

double         complex_abs(t_complex x)
{
    return (sqrt((x.a * x.a) + (x.b * x.b)));
}
