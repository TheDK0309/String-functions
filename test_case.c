#include <gtest/gtest.h>
#include "string.h"
TEST(stringlength,normal_len){
	EXPECT_EQ(6,my_strlen((char *)"abcxyz"));
	EXPECT_EQ(6,my_strlen((char *)"aBCxyz"));
	EXPECT_EQ(1,my_strlen((char *)"a"));
	EXPECT_EQ(8,my_strlen((char *)"ab  cxyz"));
	EXPECT_EQ(7,my_strlen((char *)"abˆ‰Âyz"));
	EXPECT_EQ(11,my_strlen((char *)"abcABC789  "));
}
TEST(stringlength,special_len){
	EXPECT_EQ(0,my_strlen((char *)""));
	EXPECT_EQ(3,my_strlen((char *)"ag?"));
	EXPECT_EQ(15,my_strlen((char *)"ab  ():;647cxyz"));
	EXPECT_EQ(7,my_strlen((char *)"abˆ‰Âyz"));
	EXPECT_EQ(0,my_strlen((char *)"\0abcABC789  "));
}
TEST(upper,normal){
	char a[100]="abcdfg";
	char b[100]="aBCxyz";
	char c[100]="ab  cXyz";
	char d[100]="abˆ‰ÂACDyz";
	char e[100]="abcABC789  ";
	EXPECT_EQ(6,str2upper(a));
	EXPECT_EQ(4,str2upper(b));
	EXPECT_EQ(5,str2upper(c));
	EXPECT_EQ(4,str2upper(d));
	EXPECT_EQ(3,str2upper(e));
}
TEST(upper,special){
	char a[100]="";
	char b[100]="ag?0";
	char c[100]="ab  ():;647cxyz";
	char d[100]="abˆ‰ÂACDyz";
	char e[100]="\0abcABC789  ";
	EXPECT_EQ(0,str2upper(a));
	EXPECT_EQ(2,str2upper(b));
	EXPECT_EQ(6,str2upper(c));
	EXPECT_EQ(4,str2upper(d));
	EXPECT_EQ(0,str2upper(e));
}
TEST(lower,normal){
	char a[100]="abcdfg";
	char b[100]="aBCxyz";
	char c[100]="ab  cXyz";
	char d[100]="abˆ‰ÂACDyz";
	char e[100]="abcABC789  ";
	EXPECT_EQ(0,str2lower_(a));
	EXPECT_EQ(2,str2lower_(b));
	EXPECT_EQ(1,str2lower_(c));
	EXPECT_EQ(3,str2lower_(d));
	EXPECT_EQ(3,str2lower_(e));
}
TEST(lower,special){
	char a[100]="";
	char b[100]="ag?0";
	char c[100]="ab  ():;647cXYz";
	char d[100]="abˆ‰ÂACDyz";
	char e[100]="\0abcABC789  ";
	EXPECT_EQ(0,str2lower_(a));
	EXPECT_EQ(0,str2lower_(b));
	EXPECT_EQ(2,str2lower_(c));
	EXPECT_EQ(3,str2lower_(d));
	EXPECT_EQ(0,str2lower_(e));
}
TEST(removenumbers,normal){
	unsigned char a[100]="abcdfg1023";
	unsigned char b[100]="aBCxyz123";
	unsigned char c[100]="ab  cXyz890";
	unsigned char d[100]="abcABC78,.9  ";
	EXPECT_EQ(6,str_strip_numbers(a));
	EXPECT_EQ(6,str_strip_numbers(b));
	EXPECT_EQ(8,str_strip_numbers(c));
	EXPECT_EQ(10,str_strip_numbers(d));	
}
TEST(removenumbers,special){
	unsigned char a[100]="";
	unsigned char b[100]="ag?0";
	unsigned char c[100]="ab  ():;647cXYz";
	unsigned char d[100]="abˆ‰ÂACDyz";
	unsigned char e[100]="0abcABC789  ";
	unsigned char f[100]="01234:'‚ Í";
	EXPECT_EQ(0,str_strip_numbers(a));
	EXPECT_EQ(3,str_strip_numbers(b));
	EXPECT_EQ(12,str_strip_numbers(c));
	EXPECT_EQ(10,str_strip_numbers(d));	
	EXPECT_EQ(8,str_strip_numbers(e));	
	EXPECT_EQ(5,str_strip_numbers(f));	
}
TEST(duplicate,normal){
	char a[100]="abcdfg1023";
	char b[100]="aBCxyz123";
	char c[100]="ab  cXyz890";
	char d[100]="abcABC78,.9  ";
	EXPECT_STREQ("abcdfg1023",strdupl(a));
	EXPECT_STREQ("aBCxyz123",strdupl(b));
	EXPECT_STREQ("ab  cXyz890",strdupl(c));
	EXPECT_STREQ("abcABC78,.9  ",strdupl(d));
}
TEST(duplicate,special){
	char a[100]="";
	char b[100]="ag?0";
	char c[100]="ab  ():;647cXYz";
	char d[100]="abˆ‰ÂACDyz";
	char e[100]="0abcABC789  ";
	char f[100]="01234:'‚ Í";
	EXPECT_STREQ("",strdupl(a));
	EXPECT_STREQ("ag?0",strdupl(b));
	EXPECT_STREQ("ab  ():;647cXYz",strdupl(c));
	EXPECT_STREQ("abˆ‰ÂACDyz",strdupl(d));
	EXPECT_STREQ("0abcABC789  ",strdupl(e));
	EXPECT_STREQ("01234:'‚ Í",strdupl(f));
}
TEST(compare,normal){
	EXPECT_EQ(2,mystrcmp((char *)"abcxyz",(char *)"abrcxyz"));
	EXPECT_EQ(6,mystrcmp((char *)"aBCxyz",(char *)"aBCxyzz"));
	EXPECT_EQ(-1,mystrcmp((char *)"a",(char *)"a"));
	EXPECT_EQ(4,mystrcmp((char *)"ab  cxyz",(char *)"ab   cxyz"));
	
}
TEST(compare,special){
	EXPECT_EQ(0,mystrcmp((char *)"",(char *)" "));
	EXPECT_EQ(2,mystrcmp((char *)"ag?0",(char *)"ag'?0"));
	EXPECT_EQ(8,mystrcmp((char *)"ab  ():;647cXYz",(char *)"ab  ():;Í647cXYz"));
	EXPECT_EQ(12,mystrcmp((char *)"0abcABC789  ",(char *)"0abcABC789  :"));
	EXPECT_EQ(1,mystrcmp((char *)"01234:'‚ Í",(char *)"0 1 2&34:'‚ Í"));
}
TEST(copy,normal){
	char a[100];
	char b[100]="abcxyz";
	mystrcpy(b,a);
	EXPECT_STREQ("abcxyz",a);
	char c[100]="aBCxyzz";
	mystrcpy(c,a);
	EXPECT_STREQ("aBCxyzz",a);
	char d[100]="ab  cxyz";
	mystrcpy(d,a);
	EXPECT_STREQ("ab  cxyz",a);
}
TEST(copy,special){
	char a[100];
	char b[100]="";
	mystrcpy(b,a);
	EXPECT_STREQ("",a);
	char c[100]="ag?0";
	mystrcpy(c,a);
	EXPECT_STREQ("ag?0",a);
	char d[100]="ab  ():;647cXYz";
	mystrcpy(d,a);
	EXPECT_STREQ("ab  ():;647cXYz",a);
	char e[100]="....:'''0abcABC789  ";
	mystrcpy(e,a);
	EXPECT_STREQ("....:'''0abcABC789  ",a);
	char f[100]="01234:'‚ Í";
	mystrcpy(f,a);
	EXPECT_STREQ("01234:'‚ Í",a);
	
}