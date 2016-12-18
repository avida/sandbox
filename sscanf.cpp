#include <stdio.h>
#include <string>
using namespace std;

int main()
{
const char *v = "v2.2.1_UPG.305_gdff90ee";
 int  major, minor, maint,patch;
	char l[21] = {0};
 if (5 == sscanf(v, "v%d.%d.%d_%d_%20s", &major, &minor, &maint, &patch, l) ||
       4 == sscanf(v, "v%d.%d.%d_%d", &major, &minor, &maint, &patch) ||
       4 == sscanf(v, "v%d.%d.%d_%20s", &major, &minor, &maint, l) ||
       3 == sscanf(v, "v%d.%d.%d", &major, &minor, &maint))
   {
      printf("Decompose failed");
   }else
{
	printf ("scanf failed");
}

}
