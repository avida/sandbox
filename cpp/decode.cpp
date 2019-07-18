#include <iostream>
#include <string>

int decode(std::string str){
   char* p = const_cast<char*>(str.c_str());
   char* q = 0;
   const char* key = 0;
   const char* value = 0;

   // Our strategy includes *destructive* alteration of the passed-in string

   while (*p)
   {
      // skip ws
      while (*p == ' ' || *p == '\t')
         p++;

      if (*p++ != '\"')
         return 1;

      q = strchr(p, '\"');
      // make sure it wasn't backslashed
      while (q && q[-1] == '\\')
         q = strchr(q+1, '\"');

      if (!q)
         return 2;

      *q = 0;
      key = p;

      p = q+1;

      // skip ws
      while (*p == ' ' || *p == '\t')
         p++;
      
      if (*p++ != ':')
         return 3;

      // skip ws
      while (*p == ' ' || *p == '\t')
         p++;
      
      if (*p++ != '\"')
         return 4;

      q = strchr(p, '\"');
      while (q && q[-1] == '\\')
         q = strchr(q+1, '\"');
      if (!q)
         return 5;

      *q = 0;
      value = p;
      
      p = q + 1;
      // skip ws
      while (*p == ' ' || *p == '\t' || *p == ',')
         p++;
      
   }

   return 0;
}
 int main()
 {
	char *str = "\"key0\":\">x1f3 }CjO<n1]@ [>I\\\\3~:Mj`NK,*j^\"";
    int res = decode (str);
	std::cout << "str is: "<< str <<std::endl;
	std::cout << "result is: " << res;
 }
