#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "С����");
	set("long", @LONG
����һ��С���أ��峺�ĳ�ˮ�������������㡣����Χ������滨    
��ݣ�ʱ����֥��֮�ң�����Ϯ�ԣ���ܰ���ǡ��ͷ׵Ļ���Ʈ�ڳ��ϣ�
�ƴ������У���ӵ�����ʦ���ã��е���Ϸ��ˣ���е���Ȼ���衣��Ҳ
�뵽С��������ԡ���(take bath)��
LONG
	);
    set("resource/water", 1);
    set("objects", ([
      __DIR__"npc/fireangel" : 1,
       __DIR__"npc/eton" : 1,
    ]) );

	set("exits", ([ /* sizeof() == 2 */
     "west" :__DIR__"bathroom1",

]));

	setup();
}
void init()
{
          add_action("do_takebath","take");
}
int do_takebath(string arg)
{
       object me;
       me = this_player();

       if( !arg || (arg!= "bath") )
            return notify_fail("������ʲô? \n");
       if( (string)me->query("gender") != "Ů��" ) {
            me->apply_condition("rose_poison", 15);
            tell_object(me, HIG "����ó�ˮ�����������ص�������\n" NOR );
       } else {
       message_vision("$N�ڳ����о�����ԡ����������ڳ��С�\n",this_player() );

       me->receive_damage("gin", 10);
       me->receive_heal("sen", random(5)+5);
       }
       return 1;
}
