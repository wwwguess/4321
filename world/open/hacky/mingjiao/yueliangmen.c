
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
  ǰ����һ�����µ�СԺ����שԺǽ�Ͽ���һ�������ε�С�š�
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
