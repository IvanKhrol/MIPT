#include <stdio.h>
#include <math.h>
#include <float.h>
#include <TXLib.h>

const int infinitely_roots = -1;

//------------------------------------------------------------------------------------------------------

int IsGreater(double a, double b)
{
    return ((a - b) > DBL_EPSILON)? 1 : 0;
}

//------------------------------------------------------------------------------------------------------

int DblEquals(double a, double b)
{
    return (abs(a - b) < DBL_EPSILON) ? 1 : 0;
}

//------------------------------------------------------------------------------------------------------

int SolveSquerEq(double a, double b, double c, double* x1, double* x2)
{
    assert(x1);
    assert(x2);

    if (DblEquals(a, 0.0))
    {
        if (DblEquals(b, 0.0))
        {
            return (DblEquals(c, 0.0)) ? infinitely_roots : 0;
        }
        else // if (b =! 0)
        {
            *x1 = -c / b;
            return 1;
        }
    }
    else // if (a =! 0)
    {
        double D = b*b - 4*a*c;
        if (DblEquals(D, 0.0))
        {
            *x1 = -b / 2*a;
            return 1;
        }
        else if (IsGreater(D, 0.0))
        {
            double sqrt_D = sqrt(D);
            *x1 = (-b + sqrt_D) / (2*a);
            *x2 = (-b - sqrt_D) / (2*a);
            return 2;
        }
        else return 0; // if (D < 0)
    }
}

//------------------------------------------------------------------------------------------------------

void PrintA(double a)
{
    if (!DblEquals(a, 0.0))
        printf("%+lgx^2", a);
}

//------------------------------------------------------------------------------------------------------


void PrintB(double b)
{
    if (!DblEquals(b, 0.0))
        printf("%+lgx", b);
}

//------------------------------------------------------------------------------------------------------

void PrintC(double c)
{
    printf("%+lg", c);
}

//------------------------------------------------------------------------------------------------------

void DrawEquation(double a, double b, double c)
{
    printf("Your equation: ");
    PrintA(a);
    PrintB(b);
    PrintC(c);
    printf("=0\n");
}

//------------------------------------------------------------------------------------------------------

int main()
{
    printf("Square_Equation 2020\n");
    printf("Enter a, b, c coefficients: ");

    double a = 0, b = 0, c = 0;
    scanf("%lg %lg %lg", &a, &b, &c);

    DrawEquation(a, b, c);

    double x1 = 0, x2 = 0;
    int nRoots = SolveSquerEq(a, b, c, &x1, &x2);

    switch (nRoots)
    {
        case 0:
                printf("No roots\n");
                break;

        case 1:
                printf("x = %lg\n", x1);
                break;

        case 2:
                printf("x1 = %lg, x2 = %lg", x1, x2);
                break;

        case infinitely_roots:
                printf("Any number");
                break;

        default:
                printf("main(): ERROR: nRoots = %d\n", nRoots);
                return 1;
    }
    return 0;
}

