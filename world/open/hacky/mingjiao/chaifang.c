
inherit ROOM;

void create()
{
        set("short", "��");
        set("long", @LONG
   ����һ��ľ�Ƶ�С�ݣ����ڶ�����ľ��͵��ݡ�ǽ�Ƿ���
���Ѹ�ͷ��������
LONG
        );
        set("exits", ([
		"east" : __DIR__"chitang",
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
