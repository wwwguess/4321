int main(object me, string arg)

 {
  int i;
  int times;
  string cmd, verb, path;
  
  if(!arg||arg==""||sscanf(arg,"%d %s",times,cmd)!=2)
   return notify_fail("������?\n");
  seteuid(getuid());
  if (times>10)
     return notify_fail("һ�β�������ô��Σ�\n");
  for(i=0;i<times;i++)
   me->force_me(cmd);
   me->start_busy(1);
  return 1;
 }

int help(object me)
{
        write(@HELP
ָ���ʽ : do <����> <cmds> 
    
     ���ָ���һ���������ѭ��ִ�С� 

HELP
    );
    return 1;
}                  
