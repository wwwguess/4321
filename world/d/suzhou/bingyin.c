// Room: /d/suzhou/bingyin.c
// by dwolf
//97.11.4 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"��Ӫ����"NOR);
	set("long", @LONG
	����վ�ڱ�Ӫ���ſڣ������һ�ż�ª��Ӫ�������Կ��������Ʒ��Ĺٱ�
���ڲ�������ʱ�ش����ź������ϰ����ǲ������ڴ˹ۿ��ģ�����øϿ��߿���
LONG
	);

	set("exits", ([
		"south" : __DIR__"yinzhang",
		"north" : __DIR__"eroad2",
	]));

	set("objects", ([
		__DIR__"npc/bing" : 4,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && me->query("family/family_name")!="��͢" && objectp(present("guan bing", environment(me))) && dir == "south")
		return notify_fail(RED"�ٱ���ס�����ȥ·��\n"NOR);
	return ::valid_leave(me, dir);
}

