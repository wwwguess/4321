
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
  ����һ�������С�ݣ����ڳ���򵥣����õ���Ϊ���š�
LONG
        );
        set("exits", ([
		"east" : __DIR__"houyuan",
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
