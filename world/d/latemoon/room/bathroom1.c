#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "��ԡ������");
	set("long", @LONG
����һ������ң��㿴�������ӣ��¼��Ϲ��������·���
Ʒ��ǽ�ϵļ��Ϲ���һЩ˿��������ŵ�����������Χ�����ܡ�
����һ��������������������ȥ����Լ�ɿ���С���أ�һ�ŵ�����
���е���ȥ������ԡ���þ����Щ����Ȼ�˴��ǽ�ֹ���Խ���!
LONG
	);
    set("no_fight", 1);
    set("objects", ([
       __DIR__"npc/shinyu" : 1,
    ]) );

      set("exits", ([ 
        "west" :__DIR__"flower1",
        "east" :__DIR__"bathroom",
      ]));

    create_door("west","С����","east", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        if( (string)me->query("gender") != "Ů��" ) {
        me->apply_condition("rose_poison", 5);
        tell_object(me, HIG "���������������������һЩ��ĩ��\n" NOR );
        }
        return 1;
}
