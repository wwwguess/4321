
inherit ROOM;

void create()
{
        set("short", "后院");
        set("long", @LONG
  这里是一个别致的小园，园子里暗香浮动，隐隐透出脂粉香气。
LONG
        );
        set("exits", ([
		"east" : __DIR__"dongxiang",
		"west" : __DIR__"xixiang",
	       "south" : __DIR__"yueliangmen",
	       "north" : __DIR__"guifang",
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
