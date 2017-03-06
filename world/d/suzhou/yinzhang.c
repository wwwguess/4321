// Room: /d/suzhou/yinzhang.c
//by dwolf
//97.11.4 

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"Ӫ��"NOR);
	set("long", @LONG
	�����Ǳ�Ӫ���������鵽�����ǹٱ����е����佫��ָ�����жӲ�����
�еĶ������������е����š�����������Ϣ����ǽ��������˧��������ɫ��Ѱ��
�����ܡ����������������ȫ�������Χ�˹��������ƿ�����̫��ϱ���һ��
����(bulian)��
LONG
	);

	set("item_desc", ([
		"bulian" : "����һ�鼫��Ĳ����ӣ�����·���ʲô�ڶ���\n",
	]));
	set("exits", ([
		"south" : __DIR__"zhuyin",
		"north" : __DIR__"bingyin", 
	]));

	set("objects", ([
                 __DIR__"npc/ypfeng" : 1,
                "/obj/npc/wujiang1"+random(3) : 1,
                "/obj/npc/wujiang1"+random(3) : 1,
		__DIR__"npc/bing" : 6,
	]));

	create_door("south", "bulian", "north", DOOR_CLOSED);
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("guan bing", environment(me))) && 
		dir == "south")
		return notify_fail(RED"�ٱ���ס�����ȥ·��\n"NOR);
	return ::valid_leave(me, dir);
}

