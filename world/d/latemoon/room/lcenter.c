
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "����");
	set("long", @LONG
����˺��������Ǻ�Ժ�Ϸ�����У�����һ������������ǽ            
�ڣ�������͸���ٽ��黭������ǽ�ϡ�����ɴ�֣������⣬������                  
̤��ש�����Ǳ����仨���ǵ�յ���̴��ڡ����ϰ��˶�ʮ������ľ
���Σ�ׯ�ڶ���չʾ�貽���ݣ�����������С�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "east" :__DIR__"lroad1",
     "north" :__DIR__"twoc",
     "west" :__DIR__"lroad3",
     "south" :__DIR__"lstudio",

]));

    set("objects", ([
        __DIR__"npc/spring2" : 1,
        __DIR__"npc/yushou" : 1,
    ]) );
    create_door("north","��������","south", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
