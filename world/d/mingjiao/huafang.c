
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
    ����һ��ľ�Ƶ�С�ݣ����ڰ����˸������ԵĻ��ܣ��ݽǷ���
һЩ������������
LONG
        );
        set("exits", ([
		"south" : __DIR__"jiashan",
		 "west" : __DIR__"yueliangmen",
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
