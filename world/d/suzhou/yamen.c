// Room: /d/suzhou/yamen.c
//by dwolf
//97.11.4 

#include <ansi.h>         
#include <room.h>
inherit ROOM;

void create()
{
	set("short", MAG"���Ŵ���"NOR);
        set("long", @LONG
	���������Ŵ��ţ�������ľ���Ž����ر��š����Ĵ�����"�ྲ"."�ر�"����
�ӷַ���ͷʯʨ�ӵ��Աߡ�ǰ����һ����ģ���Ȼ�ǹ�С����ԩ�õġ�������������
ǰѲ�ߡ�
LONG
	);

	set("exits", ([
		"south" : __DIR__"eroad2",
		"north" : __DIR__"ymzting",
	]));        
	create_door("north", RED"��ľ����"NOR, "south", DOOR_CLOSED);

	set("objects", ([
		__DIR__"npc/yayi" : 4,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && me->query("family/family_name")!="��͢" && objectp(present("ya yi", environment(me))) && dir == "north")
		return notify_fail(YEL"���ۺȵ������������䡭������\n"NOR);
	return ::valid_leave(me, dir);
}
