// Room: /obj/sbaa/ym.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ѩͤ������ţ����и���һ��(borad),���µ��鰸�Ϸ��ű�,
ī,ֽ,��,����ľ����.���Ը�������.���°��Ÿ�ʽ�̾�,���δ����.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	//	"north" : __DIR__"mstreet1",
	//	"west" : __DIR__"inn",
	//	"south" : __DIR__"sroad1",
		"east" :"/d/snow/crossroad",
	]));
	set("objects", ([
//		__DIR__"npc/worker": 4
//		"/d/snow/npc/trav_blade" : 3,
               "/obj/sbaa/rong":1  ,             
"/d/choyin/npc/judge_gu" :5,
               
	  ]) );

	//set("outdoors", "snow");

	setup();
	replace_program(ROOM);
}
