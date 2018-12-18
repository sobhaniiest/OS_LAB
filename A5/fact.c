long long int fact(long long int n)
{
    long long int i;
    long long int factorial = 1;

    if (n < 0)
        return 0;
    else
    {
        for(i=1; i<=n; ++i)
            factorial *= i; 

        return factorial;
    }
}