
inherit ROOM;

void create()
{
        set("short", "��޵�");
        set("long", @LONG
    ��������޵���з���һ�Ŵ��������ϲ��õ�һ����Ⱦ��
��������ķ��ı������ǻ�����һ��������š������������
��ʹ�����ճ��������ĵط���
LONG
        );
        set("exits", ([
		"east" : __DIR__"dadian",
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
