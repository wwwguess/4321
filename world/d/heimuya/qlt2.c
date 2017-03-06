inherit ROOM;
void create()
{
        set("short", "兵器储藏室");
        set("long", @LONG
这是一间堆满各式兵器、刀械的储藏室，各式武器都依照种类、长
短、依次放在一起，并且擦拭得一尘不染，储藏室的出口在你的南边，
LONG
        );
	set("objects", ([
                __DIR__"obj/m_sword": 6,
        ]) );
	set("exits", ([
		"south" :__DIR__"qlt1",
	]));
	setup();
}
void init()
{
add_action("do_1","1");
add_action("do_2","2");
}
int do_1()
{
object me;
this_player()->move("/d/jingcheng/postoffice");
return 1;
}
