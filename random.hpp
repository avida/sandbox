#include <vector>

#include <boost/random/uniform_int.hpp>
#include <boost/random/additive_combine.hpp>
boost::ecuyer1988 rng;

#define RANDOM_ORG

int local_rand(int max)
{
   return (int)((double)max * (rand() / (RAND_MAX + 1.0)));
}

std::vector<int> random_org;
FILE *random_org_bin_fp;
void init_local_random()
{
   srand(time(NULL));

   // use random.org data
   /*
   FILE* fp = fopen("random_org.txt", "r");
   if (!fp)
   {
      printf("couldn't open random_org.txt\n");
      exit(1);
   }
   char buf[16];
   while(1)
   {
      if (buf != fgets(buf, sizeof(buf), fp)) break;
      random_org.push_back(atol(buf)+1000000000L);
      //printf("%ld\n", atol(buf)+1000000000L);
   }
   fclose(fp); 
   */
   char fname[] = "/home/afriedgintis/src/wos/random_org/bin/2010-04.bin";
   random_org_bin_fp = fopen(fname, "rb");
   if (!random_org_bin_fp)
   {
      char fname2[] = "/tmp/2010-04.bin";
      random_org_bin_fp = fopen(fname2, "rb");
      if (!random_org_bin_fp)
      {
         printf("couldn't open %s or %s\n", fname, fname2);
         exit(1);
      }
   }
   fseek(random_org_bin_fp, 0, SEEK_END);
   long random_org_bin_len = ftell(random_org_bin_fp);
   fseek(random_org_bin_fp, local_rand(random_org_bin_len), SEEK_SET);
}

static int random_usage = 0;
//static int max_max = 0;

int local_random(int max)
{
   ++random_usage;
   //if (max > max_max) max_max = max;

   // only allow 0 to max-1 (should switch to unsigned)
   assert (max >= 0);

   /*
   static unsigned int pos = 0;
   if (pos == random_org.size())
   {
      printf("not enough random.org data\n");
      exit(1);
   }
   int rv = (int)((double)max * (random_org[pos++] / (2000000000L + 1.0)));
   //random_org.erase(random_org.begin());
   */

#ifdef RANDOM_ORG
   // random.org binary data
   assert (max < INT_MAX);
   unsigned long long data;
   int err = fread(&data, sizeof(data), 1, random_org_bin_fp);
   if (err != 1)
   {
      static bool first = true;
      if (first)
      {
         first = false;
         fseek(random_org_bin_fp, 0, SEEK_SET);
         return local_random(max);
      }
      else
      {
         printf("not enough random.org binary data after %d numbers used\n", random_usage);
         exit(1);
      }
   }
   //data >>= 1;
   int rv = (int)((double)max * (data / (double)ULLONG_MAX));//INT_MAX));
#else
   int rv = local_rand(max);
#endif

   //boost::uniform_int<> int_rng (0, max-1);
   //int rv = int_rng(rng);

   return rv;
}

/**
 * Class SharedRandomData
 * Provide a field of random data/strings from which we can
 * *quickly* construct random "objects"
 */
class SharedRandomData
{
   char* buf;
   int maxlen;
public:
   SharedRandomData(int maxsize);
   ~SharedRandomData();

   char* GetRandomBuffer(int len);
protected:
   int randint(int max);
};

/**
 * Set up a single random data buffer; we'll (randomly)
 * select continuous subsegments of this buffer later as
 * the source for BlockWosClient::PutRandom
 */
SharedRandomData::SharedRandomData(int maxsize)
{
   buf = new char[maxlen = maxsize];

   for (int i = 0; i < maxlen; ++i)
      buf[i] = randint(256);
}

/**
 * dtor
 */
SharedRandomData::~SharedRandomData()
{
   delete [] buf;
   buf = 0;
}

/**
 * Return a randomly selected "substring" from
 * our field of random data
 */
char*
SharedRandomData::GetRandomBuffer(int len)
{
   int off = randint(maxlen - len);

   return buf + off;
}

/**
 * Returns an int in the range (0..max]
 * This is somehow better than random() % max
 */
int
SharedRandomData::randint(int max) {
   //int next = (int) (max * ((double) rand() / (RAND_MAX + 1.0)));
   int next = local_random(max);
   return next;
}
