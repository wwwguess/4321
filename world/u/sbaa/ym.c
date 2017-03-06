// Room: /obj/sbaa/ym.c

inherit ROOM;

void create()
{
	set("short", "衙门");
	set("long", @LONG
这里是雪亭镇的衙门，正中高悬一匾(borad),匾下的书案上放着笔,
墨,纸,砚,惊堂木等物.两旁各置屏风.堂下摆着各式刑具,你从未见过.
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
