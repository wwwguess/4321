int main(object me, string arg)

 {
  int i;
  int times;
  string cmd, verb, path;
  
  if(!arg||arg==""||sscanf(arg,"%d %s",times,cmd)!=2)
   return notify_fail("做几次?\n");
  seteuid(getuid());
  if (times>10)
     return notify_fail("一次不能做这么多次！\n");
  for(i=0;i<times;i++)
   me->force_me(cmd);
   me->start_busy(1);
  return 1;
 }

int help(object me)
{
        write(@HELP
指令格式 : do <次数> <cmds> 
    
     这个指令对一类命令进行循环执行。 

HELP
    );
    return 1;
}                  
