// Room: /u/dan/room/cave/cave.c
//dan
inherit ROOM;

void create()
{
    set("short", "����");
    set("long", @LONG
ǧ��Ŷ�,�Ĵ������������.�ı��Ѿ��߲߰���,��ϡ�ɼ���
Щ�Ѻ���.ǽ���������Ͳʻ���һЩ�ֻ�.
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
      "south" : __DIR__"shatan1",
      "north" : __DIR__"cave1", 
      "east"  : __DIR__"sleeproom",   
      "west"  : __DIR__"fanting",
    ]));
    
    set("no_clean_up", 0);

    setup();
    replace_program(ROOM);
}
