
inherit ROOM;

void create()
{
        set("short", "���߿�");
        set("long", @LONG
	���������̵ķ��߿⣬��������İڷ��Ÿ�ʽ���ߣ�
��Ϊս���ϳ����Ŀ��ס�
LONG
        );
        set("exits", ([
		"north" : __DIR__"zoulang3",
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
