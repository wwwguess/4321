//door.c
//by dwolf

#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"吹雪山庄正门"NOR);
	set("long", @LONG
	  你站立在一座宏伟的院宇之前，正门的两旁放置两只石狮，门上缠着一对
大铁链，门顶之上挂着一块金匾。金匾上龙飞凤舞的写着四个大字“吹雪山庄”，金
匾左下角刚劲草书落款：“庄主苗人凤庚子年二月十五日”。你大感意外，想不到在
雪山上还有这么一座大庄院。
LONG
	);


      set("exits", ([
      "north" : __DIR__"guarden.c", 
	"down" : __DIR__"road2",
]));

        set("objects", ([
		__DIR__"npc/guard":	1,
			]));

         set("outdoors", "mountain");

	setup();
}
int valid_leave(object me,string dir)
{
	if( present("guard", environment(this_player())) )
    {
        if ( dir=="north" && !(int)me->query("marks/吹雪山庄") )
        return notify_fail("门房伸手拦住了你的去路，喝道：闯什么闯！\n");

	    if ( me->query("marks/吹雪山庄") )
		 me->delete("marks/吹雪山庄");
    }
    return ::valid_leave(me,dir);

}
