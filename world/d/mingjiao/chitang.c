
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
    ����һ���ľ��ĳ�����ˮ���ϸ��ż��ź�Ҷ��һ�������
С��ͨ��ǰ����Сͤ��
LONG
        );
        set("exits", ([
		"north" : __DIR__"shangyueting",
		 "east" : __DIR__"houhuayuan",
		 "west" : __DIR__"chaifang",
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
