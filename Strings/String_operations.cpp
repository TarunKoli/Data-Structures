#include<iostream>
using namespace std;

int countLength(char *s)
{
	int count=0;
	for(int i=0; s[i]!='\0'; i++)
		count++;
		
	return count;	
}

char* toUpperCase(char *s){
	for(int i=0; s[i]!=0; i++)
	{
			if(s[i]>=97 && s[i]<=122)
				s[i]-=32;
	}
	return s;
}

char* toLowerCase(char *s){
	for(int i=0; s[i]!=0; i++){
			if(s[i]>=65 && s[i]<=90)
				s[i]+=32;
	}
	return s;
}

char* toggle(char *s){
	for(int i=0; s[i]!=0; i++)
	{
			if(s[i]>=97 && s[i]<=122)
				s[i]-=32;
			else if(s[i]>=65 && s[i]<=90)
				s[i]+=32;
	}
	return s;	
}

void count_vowel_consonants(char *s){

	int vowel_count=0;
	int consonant_count=0;
	
	for(int i=0; s[i]!=0; i++)
	{
			if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'
				|| s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'
			)
			{
					vowel_count++;
			}else{
					consonant_count++;
			}
	}
	
	cout<<"Vowel Count : "<<vowel_count<<endl;
	cout<<"Consonant Count : "<<consonant_count<<endl;
}

bool Validate_String(char *s){
	
	for(int i=0; s[i]!=0; i++){
		if(!(s[i]>=65 && s[i]<=90) && !(s[i]>=97 && s[i]<=122) && !(s[i]>=48 && s[i]<=57)){
				return false;
		}		
	}
	
	return true;
}

char* Reverse_String(char *s){
	int i,j;
	int len=countLength(s);
	
	for(i=0,j=len-1; i<j; i++,j--){
		char temp=s[i];
		s[i]=s[j];
		s[j]=temp;
	}
	
	return s;
}

bool String_Compare(char *s1, char *s2){
	int len1=countLength(s1);
	int len2=countLength(s2);
	char *cs1=toLowerCase(s1);
	char *cs2=toLowerCase(s1);

	if(len1==len2){
		
		for(int i=0; i<len1; i++)
		{
				if(cs1[i]!=cs2[i])
					return false;
		}
		
		return true;
					
	}else{
		return false;
	}

}

bool isPallindrome(char *s){
	int len=countLength(s);
	int i,j;
	
	for(i=0,j=len-1; i<j; i++,j--){
		if(s[i]!=s[j])
			return false;
	}
	
	return true;
}

bool duplicate_1(char *s){

	for(int i=0; s[i]!='\0'; i++)
	{
			for(int j=i+1; s[j]!='\0'; j++)
			{
					if(s[i]==s[j])
						return true;
			}
	}
	
	return false;	
}

void duplicate_2(char *s)
{
		char *cs = toLowerCase(s);
		int H[30]={0};
		
		for(int i=0; s[i]!='\0'; i++)
			H[cs[i]-97]++;
		
		for(int i=0; i<30; i++)
		{
				if(H[i]>1){
					char letter=i+97;
					cout<<"Letter "<<letter<<" count :"<<H[i]<<endl;
				}
		}
}

void duplicate_bitwise(char *s){
	long int H=0,x=0;
	
	for(int i=0; s[i]!='\0'; i++)
	{
			x=1;
			x=x<<(s[i]-97);
			if((x&H)>0){
				cout<<"Duplicate : "<<s[i]<<endl;
			}
			else{
				H=x|H;
			}
	}
	
}

void anagram(char *s1, char *s2){
	int len1=countLength(s1);
	int len2=countLength(s2);
	int H[30]={0};
	int check=0;
	
	if(len1==len2){
		char *cs1=toLowerCase(s1);
		char *cs2=toLowerCase(s2);
		
		
		for(int i=0; i<len1; i++)
				H[cs1[i]-97]++;
		
		for(int i=0; i<len1; i++){
				H[cs2[i]-97]--;
				if(H[cs2[i]-97]<0){
					cout<<"Not an anagram"<<endl;
					check=1;
					break;
				}
		}
		
		if(check==0)
			cout<<"Anagram"<<endl;
		
	}else{
			cout<<"Not an anagram"<<endl;
	}
	
}

void perm(char s[], int k){
	static int flag[10]={0};
	static char res[10];
	
	if(s[k]=='\0')
	{
		res[k]='\0';
		cout<<res<<endl;
		return;
	}
	else{
		for(int i=0; s[i]!='\0'; i++){
			if(flag[i]==0)
			{
				flag[i]=1;
				res[k]=s[i];
				perm(s,k+1);
				flag[i]=0;
			}
		}
	}	
	
}

int main(){
	char a[]="Hello";
	int *res;
	char s[]="abc";
	
//	cout<<"Word Length : "<<countLength(a)<<endl;
//	cout<<"Toggle Case : "<<toggle(a)<<endl;
//	cout<<"To Upper Case : "<<toUpperCase(a)<<endl;
//	cout<<"To Lower Case : "<<toLowerCase(a)<<endl;
//	count_vowel_consonants(a);
//	Validate_String(a)==true ? cout<<"Valid"<<endl : cout<<"Invalid"<<endl;
//	cout<<Reverse_String(a)<<endl;
//	String_Compare("hello","Hello") ? cout<<"Same"<<endl : cout<<"Not Same"<<endl;
//	isPallindrome("madam") ? cout<<"Pallindrome"<<endl : cout<<"Not a pallindrome"<<endl;
//	duplicate_1(a) ? cout<<"Duplicate Found"<<endl : cout<<"No Duplicates"<<endl;
//	duplicate_2(a);
//	duplicate_bitwise(a);
//	anagram("medical","decimal");
		perm(s,0);
	return 0;
}
