// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

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
                __DIR__"obj/m_ji": 6,
        ]) );

	set("exits", ([
		"south" :__DIR__"rjt1",
	]));
	setup();
}

void init()
{
add_action("do_feng","feng");
}

int do_feng()
{
tell_object( this_player(), "welcome my boy.  heihei \n");
this_player()->move( __DIR__ "xxt8" );
return 1;
}

