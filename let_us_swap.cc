/*
1. a+=b-=a=b-a;
2. a/=b=(a=a*b)/b;
3. a^=b^=a^=b; same as a=(b=(a=b^a)^b)^a; (Thanks to Robert Vukovic)
4. b=a+b-(a=b);

5. int temp = a;
	a = b;
	b = temp;
*/
