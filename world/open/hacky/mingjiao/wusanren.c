
inherit ROOM;

void create()
{
        set("short", "��ɢ�˴�");
        set("long", @LONG
    ��������ɢ�˴���
LONG
        );
        set("exits", ([
		"east" : __DIR__"guangchang",
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
