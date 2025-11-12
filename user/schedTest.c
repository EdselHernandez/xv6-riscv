#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int Armstrong(int n){
int sum = 0, temp = n, digits = 0;

while(temp>0){
digits++;
temp /=10;
}

temp = n;
while (temp > 0){
int d = temp % 10;
int pow = 1;
for(int i = 0; i<digits;i++){
pow *=d;
}
sum +=pow; 
temp /=10;
}

return sum == n;
}

int compute(int limit){
int count = 0;
for( int i = 2; i <= limit; i++){
if(Armstrong(i)){
count++;
}

}
return count;
}

int main(){
  int LIMIT = 1000000;
  printf("Debug ON \n");
  debug(1);
  
  int priorities[8] = {0,0,5,5,10,10,15,15};
  for(int i = 0; i< 8; i++){
  int pid = priority_fork(priorities[i]);
  if(pid < 0){
  printf("Fork Failed\n");
  exit(1);
  }
  if(pid == 0){
  int cnt = compute(LIMIT);
  printf("Child PID %d found %d Armstrong Numbers\n",getpid(),cnt);
  exit(0);
  }
  }
  
  while (wait(0) > 0);
  
  debug(0);
  printf("DEBUG OFF\n");
  exit(0);
}

