
inherit ROOM;

void create()
{
        set("short", "走廊");
        set("long", @LONG
    这里是一条走廊。周围静悄悄的，你走到这里，
不由得也放轻了脚步。
LONG
        );
        set("exits", ([
		"north" : __DIR__"shidian",
	    "southwest" : __DIR__"guangchang",
		 "east" : __DIR__"zoulang8",
	]));
        set("item_desc", ([
	]));
	set("objects", ([
	]));


        set("no_clean_up", 0);
        set("valid_startroom", 1);
        setup();
        replace_program(ROOM);

}

void init()
{

}
