
inherit ROOM;

void create()
{
        set("short", "ҩƷ��");
        set("long", @LONG
    ���������̵�ҩƷ�⡣������������ŨŨ��ҩζ������
����һ���Ÿ߿ɼ�����ҩ��ÿ��ҩ�����ϰٸ�С���룬
������������������ĸ��ֲ�ͷҩ�����������̽���������
æµ�ų���ҩƷ����ҩ������
LONG
        );
        set("exits", ([
		"west" : __DIR__"zoulang3",
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
