int Factorial(int x){
	if (x <= 1)
		return 1;
	return (Factorial(x - 1) * x);
}
