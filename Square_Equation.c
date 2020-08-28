#include <stdio.h>
#include <math.h>
#include <float.h>

const int infinitely_roots = -1;

int DblEquals(double a, double b)
{
    return (fabs(a - b) < DBL_Epsilon) ? 1 : 0;
}

int SolveSquerEq(double a, double b, double c, double* x1, double* x2)
{
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
        else if (D > 0)
        {
            double sqrt_D = sqrt(D);
            *x1 = (-b + sqrt_D) / (2*a);
            *x2 = (-b - sqrt_D) / (2*a);
            return 2;
        }
        else return 0; // if (D < 0)
    }
}

void DrawEquation(double a, double b, double c)
{
    if (a > 0)
    {
        if (b > 0)
        {
            if (c >= 0) printf("Your equation: %lgx^2 + %lgx + %lg = 0\n", a, b, c);
            else printf("Your equation: %lgx^2 + %lgx - %lg = 0\n", a, b, -c);
        }
        else if (DblEquals(b, 0.0))
        {
            if (c >= 0) printf("Your equation: %lgx^2 + %lg = 0\n", a, c);
            else printf("Your equation: %lgx^2 - %lg = 0\n", a, -c);
        }
        else  // if (b < 0)
        {
            if (c >= 0) printf("Your equation: %lgx^2 - %lgx + %lg = 0\n", a, -b, c);
            else printf("Your equation: %lgx^2 - %lgx - %lg = 0\n", a, -b, -c);
        }
    }
    else if (DblEquals(a, 0.0))
    {
        if (b > 0)
        {
            if (c >= 0) printf("Your equation: %lgx + %lg = 0\n", b, c);
                else printf("Your equation: %lgx - %lg = 0\n", b, -c);
        }
        else if (DblEquals(b, 0.0))
        {
            if (c >= 0) printf("Your equation: %lg = 0\n", c);
            else printf("Your equation: %lg = 0\n", c);
        }
        else  // if (b < 0)
        {
            if (c >= 0) printf("Your equation: %lgx + %lg = 0\n", b, c);
            else printf("Your equation: %lgx - %lg = 0\n", b, -c);
        }
    }
    else // if (a < 0)
    {
        if (b > 0)
        {
            if (c >= 0) printf("Your equation: %lgx^2 + %lgx + %lg = 0\n", a, b, c);
            else printf("Your equation: %lgx^2 + %lgx - %lg = 0\n", a, b, -c);
        }
        else if (DblEquals(b, 0.0))
        {
            if (c >= 0) printf("Your equation: %lgx^2 + %lg = 0\n", a, c);
            else printf("Your equation: %lgx^2 - %lg = 0\n", a, -c);
        }
        else  // if (b < 0)
        {
            if (c >= 0) printf("Your equation: %lgx^2 - %lgx + %lg = 0\n", a, -b, c);
            else printf("Your equation: %lgx^2 - %lgx - %lg = 0\n", a, -b, -c);
        }
    }
}

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

