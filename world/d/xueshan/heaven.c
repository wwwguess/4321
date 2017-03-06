//by dwolf
//97.11.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"天堂"NOR);
	set("long", @LONG
	  这就是人们常说的天堂，到处雾气缭绕，彩云飘飘。朦胧中可见一位仙子
向你走来。
LONG
	);  
	set("exits", ([
		"down" : "/d/suzhou/shizx.c",
	]));                   
	set("objects", ([
		__DIR__"npc/fairy" : 1,
	]));
	setup();
}               
   
