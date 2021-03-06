// Room: /d/taishan/.c
// Date: CSWORD 96/03/25
//#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC "月观峰" NOR);
	set("long", @LONG
这里是位于南天门西面的山岭，怪石攒簇，最高的地方一石
卓立，名为君子峰。往北走便是泰山的西天门。往东走就是
比武擂台的场所，大家可以在这里拿上竹刀，竹剑到擂台上
进行比划。
LONG
	);

	set("exits", ([
		"westup" : __DIR__"yuhuang",
		"east"   : __DIR__"biwutai",
		"eastup" : __DIR__"tanhai",
	]));
        set("objects", ([ 
	"/d/snow/obj/bamboo_sword":2,
	"/d/resort/obj/bblade":2,
          "/d/guanwai/obj/junkstaff":2,
]));
	set("outdoors", "taishan");
	setup();
	set("no_kill",1);
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{

        if (dir == "east")
        {
             if (wizardp(me)) return ::valid_leave(me,dir); 
             if (me->query_temp("mark/bwdh") == 1) {
                me->set("mark/bwdh",0);
		tell_object (me,"公平子说,这位英雄请!\n");
		return ::valid_leave(me,dir);
                 }
            if( me->query("mark/bwdh") == 0 )
            {
             tell_object (me, "公平子说，现在没有举行比武大会，请回吧。\n");
             return notify_fail("上擂台的路被公平子挡住了。\n");     
            }
        }

        return ::valid_leave(me, dir);
}                                       
