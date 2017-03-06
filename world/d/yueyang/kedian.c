// Room: /city/kedian.c
// YZC 1995/12/04 

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", YEL "�͵�" NOR);
	set("long","    ����һ�Ҽ�Ǯ�����Ŀ�ջ������ǳ���¡������οͶ�ѡ��������ţ���\n������������������صķ������顣��С����������æ������ת���Ӵ�����ǻ����\n�Ŀ��ˡ��͵�����˴Ӳ�¶�棬��������˭���и��ָ����Ĳ²⡣" NOR + "\n");

	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);

	set("item_desc", ([
        "paizi" : "¥���ŷ���ÿҹ����������\n",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));

	set("exits", ([
		"west" : __DIR__"beidajie1",
                "up" : __DIR__"kedian2",
	]));

	setup();
//	"/clone/board/kedian_b"->foo();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
	return notify_fail("��С��һ�µ���¥��ǰ������һ���������ţ����ס����\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
	return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ�
���˻���ΪС���ź����أ�\n");

	return ::valid_leave(me, dir);
}
