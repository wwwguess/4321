// Room: /u/sunhill/northriver.c

inherit ROOM;

void cross_river();
void no_boat();

void create()
{
        set("short", "��ˮ����");
        set("long", @LONG
�����ѿ�����������ˮ�����ż��һ��������������·�Ҫ����
���뽭���Ƶġ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : "/u/cloud/dukou",
  "south" : __DIR__"midriver",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

void init()
{
        cross_river();
}

void cross_river()
{
        if( this_object()->query("marks/����") ) {
                set("exits/south", __DIR__"sunhill/midriver");
                call_out("no_boat", 5);
        }
}

void no_boat()
{
        if( !query("exits/south") ) return;
        message("vision","С��ʻ���ϡ�\n", this_object() );
        delete("exits/south");
	this_object()->set("marks/����", 0);
}

