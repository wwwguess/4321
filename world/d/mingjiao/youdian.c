
inherit ROOM;

void create()
{
        set("short", "�Ҳ޵�");
        set("long", @LONG
    �������Ҳ޵���з���һ�Ŵ��������ϻ��ź��ĳ�����
����ԭ��������ʹ��פ���Է�ңʧ�ٺ�����һֱ���ò��á�
LONG
        );
        set("exits", ([
		"west" : __DIR__"dadian",
	]));
        set("item_desc", ([
	]));
	set("objects", ([
	]));


        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

void init()
{

}
