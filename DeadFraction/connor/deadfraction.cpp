#include <iostream>
#include <string>
#include <cmath>


struct fraction
{
  long n,d;
};

long gcd(long n, long d) { return (n%d==0) ? d : gcd(d,n%d);}

int main()
{
  std::string digits;
  std::cin >> digits;
  while (digits.length()!=1)
  {
    digits = digits.substr(2,digits.length()-5);
    int c = 1; 
    std::string m;
    fraction best;
     best.n=0;
     best.d = 999999999;
    for (int j=digits.length()-1; j>=0; --j,++c) // digits[j] = n_j, c = m.length();
    {
      m = digits.substr(j,digits.length()); // repeating part
      fraction current; current.d = pow(10,j)*(pow(10,c)-1); // taken care of 
      current.n =0;
      for (int i=j;i>0;i--)
      {
        current.n += (digits[i-1]-'0')*pow(10,j-i); // hard numerator part

      }
      current.n = ((current.n)*(pow(10,c)-1) + atol(m.c_str()));
      long gcf = gcd(current.n,current.d);
      current.d = current.d/gcf;
      current.n = current.n/gcf;
      if (current.d<best.d)
      {
        best = current;
      }
    }
    std::cout << best.n << "/" << best.d << std::endl;
    std::cin >> digits;
  }
}
