
inherit ROOM;

void create()
{
        set("short", "����ͤ");
        set("long", @LONG
  ����һ�����µ�Сͤ��ͤ�з���һ��ʯ�������԰��ż���ʯ�ա�
LONG
        );
        set("exits", ([
		"south" : __DIR__"chitang",
		 "east" : __DIR__"yueliangmen",
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
