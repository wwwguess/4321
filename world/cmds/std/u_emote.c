// emote.c (Mon  09-04-95)

#include <ansi.h>
inherit F_CLEAN_UP;
 
int main(object me, string str)
{
    if (!str) {
        write(CYN"�㿴��������ḻ��\n"NOR);
	message("channel:chat", BLU +"�����ġ�"+(string)me->name()+ "\077\064\106\160\100\064\061\155\107\151\067\141\070\073\041\043\n"+ NOR , users());   
     //   tell_room(environment(me), CYN+(string)me->name()+
//		"����������ḻ��\n" +NOR, me);
        return 1;
    }
    write(CYN"��"+str+"\n"NOR);
 //   tell_room(environment(me), CYN+(wizardp(me)? "":"->")+(string)me->name()+
  //      str+"\n"+NOR, me);
  	 message("channel:chat",  BLU +"�����ġ�"+(string)me->name()+str +"\n"+NOR, users());
	 return 1;
}
 
int help(object me)
{
	write(@HELP
ָ���ʽ: emote <������>

���ָ�����������һ��ϵͳû��Ԥ��Ķ�����, ϵͳ�Ὣ��������
�����ּ��������������ʾ��������ͬһ���ط������￴. Ϊ�˱�����
������, ���������Ĵʾ�ǰ������ -> �Թ�����. (��ʦ���ڴ�
��.)

����: emote ����������
��ῴ��: ������������
�����˻ῴ��: ->��������������

����, ���Ӿ����������.

���ָ��: semote
HELP
	);
        return 1;
}
