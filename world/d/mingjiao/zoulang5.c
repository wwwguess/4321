
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
    ������һ�����ȡ���Χ�����ĵģ����ߵ����
���ɵ�Ҳ�����˽Ų���
LONG
        );
        set("exits", ([
		"north" : __DIR__"longdian",
		 "east" : __DIR__"zoulang6",  
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
