#include <stdio.h>
#include <unistd.h>

char* EFLAGS[] = { "CF", "1", "PF", "3", "AF", "5", "ZF", "SF", "TF", "IF", "DF", "OF", "IOPL", "IOPL", "NT", "15", "RF", "VM", "AC" };

void toggleac()
{
  __asm__(
      "pushfq\n"   /* Push the eflags on the stack */
      "xorl $0x40000, (%rsp)\n"  /* Set AC flags (1 << 18) */
      "popfq \n"  /* Save to output */
      );
}

int printeflags()
{
  long int eflags;
  __asm__(
      "pushfq\n"   /* Push the eflags on the stack */
      "popq %0\n"  /* Save to output */
      : "=r"(eflags)
      );

  printf("eflag = 0x%lx\n", eflags);
  printf("[");
  
  int i;
  for(i=0; i<19; ++i)
  {
    if (eflags & (1<<i))
    {
      printf("%s ", EFLAGS[i]);
    }
  }
  printf("]\n");
  return eflags;
}

extern void emulate_FileRepConnClient_CloseConnection(int i);

int main()
{
  for (;;) {
    //printeflags();
    //unsetac();

    //printeflags();
    emulate_FileRepConnClient_CloseConnection(0);


    //printeflags();
  /* Set or unset AC by uncommenting/commenting this line */
    toggleac();
    //printeflags();

  /* corrupt the stack */
     // __asm__(
     //   "addq $8, %rsp\n"  /* Add 0x8 to the Stack pointer */
     // );

  /* Any access to the stack will mess things up if setac() was called */
  //printeflags();
    usleep(70);
  }
}
