
inherit ROOM;

void create()
{
        set("short", "�����촦");
        set("long", @LONG
    �����������촦
LONG
        );
        set("exits", ([
		"west" : __DIR__"guangchang",
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
