#include <room.h>

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",HIY "����" NOR);
	set("long", @LONG
����һ�����ҡ������������Ժϵش����Ĵ���ʯ�������ܹ���һ
Щ����������ǽ��д��ټ��� �� �� ���֣� �ذ�����Լ����һ����
�����ͼ�����뻭�����ǣ��˸�����ֱ��ǣ�Ǭ���������㿲�ޡ���
���ࡣǽ�ϻ�������������Ů��Ȼ������������
LONG
	);

    set("exits", ([
        "north" :__DIR__"miroom2",
    ]) );
    set("objects", ([
       __DIR__"obj/hankie" : 1,
     ]) );
	create_door("north","������","south",DOOR_CLOSED);

	setup();
}
void init()
{
         add_action("do_dancing", "dancing");
         add_action("do_get", "get");
}

int do_dancing(string arg)
{
   object me;

   me = this_player();

   if( (string)me->query("gender") == "����" ) {
   if ( (int)me->query("sen") < 100 )
        return notify_fail("�����ڵ���̫���ˣ��޷�רע�����貽��\n");
        me->receive_damage("sen",80);
   }
   if( (string)me->query("gender") == "Ů��" ) {
   if ( (int)me->query("sen") < 50 )
        return notify_fail("�����ڵ���̫���ˣ��޷�רע�����貽��\n");
        me->receive_damage("sen", 50);
   }
     if ( arg!="out" )
     return notify_fail("�����������������������ƺ�����Ҫ�죡\n" );
     if( arg == "out" )
       message_vision("$N����������������..һ��"+HIG"�� �������� ��"+
          NOR"ͻȻ...\n",
                        this_player() );
         this_player()->move(__DIR__"bamboo");

         return 1;
}
int do_get(string arg)
{
     object me;
     
     me = this_player();

	if (arg !="dance-book")
	return 0;
	else me->receive_damage("sen",50);
	return 0;
}
