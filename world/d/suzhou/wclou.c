//ROOM: d/suzhou/wclou.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;   

string look_scene();

void create()
{
	set("short", MAG"����¥"NOR);
	set("long", @LONG
	  �����������ų�¥����������Կ���(look)Զ�����龰(scene)���������
ϲ�������������
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"down" : __DIR__"wgate",
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
	return YEL"Զ���ݳ�ݺ�ɣ�����	��֯����һ�������ľ��������ס��߸�һ����"NOR;
}





