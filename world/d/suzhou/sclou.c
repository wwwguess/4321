//ROOM: d/suzhou/sclou.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;   

string look_scene();

void create()
{
	set("short", MAG"�ϳ�¥"NOR);
	set("long", @LONG
	  �����������ų�¥����������Կ���(look)Զ��������(scene)���������
ϲ�������������
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"down" : __DIR__"sgate",
	]));
	set("objects", ([
		__DIR__"npc/ren" : 2,
]));                              
	set("item_desc", ([
		"scene" : (: look_scene :),
]));
	setup();
}           

string look_scene()
{
	return YEL"Զ���ݳ�ݺ�ɣ�������֯����һ�������ľ��������ס��߸�һ����"NOR;
}





