
inherit ROOM;

void create()
{
        set("short", "ӥ����");
        set("long", @LONG
    ������ӥ���
LONG
        );
        set("exits", ([
		    "south" : __DIR__"zoulang6",
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
