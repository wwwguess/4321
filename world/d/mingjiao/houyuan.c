
inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
  ������һ�����µ�С԰��԰���ﰵ�㸡��������͸��֬��������
LONG
        );
        set("exits", ([
		"east" : __DIR__"dongxiang",
		"west" : __DIR__"xixiang",
	       "south" : __DIR__"yueliangmen",
	       "north" : __DIR__"guifang",
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
