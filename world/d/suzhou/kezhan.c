//ROOM:/d/suzhou/kezhan.c
//by dwolf
//97.11.7

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG "�͵�" NOR);
	set("long", @LONG
	����һ�Ҽ�Ǯ�����Ŀ�ջ������ǳ���¡������οͶ�ѡ��������ţ����
����������������صķ������顣��С����������æ������ת���Ӵ�����ǻ�����Ŀ�
�ˡ��͵�����˴Ӳ�¶�棬��������˭���и��ָ����Ĳ²⡣ǽ�Ϲ���һ������(paizi)
LONG
	);

	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);

	set("item_desc", ([
        "paizi" : "��Ժ�ͷ���ÿҹ����������\n",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));

	set("exits", ([
		"west" : __DIR__"sroad1",
		"east" : __DIR__"kezhan2",
	]));

	setup();
	"/obj/board/kedian_b"->foo();
}

int valid_leave(object me, string dir)
{
         object *inv;
    	 int i;

    	 if ( me->query_temp("riden") && dir == "east")
		return notify_fail("����ط����������ȥ��\n");
         if ( !userp(me) && dir == "east" )
			return 0;      

	if ( !me->query_temp("rent_paid") && dir == "east" )
	return notify_fail("��С��һ�µ�����ǰ������һ���������ţ����ס����\n");

/*	if ( me->query_temp("rent_paid") && dir == "west" )
	return notify_fail("��С���ܵ���ǰ����ס���͹��Ѿ��������ӣ����᲻ס��������أ�
���˻���ΪС���ź����أ�\n");*/

	return ::valid_leave(me, dir);    
}
       
