
inherit ROOM;

void create()
{
        set("short", "��ɽ");
        set("long", @LONG
    ����һ����ʯ����ļ�ɽ��������ˮ���ȣ�С��ͨ�ģ�
�Եø������¡�
LONG
        );
        set("exits", ([
		"north" : __DIR__"huafang",
		 "west" : __DIR__"houhuayuan",
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
