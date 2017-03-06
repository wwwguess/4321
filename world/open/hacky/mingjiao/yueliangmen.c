
inherit ROOM;

void create()
{
        set("short", "月亮门");
        set("long", @LONG
  前方是一个精致的小院，青砖院墙上开着一个月亮形的小门。
LONG
        );
        set("exits", ([
		"north" : __DIR__"houyuan",
		"south" : __DIR__"houhuayuan",
		 "east" : __DIR__"huafang",
		 "west" : __DIR__"shangyueting",
	]));
        set("item_desc", ([
	]));

        set("no_clean_up", 0);
        set("valid_startroom", 1);
        setup();
        replace_program(ROOM);

}

void init()
{

}
