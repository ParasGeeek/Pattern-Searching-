# include <limits.h> 
# include <string.h> 
# include <stdio.h> 

# define NO_OF_CHARS 256 
int max (int a, int b) { return (a > b)? a: b; } 
void badCharHeuristic( char *str, int size, 
						int badchar[NO_OF_CHARS]) 
{ 
	int i; 
	for (i = 0; i < NO_OF_CHARS; i++) 
		badchar[i] = -1; 
	for (i = 0; i < size; i++) 
		badchar[(int) str[i]] = i; 
} 
void search( char *txt, char *pat) 
{ 
	int m = strlen(pat); 
	int n = strlen(txt); 
	int badchar[NO_OF_CHARS]; 
	badCharHeuristic(pat, m, badchar); 

	int s = 0;
	while(s <= (n - m)) 
	{ 
		int j = m-1; 
		while(j >= 0 && pat[j] == txt[s+j]) 
			j--; 
		if (j < 0) 
		{ 
			printf("pattern occurs at index:%d\n",s); 
			s += (s+m < n)? m-badchar[txt[s+m]] : 1; 

		} 
		else
			s += max(1, j - badchar[txt[s+j]]); 
	} 
} 
int main() 
{ 
	 int n,m;
	 scanf("%d %d",&n,&m);
	 char txt[n];
	 char pat[m];
	 printf("Enter the text:\n");
	 scanf("%s",txt);
	 printf("Enter the pattern:\n");
	 scanf("%s",pat);
	search(txt, pat); 
	return 0; 
} 
