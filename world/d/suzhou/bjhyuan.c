//ROOM:/d/suzhou/bjhyuan.c
//by dwolf
//97.11.4 

#include <ansi.h>
inherit ROOM;

string* objects = ({
        "flower",
        "stone",
});
 
void create()
{
	int i = random(sizeof(objects));

	set("short", MAG"后花园"NOR);
	set("long", @LONG
这是镖局后花园，里面有各种花草，假山，十分惹人喜欢。突然你看见一朵玫瑰，要
是把它给你的情人，那该多好啊。	
LONG
	);
	set("outdoors", "suzhou");

	set("exits", ([
		"south" : __DIR__"bjdting", 
		"northeast" : __DIR__"dzju",
		"east" : __DIR__"chufan",
	]));

        set("objects", ([
	__DIR__"npc/obj/"+objects[i] : 1]));
                                    

	setup();
}

