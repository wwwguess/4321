
inherit ROOM;

void create()
{
        set("short", "池塘");
        set("long", @LONG
    这是一个幽静的池塘，水面上浮着几张荷叶。一条弯弯的
小桥通向前方的小亭。
LONG
        );
        set("exits", ([
		"north" : __DIR__"shangyueting",
		 "east" : __DIR__"houhuayuan",
		 "west" : __DIR__"chaifang",
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
